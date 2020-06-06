# Ledger BOLOS application for LTO Network
![Docker build](https://img.shields.io/docker/build/ignacioxyz/lto-ledger-devenv?style=flat-square)  ![Docker pulls](https://img.shields.io/docker/pulls/ignacioxyz/lto-ledger-devenv?style=flat-square)

Community made LTO Network wallet application for Ledger devices.

# Introduction
Ledger device wallet application for the LTO Network blockchain developed by a community member.

It is compliant with [LTO Network cryptographic specifications](https://docs.lto.network/project/developer-area/lto_protocol/cryptographic_details). 

It can be tested quickly using the python script located at [python/ledger-lto.py](https://github.com/iicc1/ledger-app-lto-network-unofficial/tree/master/python).

There is a ready to use web app interface [here](https://lto-ledger-beta.netlify.app/).

Special thanks to Ledger team, Waves community and, LTO Network team.

[User guide](https://github.com/iicc1/ledger-app-lto/wiki/How-to-use-a-Ledger-device-with-LTO-Network)


# Building

To build this application you need to create a Ledger development environment. More information can be 
found [here](https://ledger.readthedocs.io/en/latest/userspace/getting_started.html).

Alternatively, you can use my Docker image to compile the App with just one command.


## Prerequisites

First, you must have Docker and Python 2 or 3 installed.
- Docker installation instructions: https://docs.docker.com/engine/install/
- Python installation instructions: https://www.python.org/downloads/

Docker is used to compile the App from source and Python to load it into your device.

Next, download or clone this repository into a folder. If you have downloaded it, remember to extract it.


## Compiling

Open a terminal inside the folder where the repository was downloaded and enter the following command:

_Linux/Mac/Windows (PowerShell)_
```
docker run -v ${PWD}:/code ignacioxyz/lto-ledger-devenv 'make'
```
_Windows (CMD)_
```
docker run -v %cd%:/code ignacioxyz/lto-ledger-devenv 'make'
```
This command will download my Docker image from DockerHub and build the Ledger App, creating several folders within the current folder.


## Uploading

Now we will use Python to upload the App to your device.

You need to have `ledgerblue` depencency installed:

_Python_
```
pip install ledgerblue
```
_Python3_
```
pip3 install ledgerblue
```

And finally, load the App:

_Python_
```
python -m ledgerblue.loadApp --appFlags 0x240 --path "44'/353'" --curve secp256k1 --curve ed25519 --tlv --targetId 0x31100004 --delete --fileName bin/app.hex --appName "LTO Network" --appVersion 1.0.0 --dataSize 64 --icon 010000000000ffffffffffffffffffffffbffd7ffedffbb7ed67e6cff39ff97ffe7ffeffffffffffff
```
_Python3_
```
python3 -m ledgerblue.loadApp --appFlags 0x240 --path "44'/353'" --curve secp256k1 --curve ed25519 --tlv --targetId 0x31100004 --delete --fileName bin/app.hex --appName "LTO Network" --appVersion 1.0.0 --dataSize 64 --icon 010000000000ffffffffffffffffffffffbffd7ffedffbb7ed67e6cff39ff97ffe7ffeffffffffffff
```
After this, the installation process will start, asking for your permission on the Ledger screen.

# Run CLI app

Once the Ledger app is loaded, you can try to communicate with it using the CLI app.
You can download the precompiled binaries from the [releases tag](https://github.com/iicc1/ledger-app-lto/releases). Make sure you download the correct executable for your platform.
Then execute the program and the app will guide you through the process.

You can also run the CLI app from source, it is just a Python script located at the python/ folder. 
Python 2.7 is required for this, the latest releases are found here [here](https://www.python.org/downloads/release/python-2716/).

Install dependencies:
```bash
pip install ledgerblue
pip install colorama
pip install base58
```

Then enter the LTO Network app on your ledger and start the script:
```bash
python python/ledger-lto.py
```


# Web app

There is also a Vuejs web app project located here: https://github.com/iicc1/lto-ledger-vue