#include <iostream>
#include <map>
#include <limits>
#include <string>
#include "wifi.hpp"
#include "bluetooth.hpp"

void printMainTitle() {
    system("clear");
    std::cout << "\n====================================================" << std::endl;
    std::cout << "\t\t Network Driver Manager " << std::endl;
    std::cout << "====================================================\n" << std::endl;
}

void contFunction() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int main() {
    int choice;

    initializeDatabase();

    while (true) {
        printMainTitle();

        std::cout << "1. \tWifi Driver Manager" << std::endl;
        std::cout << "2. \tBluetooth Driver Manager" << std::endl;
        std::cout << "3. \tAirplane Mood" << std::endl;
        std::cout << "4. \tExit" << std::endl;
        std::cout << "\nEnter Your Choice : ";

        std::cin >> choice;
        std::cin.ignore();  

        switch (choice) {
            case 1:
                while (true) {
                    printWifiTitle();

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
                            printWifiTitle();
                            std::cout << "\nDisplaying all WiFi Networks..." << std::endl;
                            displayAllNetworks();
                            contFunction();
                            break;
                        
                        case 2:
                            printWifiTitle();
                            std::cout << "\nEnabling WiFi Connectivity..." << std::endl;
                            enableWifiConnectivity();
                            contFunction();
                            break;
                        
                        case 3:
                            printWifiTitle();
                            std::cout << "\nDisabling WiFi Connectivity..." << std::endl;
                            disableWifiConnectivity();
                            contFunction();
                            break;
                        
                        case 4:
                            printWifiTitle();
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
                            contFunction();
                            break;
                        
                        case 5:
                            printWifiTitle();
                            std::cout << "\nDeleting Saved WiFi Network..." << std::endl;
                            {
                                std::string ssid;
                                std::cout << "Enter Saved Network Name : ";
                                std::getline(std::cin, ssid);
                                deleteSavedWifiConnection(ssid);
                            }
                            contFunction();
                            break;
            
                        case 6:
                            printWifiTitle();
                            std::cout << "\nSearching for Available WiFi Network..." << std::endl;
                            {
                                std::string ssid;
                                std::cout << "Enter Network Name : ";
                                std::getline(std::cin, ssid);
                                searchForAvailableNetwork(ssid);
                            }
                            contFunction();
                            break;
            
                        case 7:
                            printWifiTitle();
                            std::cout << "\nListing All Database Content..." << std::endl;
                            listAllNetworks_DB();
                            contFunction();
                            break;
                        
                        case 8:
                            break;
                        
                        default:
                            std::cout << "Invalid choice. Please try again." << std::endl;
                            break;
                    }

                    if (choice == 8) break; // Exit WiFi Manager
                }
                break;
            
            case 2:
                while (true) {
                    printBluetoothTitle();

                    std::cout << "1. \t Display Bluetooth Status" << std::endl;
                    std::cout << "2. \t Turn on Bluetooth" << std::endl;
                    std::cout << "3. \t Turn off Bluetooth" << std::endl;
                    std::cout << "4. \t Scan Bluetooth Area" << std::endl;
                    std::cout << "5. \t Pair to Bluetooth Device" << std::endl;
                    std::cout << "6. \t Unpair to Bluetooth Device" << std::endl;
                    std::cout << "7. \t Connect to Bluetooth Device" << std::endl;
                    std::cout << "8. \t Disconnect to Bluetooth Device" << std::endl;
                    std::cout << "9. \t Exit" << std::endl;
                    std::cout << "\nEnter Your Choice : ";

                    std::cin >> choice;
                    std::cin.ignore();  

                    switch (choice) {
                        case 1:
                            printBluetoothTitle();
                            std::cout << "\nGetting Your Bluetooth Driver Status ..." << std::endl;
                            bluetoothShowStatus();
                            contFunction();
                            break;

                        case 2:
                            printBluetoothTitle();
                            std::cout << "\nTurning Your Bluetooth Driver on ..." << std::endl;
                            bluetoothPowerOn();
                            contFunction();
                            break;

                        case 3:
                            printBluetoothTitle();
                            std::cout << "\nTurning Your Bluetooth Driver off ..." << std::endl;
                            bluetoothPowerOff();
                            contFunction();
                            break;

                        case 4:
                            printBluetoothTitle();
                            {
                                std::cout << "\nScanning Your Area for Available Bluetooth Devices ..." << std::endl;
                                std::map<int, std::string> mac = bluetoothScan(BLUETOOTH_SCAN_AVAILABLE_DEVICES);
                                contFunction();
                            }
                            break;

                        case 5:
                            printBluetoothTitle();
                            {
                                std::cout << "\nPairing with Bluetooth Device ..." << std::endl;
                                std::map<int, std::string> mac = bluetoothScan(BLUETOOTH_SCAN_AVAILABLE_DEVICES);

                                std::cout << "\nEnter Device Index to Pair with : ";

                                int index = -1;
                                std::cin >> index;
                                std::cin.ignore();

                                if (bluetoothPairDevice(mac[index])) {
                                    std::cout << "Paired with : " << mac[index] << " Successfully" << std::endl;
                                }
                                contFunction();
                            }
                            break;

                        case 6:
                            printBluetoothTitle();
                            {
                                std::cout << "\nUnpairing with Bluetooth Device ..." << std::endl;
                                std::map<int, std::string> mac = bluetoothScan(BLUETOOTH_SCAN_PAIRED_DEVICES);

                                std::cout << "\nEnter Device Index to Unpair : ";

                                int index = -1;
                                std::cin >> index;
                                std::cin.ignore();

                                if (bluetoothUnPairDevice(mac[index])) {
                                    std::cout << "Unpaired with : " << mac[index] << " Successfully" << std::endl;
                                }
                                contFunction();
                            }
                            break;

                        case 7:
                            printBluetoothTitle();
                            {
                                std::cout << "\nConnecting to Bluetooth Device ..." << std::endl;
                                std::map<int, std::string> mac = bluetoothScan(BLUETOOTH_SCAN_PAIRED_DEVICES);

                                std::cout << "\nEnter Device Index to Connect to : ";

                                int index = -1;
                                std::cin >> index;
                                std::cin.ignore();

                                if (bluetoothConnectDevice(mac[index])) {
                                    std::cout << "Connected to : " << mac[index] << " Successfully" << std::endl;
                                }
                                contFunction();
                            }
                            break;

                        case 8:
                            printBluetoothTitle();
                            {
                                std::cout << "\nDisconnecting with Bluetooth Device ..." << std::endl;
                                std::map<int, std::string> mac = bluetoothScan(BLUETOOTH_SCAN_CONNECTED_DEVICES);

                                std::cout << "\nEnter Device Index to Disconnect from : ";

                                int index = -1;
                                std::cin >> index;
                                std::cin.ignore();

                                if (bluetoothDisconnectDevice(mac[index])) {
                                    std::cout << "Disconnected from : " << mac[index] << " Successfully" << std::endl;
                                }
                                contFunction();
                            }
                            break;

                        case 9:
                            break;

                        default:
                            std::cout << "Invalid choice. Please try again." << std::endl;
                            break;
                    }

                    if (choice == 9) break; // Exit Bluetooth Manager
                }
                break;

            case 3:
                while (true) {
                    system("clear");
                    std::cout << "1. \tAirplane Mood On" << std::endl;
                    std::cout << "2. \tAirplane Mood Off" << std::endl;
                    std::cout << "3. \tExit" << std::endl;
                    std::cout << "\nEnter Your Choice : ";

                    std::cin >> choice;
                    std::cin.ignore();  

                    switch (choice) {
                        case 1:
                            {
                                system("clear");
                                std::cout << "Airplane Mood Turning on ..." << std::endl;
                                int ret = system("nmcli radio all off");
                                if (ret) {
                                    std::cout << "<Failed> : Airplane Mood" << std::endl;
                                }
                                contFunction();
                                break;
                            }

                        case 2:
                            {
                                system("clear");
                                std::cout << "Airplane Mood Turning off ..." << std::endl;
                                int ret = system("nmcli radio all on");
                                if (ret) {
                                    std::cout << "<Failed> : Airplane Mood" << std::endl;
                                }
                                contFunction();
                                break;
                            }

                        case 3:
                            break;

                        default:
                            std::cout << "Invalid choice. Please try again." << std::endl;
                            break;
                    }

                    if (choice == 3) break; // Exit Airplane Mood Manager
                }
                break;

            case 4:
                return 0;
            
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }    
}
