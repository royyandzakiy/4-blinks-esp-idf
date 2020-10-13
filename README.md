# Blink ESP-IDF

This repo is made to easily do a simple blink test on 4 DOIT ESP32 devices.

## Where to start
1. Determine whether or not you want to set NodeId
  - Set NodeId (in global.h) if not set yet, uncomment the macro SET_NODEID, and add the proper ID that you want to add (ranging 1-4)
  - If NodeId (in global.h) was already set before and you don't want to set a new NodeId, comment the macro SET_NODEID

3. build and flash

## How to build and flash:
1. `. $HOME/esp/esp-idf/export.sh` *change `$HOME/esp/esp-idf` with directory of esp-idf if different

2. `idf.py clean` *optional if you want a clean build

3. `idf.py -p /dev/ttyUSB3 build flash monitor` *change port in `idf.py -p [port] build flash monitor` to current port active if different

## Speedy way
add these lines within your ~/.bashrc to use these shortcuts

```
alias ges='. $HOME/esp/esp-idf/export.sh'
alias bes='idf.py build'
alias fes='idf.py -p /dev/ttyUSB0 flash'
alias mes='idf.py -p /dev/ttyUSB0 monitor'
alias mfes='idf.py -p /dev/ttyUSB0 flash monitor'
alias bges='ges && bes'
alias mfbges='bges && mfes'

# duplicates
alias fes1='idf.py -p /dev/ttyUSB1 flash'
alias fes2='idf.py -p /dev/ttyUSB2 flash'
alias fes3='idf.py -p /dev/ttyUSB3 flash'
alias mes1='idf.py -p /dev/ttyUSB1 monitor'
alias mes2='idf.py -p /dev/ttyUSB2 monitor'
alias mes3='idf.py -p /dev/ttyUSB3 monitor'
alias mfes1='idf.py -p /dev/ttyUSB1 flash monitor'
alias mfes2='idf.py -p /dev/ttyUSB2 flash monitor'
alias mfes3='idf.py -p /dev/ttyUSB3 flash monitor'
```

Write this in the terminal to build then flash to all 4 devices

`bges && fes && fes1 && fes2 && fes3`

note: made and tested on Ubuntu, I don't guarantee the steps will be the same on different OS's