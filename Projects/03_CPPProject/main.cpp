#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include <array>
#include <cstdio>

std::map<std::string, std::string> savedNetworks;

void initializeDatabase() {
    const char* cmd = "nmcli -t -f NAME,TYPE connection show | grep 802-11-wireless | cut -d: -f1";
    std::array<char, 128> buffer;
    std::string result;
    FILE* pipe = popen(cmd, "r");

    if (!pipe) {
        std::cerr << "Error opening pipe." << std::endl;
        return;
    }

    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result = buffer.data();
        result.erase(result.find_last_not_of("\n\r") + 1);
        savedNetworks[result] = ""; 
    }

    pclose(pipe);
    std::cout << "Database initialized with saved networks." << std::endl;
}

std::string getPasswordForSSID(const std::string& ssid) {
    std::string password;
    const std::string cmd = "nmcli -s -g 802-11-wireless.security.psk connection show \"" + ssid + "\"";
    std::array<char, 128> buffer;
    std::string result;
    FILE* pipe = popen(cmd.c_str(), "r");

    if (!pipe) {
        std::cerr << "Error opening pipe to get password." << std::endl;
        return "";
    }

    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result += buffer.data();
    }
    pclose(pipe);

    result.erase(result.find_last_not_of("\n\r") + 1);
    return result;
}

void addNetwork_DB(const std::string& ssid, const std::string& pass) {
    savedNetworks[ssid] = pass;
    std::cout << "Network with SSID: " << ssid << " has been added" << std::endl;
}

void retrievNetwork_DB(const std::string& ssid) {
    auto it = savedNetworks.find(ssid);
    if (it != savedNetworks.end()) {
        std::cout << "Network with SSID: " << ssid << " has been found" << std::endl;
    } else {
        std::cout << "Network with SSID: " << ssid << " not found" << std::endl;
    }
}

void listAllNetworks_DB() {
    if (savedNetworks.empty()) {
        std::cout << "No Saved Networks." << std::endl;
    } else {
        for (const auto& pair : savedNetworks) {
            std::cout << "SSID: " << pair.first << std::endl;
        }
    }
    std::cin.get();  
}

void displayAllNetworks() {
    int ret = system("nmcli -f SSID,SIGNAL,RATE,SECURITY dev wifi list");
    if (ret) {
        std::cout << "<Failed> : Display All Networks" << std::endl;
    }
    std::cin.get();  
}

void enableWifiConnectivity() {
    int ret = system("nmcli radio wifi on");
    if (ret) {
        std::cout << "<Failed> : Enable WiFi Connectivity" << std::endl;
    }
    std::cin.get();  
}

void disableWifiConnectivity() {
    int ret = system("nmcli radio wifi off");
    if (ret) {
        std::cout << "<Failed> : Disable WiFi Connectivity" << std::endl;
    }
    std::cin.get();  
}

void getWifiStatus() {
    int ret = system("nmcli radio wifi");
    if (ret) {
        std::cout << "<Failed> : Get WiFi Status" << std::endl;
    }
    std::cin.get();  
}

void showActiveAvailableNetworks() {
    int ret = system("nmcli connection show --active");
    if (ret) {
        std::cout << "<Failed> : Show Available and Active Networks" << std::endl;
    }
    std::cin.get();  
}

void connctSavedNetwork(const std::string& ssid) {
    int ret = system(("nmcli connection up \"" + ssid + "\"").c_str());
    if (ret) {
        std::cout << "<Failed> : Connect to Available and Active Network" << std::endl;
    } else {
        std::cout << "Connected to saved network: " << ssid << std::endl;
    }
    std::cin.get();  
}

void conncetNewWifiNetwork(const std::string& ssid, const std::string& pass) {
    int ret = system(("nmcli device wifi connect \"" + ssid + "\" password \"" + pass + "\"").c_str());
    if (ret) {
        std::cout << "<Failed> : Connect to New Network" << std::endl;
    } else {
        std::cout << "Connected to new network: " << ssid << std::endl;
        addNetwork_DB(ssid, pass);
    }
    std::cin.get();  
}

