# BCD 3000 Midi Mapping/Midi hotkey

## How it works

The application uses the alsa api to read and write midi messages, and also has the hability to assign commands to each individual button/knob

## How to configure the commands

Just edit the config.h file

## How to install

The default installation path is /usr/local/bin, but that can be changed in the makefile file, to install just type

```sh
# sudo make install
