#!/bin/bash

source file1.sh

menu() 
{
    clear
    echo ""
    echo "a. System"
    echo "1. Show CPU Info"
    echo "2. Show RAM Info"
    echo "3. Show Disk Info"

    echo ""
    echo "b. Devices"
    echo "4. Change CPU Policy (Admin)"
    echo "5. Set Battery Threshold (Admin)"
    echo "6. Control PC LEDs (Admin)"

    echo ""
    echo "c. Directory Sync over network"
    echo "7. Directory Sync"

    echo ""
    echo "d. Network"
    echo "8. Show Network Info"

    echo ""
    echo "9. Reboot System (Admin)"

    echo ""
    echo "10. Shutdown System (Admin)"

    echo ""
    echo "e. Kernel Logs"
    echo "11. Show Kernel Logs"
    echo "12. Exit"
}

menu

echo ""
read -p "Enter Choice : " choice

case ${choice} in
    1) show_cpu_info ;;
    2) show_ram_info ;;
    3) show_disk_info ;;
    4) change_cpu_policy ;;
    5) set_battery_threshold ;;
    6) control_pc_leds ;;
    7) directory_sync ;;
    8) show_network_info ;;
    9) reboot_system ;;
    10) shutdown_system ;;
    11) show_kernel_logs ;;
    12) exit 0 ;;
    *) echo "Invalid option" ;;
esac