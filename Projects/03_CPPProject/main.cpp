#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include <memory>
#include <array>

std::map<std::string, std::string> savedNetworks;

// Function to add network details to the map
void addNetwork_DB(const std::string& ssid, const std::string& pass) {
    savedNetworks[ssid] = pass;
    std::cout << "Network with SSID: " << ssid << " has been added" << std::endl;
}

// Function to retrieve network details from the map
void retrievNetwork_DB(const std::string& ssid) {
    auto it = savedNetworks.find(ssid);
    if (it != savedNetworks.end()) {
        std::cout << "Network with SSID: " << ssid << " and PASS: " << it->second << " has been found" << std::endl;
    } else {
        std::cout << "Network with SSID: " << ssid << " not found" << std::endl;
    }
}

// Function to list all saved networks
void listAllNetworks_DB() {
    if (savedNetworks.empty()) {
        std::cout << "No Saved Networks." << std::endl;
    } else {
        for (const auto& pair : savedNetworks) {
            std::cout << "SSID: " << pair.first << ", Password: " << pair.second << std::endl;
        }
    }
}

// Function to display all available WiFi networks
void displayAllNetworks() {
    int ret = system("nmcli -f SSID,SIGNAL,RATE,SECURITY dev wifi list");
    if (ret) {
        std::cout << "<Failed> : Display All Networks" << std::endl;
    }
    std::cin.get(); // Wait for user input
}

// Function to enable WiFi connectivity
void enableWifiConnectivity() {
    int ret = system("nmcli radio wifi on");
    if (ret) {
        std::cout << "<Failed> : Enable WiFi Connectivity" << std::endl;
    }
    std::cin.get(); // Wait for user input
}

// Function to disable WiFi connectivity
void disableWifiConnectivity() {
    int ret = system("nmcli radio wifi off");
    if (ret) {
        std::cout << "<Failed> : Disable WiFi Connectivity" << std::endl;
    }
    std::cin.get(); // Wait for user input
}

// Function to get WiFi status
void getWifiStatus() {
    int ret = system("nmcli radio wifi");
    if (ret) {
        std::cout << "<Failed> : Get WiFi Status" << std::endl;
    }
    std::cin.get(); // Wait for user input
}

// Function to show active WiFi connections
void showActiveAvailableNetworks() {
    int ret = system("nmcli connection show --active");
    if (ret) {
        std::cout << "<Failed> : Show Available and Active Networks" << std::endl;
    }
    std::cin.get(); // Wait for user input
}

// Function to connect to a saved WiFi network
void connctSavedNetwork(const std::string& ssid) {
    int ret = system(("nmcli connection up \"" + ssid + "\"").c_str());
    if (ret) {
        std::cout << "<Failed> : Connect to Available and Active Network" << std::endl;
    }
    std::cin.get(); // Wait for user input
}

// Function to connect to a new WiFi network
void conncetNewWifiNetwork(const std::string& ssid, const std::string& pass) {
    int ret = system(("nmcli device wifi connect \"" + ssid + "\" password \"" + pass + "\"").c_str());
    if (ret) {
        std::cout << "<Failed> : Connect to New Network" << std::endl;
    }
    std::cin.get(); // Wait for user input
}

// Function to delete a saved WiFi connection
void deleteSavedWifiConnection(const std::string& ssid) {
    int ret = system(("nmcli connection delete \"" + ssid + "\"").c_str());
    if (ret) {
        std::cout << "<Failed> : Delete Saved Wifi Network" << std::endl;
    }
    std::cin.get(); // Wait for user input
}

// Function to search for an available WiFi network
void searchForAvailableNetwork(const std::string& ssid) {
    int ret = system(("nmcli -f SSID,RATE,SECURITY dev wifi list | grep \"" + ssid + "\"").c_str());
    if (ret) {
        std::cout << "<Failed> : Search for Available Wifi Network" << std::endl;
    }
    std::cin.get(); // Wait for user input
}

// Function to print the main menu title
void printTitle() {
    system("clear");
    std::cout << "\n====================================================" << std::endl;
    std::cout << "\t\t WiFi Driver Manager " << std::endl;
    std::cout << "====================================================\n" << std::endl;
}

int main() {
    int choice;

    while (true) {
        printTitle();

        std::cout << "1. \tDisplay Wifi Status" << std::endl;
        std::cout << "2. \tTurn on WiFi" << std::endl;
        std::cout << "3. \tTurn off WiFi" << std::endl;
        std::cout << "4. \tConnect to WiFi Network" << std::endl;
        std::cout << "5. \tRemove Saved Network" << std::endl;
        std::cout << "6. \tSearch for Network" << std::endl;
        std::cout << "7. \tExit" << std::endl;
        std::cout << "\nEnter Your Choice : ";

        std::cin >> choice;
        std::cin.ignore(); // Ignore newline left in buffer

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
                std::cout << "\nEnter Your Choice : ";
                std::cin >> choice;
                std::cin.ignore(); // Ignore newline left in buffer

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
                return 0;
            
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
}
