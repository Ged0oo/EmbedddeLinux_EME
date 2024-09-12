#ifndef __BLUETOOTH_H__
#define __BLUETOOTH_H__

#include <algorithm>
#include <iostream>
#include <cstdio>  
#include <map>
#include <memory>
#include <sstream>
#include <array>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include <stdexcept>
#include <cstddef>
#include <cstdlib>

constexpr uint8_t BLUETOOTH_STATUS = 0;
constexpr uint8_t BLUETOOTH_ON = 1;
constexpr uint8_t BLUETOOTH_OFF = 2;
constexpr uint8_t BLUETOOTH_PAIR = 3;
constexpr uint8_t BLUETOOTH_REMOVE = 4;
constexpr uint8_t BLUETOOTH_CONNECT = 5;
constexpr uint8_t BLUETOOTH_DISCONNECT = 6;
constexpr uint8_t BLUETOOTH_SCAN_AVAILABLE_DEVICES = 7;
constexpr uint8_t BLUETOOTH_SCAN_CONNECTED_DEVICES = 8;
constexpr uint8_t BLUETOOTH_SCAN_PAIRED_DEVICES = 9;

std::string executeCMD(const char* cmd);
extern std::map<uint8_t, std::string> CmdList;

std::string bluetoothGetStatus();
void bluetoothShowStatus();
bool bluetoothTurnedOn();
bool bluetoothTurnedOff();
void bluetoothPowerOn();
void bluetoothPowerOff();
std::map<int, std::string> bluetoothScan(uint8_t cmd);
bool bluetoothPairDevice(std::string mac);
bool bluetoothUnPairDevice(std::string mac);
bool bluetoothConnectDevice(std::string mac);
bool bluetoothDisconnectDevice(std::string mac);
void printBluetoothTitle();

#endif // !__BLUETOOTH_H__