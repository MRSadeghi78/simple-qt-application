# Qt, QML, and FastAPI Integration

## Introduction
This project demonstrates a integration between a Qt C++ application and a FastAPI server, designed to dynamically fetch and display QML content. The system is divided into two main components: a Qt application that handles the user interface and network communication, and a FastAPI server that serves QML files upon request.

## Project Features

- **Dynamic QML Loading**: Qt application fetches QML files dynamically from a backend FastAPI server.
- **Timer**: There is a start/stop button in the QML UI that by pressing it, a timer in the QML UI starts/stops working. When running, the timer value gets updated each 1 second from the triggers it gets from the C++ code.
- **Listing USB Devices**: By pressing the "List USB Devices" button, the QML’s UI will display all currently attached USB devices including their model, vendor and location.
- **Exit**: The exit button, exits and shuts down both Qt application and the FastAPI web server. The implementation of this feature consists of sending a "shutdown" request to the web server from the Qt application and then then shutting down the Qt application by its own C++ code.
- **Cleanup**: Clicking this button C++ application exits, shuts down and deletes the webserver, and also shuts down and deletes itself. the implementation of this feature is quite similar to the exit functionality.

## System Requirements

### For the Qt Application
- Qt 5 (version 5.15 or later recommended)
- CMake (version 3.16 or higher)
- A C++ compiler (GCC or Clang recommended)
- Git (for cloning the repository)

### For the FastAPI Server
- Python 3.6 or higher
- FastAPI
- Uvicorn (for running the server)

## Installation Guide

### Setting Up the FastAPI Server

1. Install necessary packages:
   ```bash
   sudo apt update
   sudo apt install python3.12-venv
   ```

2. Clone the repository and enter project directory:
   ```bash
   git clone https://github.com/MRSadeghi78/simple-qt-application.git
   cd simple-qt-application/SimpleServer
   ```

3. Create and activate a virtual environment:
   ```bash
   python3 -m venv venv
   source venv/bin/activate
   ```

4. Install dependencies:
   ```bash
   pip install -r requirements.txt
   ```

5. Run the server:
   ```bash
   uvicorn app.main:app --reload --host 0.0.0.0 --port 15555
   ```

### Setting Up the Qt Application

1. Install Qt5 and Necessary Tools:
    ```bash
    sudo apt update
    sudo apt upgrade
    sudo apt install qt5-default qt5-qmake qtbase5-dev build-essential
    sudo apt install qml-module-qtquick-controls qtwebengine5-dev
    sudo apt install cmake
    sudo apt install qml-module-qtquick-controls2
    sudo apt-get install libusb-1.0-0-dev
    sudo apt-get install pkg-config
    ```

2. Clone the Qt project repository and enter project directory:
   ```bash
   git clone https://github.com/MRSadeghi78/simple-qt-application.git //skip this part if you have already cloned the repository in the previous steps
   cd simple-qt-application/QtApplication
   ```

3. Build the project:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

4. Run the application:
   ```bash
   ./appQtApplication
   ```

## Usage

### FastAPI Server
Access the server at http://localhost:15555. Use the following command to make a POST request:

   ```bash
   curl -X POST http://localhost:15555/api/v1/getQML -H "Content-Type: application/json" -d "{\"filename\":\"example.qml\"}"
   ```

### Qt Application
Interact with the Qt application through its GUI, which allows dynamic fetching of QML files, listing USB devices, and system cleanup functionalities.
