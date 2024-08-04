#!/bin/bash

LOG="./bash.log"

log()
{
    echo "$(date) : $1" >> ${LOG}
}

show_cpu_info()
{
    echo "CPU Information"
    log "Displayed CPU information"
}


show_ram_info()
{
    echo "RAM Information"
    
    totalMemory=$(cat /proc/meminfo | grep 'MemTotal' | awk '{printf $2}')
    freeMemory=$(cat /proc/meminfo | grep 'MemFree' | awk '{printf $2}')
    availableMemory=$(cat /proc/meminfo | grep 'MemAvailable' | awk '{printf $2}')

    used=$((totalMemory - availableMemory))
    usage=$(((used * 100) / totalMemory))
    
    echo "Memory Usage : ${usage}%"

    log "Displayed RAM information"
}


show_disk_info()
{
    echo "Disk Information"
    
    diskUsage=$(df --output=pcent,avail / | tail -1 | awk '{printf $1}')
    freeSpace=$(df --output=pcent,avail / | tail -1 | awk '{printf $2}')

    echo "Disk Usage : ${diskUsage}"
    echo "Free Space : ${freeSpace}"

    log "Displayed Disk information"
}


change_cpu_policy()
{
    echo "Changing CPU policy"
    # Add your commands to change CPU policy here
    log "Changed CPU policy"
}


set_battery_threshold()
{
    echo "Setting battery threshold to 60%"
    
    for bat in /sys/class/power_supply/BAT[0-9]* ; 
    do
        echo 60 | sudo tee ${bat}/charge_control_end_threshold > /dev/null
    done

    log "Set battery threshold"
}


control_pc_leds()
{
    echo "Controlling PC LEDs"
    
    while true; 
    do
        echo 1 | sudo tee /sys/class/leds/input7\:\:numlock/brightness > /dev/null
        echo 0 | sudo tee /sys/class/leds/input7::capslock/brightness > /dev/null
        echo 0 | sudo tee /sys/class/leds/input7::scrolllock/brightness > /dev/null        
        sleep 0.5

        echo 0 | sudo tee /sys/class/leds/input7\:\:numlock/brightness > /dev/null
        echo 1 | sudo tee /sys/class/leds/input7::capslock/brightness > /dev/null
        echo 0 | sudo tee /sys/class/leds/input7::scrolllock/brightness > /dev/null        
        sleep 0.5
        
        echo 0 | sudo tee /sys/class/leds/input7\:\:numlock/brightness > /dev/null
        echo 0 | sudo tee /sys/class/leds/input7::capslock/brightness > /dev/null
        echo 1 | sudo tee /sys/class/leds/input7::scrolllock/brightness > /dev/null        
        sleep 0.5
        
        echo 0 | sudo tee /sys/class/leds/input7\:\:numlock/brightness > /dev/null
        echo 1 | sudo tee /sys/class/leds/input7::capslock/brightness > /dev/null
        echo 0 | sudo tee /sys/class/leds/input7::scrolllock/brightness > /dev/null        
        sleep 0.5
        
        echo 1 | sudo tee /sys/class/leds/input7\:\:numlock/brightness > /dev/null
        echo 0 | sudo tee /sys/class/leds/input7::capslock/brightness > /dev/null
        echo 0 | sudo tee /sys/class/leds/input7::scrolllock/brightness > /dev/null        
        sleep 0.5
    done

    log "Controlled PC LEDs"
}


directory_sync()
{
    echo "Directory Sync"
    
    read -p "Enter target IP : " targetIP
    read -p "Enter target folder : " targetFolder
    read -p "Enter source folder : " sourceFolder

   # Trailing slashes
    source_folder="${sourceFolder%/}/"
    target_folder="${targetFolder%/}/"

    rsync -avz --delete "$source_folder" "$target_ip:$target_folder"
    echo "Sync completed."

    log "Synced directories"
}


show_network_info()
{
    echo "Network Information"
    
    ip=$(hostname -I | awk '{print $1}')
    dns=$(nmcli dev show | grep IP4.DNS | awk '{print $2}')

    echo "IP Adress : ${ip}"
    echo "DNS : ${dns}"

    log "Displayed network information"
}


reboot_system()
{
    echo "Rebooting system"
    log "Rebooted system"
    sudo reboot
}


shutdown_system()
{
    echo "Shutting down system"
    log "Shut down system"
    shutdown now
}


show_kernel_logs()
{
    echo "Kernel Logs"
    # Add your commands to show kernel logs here
    log "Displayed kernel logs"
}