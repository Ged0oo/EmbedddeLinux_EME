#include "wifi.hpp"

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