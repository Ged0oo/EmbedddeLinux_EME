#include "wifi.hpp"

std::map<std::string, std::string> savedNetworks;

void initializeDatabase() {
    const char* listCmd = "sudo ls /etc/NetworkManager/system-connections/";
    std::array<char, 128> buffer;
    std::string result;

    FILE* pipe = popen(listCmd, "r");
    if (!pipe) {
        std::cerr << "Error opening pipe." << std::endl;
        return;
    }

    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result = buffer.data();
        result.erase(result.find_last_not_of("\n\r") + 1);

        std::string filePath = "/etc/NetworkManager/system-connections/" + result;
        std::ifstream file(filePath);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filePath << std::endl;
            continue;
        }

        std::string line, ssid, password;
        while (std::getline(file, line)) {
            if (line.find("ssid=") == 0) {
                ssid = line.substr(5);
            } else if (line.find("psk=") == 0) {
                password = line.substr(4);
            }
        }

        if (!ssid.empty() && !password.empty())
            savedNetworks[ssid] = password;
    }

    pclose(pipe);
}

void addNetwork_DB(const std::string& ssid, const std::string& pass) {
    savedNetworks[ssid] = pass;
    std::cout << "Network with SSID: " << ssid << " has been added" << std::endl;
       
}

void retrievNetwork_DB(const std::string& ssid) {
    auto it = savedNetworks.find(ssid);
    if (it != savedNetworks.end()) {
        std::cout << "Network with SSID: " << ssid << " and PASS: " << it->second << " has been found" << std::endl;
    } else {
        std::cout << "Network with SSID: " << ssid << " not found" << std::endl;
    }
       
}

void listAllNetworks_DB() {
    if (savedNetworks.empty()) {
        std::cout << "No Saved Networks." << std::endl;
    } else {
        for (const auto& pair : savedNetworks) {
            std::cout << "SSID: " << pair.first << ", Password: " << pair.second << std::endl;
        }
    }
       
}

void displayAllNetworks() {
    int ret = system("nmcli -f SSID,SIGNAL,RATE,SECURITY dev wifi list");
    if (ret) {
        std::cout << "<Failed> : Display All Networks" << std::endl;
    }
       
}

void enableWifiConnectivity() {
    int ret = system("nmcli radio wifi on");
    if (ret) {
        std::cout << "<Failed> : Enable WiFi Connectivity" << std::endl;
    }
       
}

void disableWifiConnectivity() {
    int ret = system("nmcli radio wifi off");
    if (ret) {
        std::cout << "<Failed> : Disable WiFi Connectivity" << std::endl;
    }
       
}

void getWifiStatus() {
    int ret = system("nmcli radio wifi");
    if (ret) {
        std::cout << "<Failed> : Get WiFi Status" << std::endl;
    }
       
}

void showActiveAvailableNetworks() {
    int ret = system("nmcli connection show --active");
    if (ret) {
        std::cout << "<Failed> : Show Available and Active Networks" << std::endl;
    }
       
}

void connctSavedNetwork(const std::string& ssid) {
    int ret = system(("nmcli connection up \"" + ssid + "\"").c_str());
    if (ret) {
        std::cout << "<Failed> : Connect to Available and Active Network" << std::endl;
    } else {
        std::cout << "Connected to saved network: " << ssid << std::endl;
    }
       
}

void conncetNewWifiNetwork(const std::string& ssid, const std::string& pass) {
    int ret = system(("nmcli device wifi connect \"" + ssid + "\" password \"" + pass + "\"").c_str());
    if (ret) {
        std::cout << "<Failed> : Connect to New Network" << std::endl;
    } else {
        std::cout << "Connected to new network: " << ssid << std::endl;
        addNetwork_DB(ssid, pass);
    }
       
}

void deleteSavedWifiConnection(const std::string& ssid) {
    int ret = system(("nmcli connection delete \"" + ssid + "\"").c_str());
    if (ret) {
        std::cout << "<Failed> : Delete Saved Wifi Network" << std::endl;
    } else {
        savedNetworks.erase(ssid); 
        std::cout << "Deleted saved network: " << ssid << std::endl;
    }
       
}

void searchForAvailableNetwork(const std::string& ssid) {
    int ret = system(("nmcli -f SSID,RATE,SECURITY dev wifi list | grep \"" + ssid + "\"").c_str());
    if (ret) {
        std::cout << "<Failed> : Search for Available Wifi Network" << std::endl;
    }
       
}

void printWifiTitle() {
    system("clear");
    std::cout << "\n====================================================" << std::endl;
    std::cout << "\t\t WiFi Driver Manager " << std::endl;
    std::cout << "====================================================\n" << std::endl;
}
