#!/bin/bash
sudo ./build.sh 

killall NotificationCenter && \
rm -f ~/NCBlackhole.log && \
sleep 1 && \
sudo ./NCBlackhole && \
sleep 1 && \
tail -f ~/NCBlackhole.log