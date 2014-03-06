#!/bin/bash

# inspired by https://github.com/infinitelabs/FinderMenu/

xcodebuild clean && \
xcodebuild && \
killall NotificationCenter && \
rm -f ~/NCBlackhole.log && \
sleep 1 && \
sudo build/Release/NCBlackhole && \
sleep 1 && \
tail -f ~/NCBlackhole.log