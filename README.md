Reverse shells for Digispark Attiny85
==================

Script and paylod for Digispark USB module for establishing reverse shells on Windows and Linux machines.

To check if victim is running either Windows or Linux, use nmap to grab banner or just ping your target (Windows TTL = 128, Linux TTL = 64)

.ino sketeches to be uploaded via Arduino IDE - Digispark drivers needs to be installed prior to that

- PowerRevShell.ino - Windows Powershell reverse shell

- shell.ps1 - payload for setting up reverse shell on Windows that connects to desired C2 server

- BashRevShell.ino - Linux bash reverse shell

Scripts are executed as soon as Digispark is inserted into PC.

------------
