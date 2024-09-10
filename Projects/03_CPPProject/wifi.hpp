#ifndef  __WIFI_HPP__
#define  __WIFI_HPP__

#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include <array>
#include <cstdio>

void initializeDatabase();
void addNetwork_DB(const std::string& ssid, const std::string& pass);
void retrievNetwork_DB(const std::string& ssid);
void listAllNetworks_DB();
void displayAllNetworks();
void enableWifiConnectivity();
void disableWifiConnectivity();
void getWifiStatus();
void showActiveAvailableNetworks();
void connctSavedNetwork(const std::string& ssid);
void conncetNewWifiNetwork(const std::string& ssid, const std::string& pass);
void deleteSavedWifiConnection(const std::string& ssid);
void searchForAvailableNetwork(const std::string& ssid);
void printTitle();

#endif  //__WIFI_HPP__