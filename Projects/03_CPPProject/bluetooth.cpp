#include "bluetooth.hpp"

std::map<uint8_t, std::string> CmdList {
    {BLUETOOTH_STATUS, "bluetoothctl show"},
    {BLUETOOTH_ON, "bluetoothctl power on"},
    {BLUETOOTH_OFF, "bluetoothctl power off"},
    {BLUETOOTH_PAIR, "bluetoothctl pair"},
    {BLUETOOTH_REMOVE, "bluetoothctl remove"},
    {BLUETOOTH_CONNECT, "bluetoothctl connect"},
    {BLUETOOTH_DISCONNECT, "bluetoothctl disconnect"},
    {BLUETOOTH_SCAN_AVAILABLE_DEVICES, "bluetoothctl --timeout 10 scan on"},
    {BLUETOOTH_SCAN_CONNECTED_DEVICES, "bluetoothctl info"},
    {BLUETOOTH_SCAN_PAIRED_DEVICES, "bluetoothctl paired-devices"},
};

std::string execCMD(const char* cmd) {
    std::array<char, 128> buffer;
    std::string ret;

    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        if (std::string(buffer.data()).find("Error") != std::string::npos) {
            return "Error";
        }
        ret += buffer.data();
    }

    return ret;
}

std::string bluetoothGetStatus() {
    std::string ret = execCMD(CmdList[BLUETOOTH_STATUS].c_str());
    if(ret.find("Powered: yes") != std::string::npos) 
        ret = "Enabled";
    else if(ret.find("Powered: no") != std::string::npos) 
        ret = "Disabled";
    return ret;
}

void bluetoothShowStatus() {
    std::string ret = bluetoothGetStatus();
    
    if(ret.find("Powered: yes") != std::string::npos) 
        ret = "Enabled";
    else if(ret.find("Powered: no") != std::string::npos) 
        ret = "Disabled";
    
    std::cout << "\nYour Bluetooth Driver : "<< ret << std::endl << std::endl;
}

void bluetoothPowerOn() {
    std::string ret = bluetoothGetStatus();
    if(ret == "Disabled") {
        while(1) {
            ret = execCMD(CmdList[BLUETOOTH_ON].c_str());
            if(ret.find("succeeded") != std::string::npos)
                return;
        }        
    }
    else {
        std::cout << "\nYour Bluetooth Driver Already Enabled" << std::endl;
        return;
    }
    
    std::cout << "\nNow Your Bluetooth Driver : Enabled" << std::endl;
}

void bluetoothPowerOff() {
    std::string ret = bluetoothGetStatus();
    if(ret == "Enabled") {
        while(1) {
            ret = execCMD(CmdList[BLUETOOTH_OFF].c_str());
            if(ret.find("succeeded") != std::string::npos)
                return;
        }        
    }
    else {
        std::cout << "\nYour Bluetooth Driver Already Disabled" << std::endl;
        return;
    }

    std::cout << "\nNow Your Bluetooth Driver : Disabled" << std::endl;
}

std::map<int, std::string> bluetoothScan(uint8_t cmd) {
    std::map<int, std::string> devices;
    std::string ret = execCMD(CmdList[cmd].c_str());

    std::istringstream iss(ret);
    std::string line;
    int index = 1;

    while (std::getline(iss, line)) {
        if (line.find("Device") != std::string::npos) {
            // Extract MAC address
            std::size_t start = line.find("Device") + 7;
            std::size_t end = line.find(' ', start);
            std::string deviceMAC = line.substr(start, end - start);

            // Extract device name
            std::size_t nameStart = line.find(deviceMAC) + deviceMAC.length() + 1;
            std::string deviceName = line.substr(nameStart);

            // Print the information
            std::cout << "Index: " << index << " - MAC: " << deviceMAC << " - Name: " << deviceName << std::endl;

            // Store index and MAC in the map
            devices[index++] = deviceMAC;
        }
    }

    return devices;
}
bool bluetoothPairDevice(std::string mac) {
    std::string cmd = CmdList[BLUETOOTH_PAIR] + " " + mac;
    std::string ret = execCMD(cmd.c_str());
    bool flage = false;

    while(ret.find("Attempting") != std::string::npos) {
        if(ret.find("Pairing successful") != std::string::npos) { 
            flage = true;
            break;
        }
    }

    return flage;
}

bool bluetoothUnPairDevice(std::string mac) {
    std::string cmd = CmdList[BLUETOOTH_REMOVE] + " " + mac;
    std::string ret = execCMD(cmd.c_str());
    bool flage = false;

    if(ret.find("removed") != std::string::npos) { 
        flage = true;
    }
    else if(ret.find("not available") != std::string::npos) { 
        flage = false;
    }
    
    return flage;
}

bool bluetoothConnectDevice(std::string mac) {
    std::string cmd = CmdList[BLUETOOTH_CONNECT] + " " + mac;
    std::string ret = execCMD(cmd.c_str());
    bool flage = false;

    while(ret.find("Attempting") != std::string::npos) {
        if(ret.find("Connection successful") != std::string::npos) { 
            flage = true;
            break;
        }
    }

    return flage;
}

bool bluetoothDisconnectDevice(std::string mac) {
    std::string cmd = CmdList[BLUETOOTH_DISCONNECT] + " " + mac;
    std::string ret = execCMD(cmd.c_str());
    bool flage = false;

    while(ret.find("Attempting") != std::string::npos) {
        if(ret.find("Successful disconnected") != std::string::npos) { 
            flage = true;
            break;
        }
    }

    return flage;
}

void printBluetoothTitle() {
    system("clear");
    std::cout << "\n====================================================" << std::endl;
    std::cout << "\t\t Bluetooth Driver Manager " << std::endl;
    std::cout << "====================================================\n" << std::endl;
}