#!/bin/bash

echo "Installing NCBlackhole"

sudo ./build.sh 

sudo launchctl unload -w  /Library/LaunchDaemons/com.am.NCBlackhole-Launch.plist
sudo rm -rf /Applications/NCBlackhole/

sudo cp -r build/Release /Applications/NCBlackhole
sudo cp run.sh /Applications/NCBlackhole/
sudo cp com.am.NCBlackhole-Launch.plist /Library/LaunchDaemons/com.am.NCBlackhole-Launch.plist 

sudo touch /Library/LaunchDaemons/com.am.NCBlackhole-Launch.plist 
sudo launchctl load -w /Library/LaunchDaemons/com.am.NCBlackhole-Launch.plist

echo "Installed NCBlackhole"