void deleteSavedWifiConnection(const std::string& ssid) {
    int ret = system(("nmcli connection delete \"" + ssid + "\"").c_str());
    if (ret) {
        std::cout << "<Failed> : Delete Saved Wifi Network" << std::endl;
    } else {
        savedNetworks.erase(ssid); 
        std::cout << "Deleted saved network: " << ssid << std::endl;
    }
    std::cin.get();  
}

void searchForAvailableNetwork(const std::string& ssid) {
    int ret = system(("nmcli -f SSID,RATE,SECURITY dev wifi list | grep \"" + ssid + "\"").c_str());
    if (ret) {
        std::cout << "<Failed> : Search for Available Wifi Network" << std::endl;
    }
    std::cin.get();  
}

void printTitle() {
    system("clear");
    std::cout << "\n====================================================" << std::endl;
    std::cout << "\t\t WiFi Driver Manager " << std::endl;
    std::cout << "====================================================\n" << std::endl;
}

int main() {
    int choice;

    initializeDatabase();

    while (true) {
        printTitle();

        std::cout << "1. \tDisplay Wifi Status" << std::endl;
        std::cout << "2. \tTurn on WiFi" << std::endl;
        std::cout << "3. \tTurn off WiFi" << std::endl;
        std::cout << "4. \tConnect to WiFi Network" << std::endl;
        std::cout << "5. \tRemove Saved Network" << std::endl;
        std::cout << "6. \tSearch for Network" << std::endl;
        std::cout << "7. \tList DataBase Content" << std::endl;
        std::cout << "8. \tExit" << std::endl;
        std::cout << "\nEnter Your Choice : ";

        std::cin >> choice;
        std::cin.ignore();  

        switch (choice) {
            case 1:
                printTitle();
                std::cout << "\nDisplaying all WiFi Networks..." << std::endl;
                displayAllNetworks();
                break;
            
            case 2:
                printTitle();
                std::cout << "\nEnabling WiFi Connectivity..." << std::endl;
                enableWifiConnectivity();
                break;
            
            case 3:
                printTitle();
                std::cout << "\nDisabling WiFi Connectivity..." << std::endl;
                disableWifiConnectivity();
                break;
            
            case 4:
                printTitle();
                std::cout << "\nConnecting to WiFi Network..." << std::endl;
                std::cout << "1. \tConnect to Saved WiFi Network" << std::endl;
                std::cout << "2. \tConnect to New WiFi Network" << std::endl;
                std::cin >> choice;
                std::cin.ignore();  

                switch (choice) {
                    case 1:
                        {
                            std::string ssid;
                            std::cout << "Enter Saved Network Name : ";
                            std::getline(std::cin, ssid);
                            connctSavedNetwork(ssid);
                        }
                        break;

                    case 2:
                        {
                            std::string ssid;
                            std::string pass;
                            std::cout << "Enter New Network Name : ";
                            std::getline(std::cin, ssid);
                            std::cout << "Enter New Network Password : ";
                            std::getline(std::cin, pass);
                            conncetNewWifiNetwork(ssid, pass);
                        }
                        break;
                    
                    default:
                        std::cout << "Invalid choice." << std::endl;
                        break;
                }
                break;
            
            case 5:
                printTitle();
                std::cout << "\nDeleting Saved WiFi Network..." << std::endl;
                {
                    std::string ssid;
                    std::cout << "Enter Saved Network Name : ";
                    std::getline(std::cin, ssid);
                    deleteSavedWifiConnection(ssid);
                }
                break;

            case 6:
                printTitle();
                std::cout << "\nSearching for Available WiFi Network..." << std::endl;
                {
                    std::string ssid;
                    std::cout << "Enter Network Name : ";
                    std::getline(std::cin, ssid);
                    searchForAvailableNetwork(ssid);
                }
                break;

            case 7:
                printTitle();
                std::cout << "\nListing All Database Content..." << std::endl;
                listAllNetworks_DB();
                break;
            
            case 8:
                return 0;
            
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
}
