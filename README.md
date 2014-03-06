#NCBlackhole

It's an easy way to stop AppStore.app from harassing you to update your mac.

### Useage

Run install.sh with sudo or add your user to procmod and set setgid. On success 
"NCBlackhole loaded" is outputted to the console.

## About

I wanted to implement a clean way to disable the AppStore update popups. There
is no system preference for AppStore notifications and I don't need a nanny
harassing me to run updates.

NCBlackhole disables these popups by overriding the default functionality of
NotificationCenter.app (the NotificationCenter UI). NCBlackhole installs a
helper tool as a launch daemon that injects a patch into the NotificationCenter
process.

## Feedback

If you have any ideas I'd love to hear.

