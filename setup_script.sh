#!/bin/bash

# Exit immediately if a command exits with a non-zero status.
set -e

# Update and install dependencies for both FastAPI and Qt
echo "Updating system and installing required packages..."
sudo apt update && sudo apt upgrade -y
sudo apt install python3.12-venv qt5-default qt5-qmake qtbase5-dev build-essential \
                 qml-module-qtquick-controls qtwebengine5-dev cmake \
                 qml-module-qtquick-controls2 libusb-1.0-0-dev pkg-config -y

# Setup FastAPI Server
echo "Setting up FastAPI server..."
cd simple-qt-application/SimpleServer
python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt
# Consider using & at the end if you want to run in the background or use a terminal multiplexer like tmux
uvicorn app.main:app --reload --host 0.0.0.0 --port 15555 &

# Setup Qt Application
echo "Setting up Qt application..."
cd ../QtApplication
mkdir -p build && cd build
cmake ..
make

# Optional: Run the application, comment out if running manually is preferred
echo "Starting Qt application..."
./appQtApplication &

echo "Setup complete. FastAPI server and Qt application are set up and running."
