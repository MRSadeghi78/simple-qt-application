# QtApplication

## Overview
QtApplication is a modern C++ application utilizing the powerful Qt framework to demonstrate fetching and displaying QML content dynamically from a FastAPI server. This project showcases the integration of Qt's networking capabilities with its QML rendering system, providing a practical example of how to handle network communications and UI updates in a Qt application.

## Features
- **Dynamic QML Loading**: Fetches QML files dynamically from a backend server.
- **Network Communication**: Uses Qt's `QNetworkAccessManager` to manage HTTP requests.
- **QML Rendering**: Displays the fetched QML content using `QQmlApplicationEngine`.

## Prerequisites
Before you can run this project, ensure you have the following installed on your Linux system:
- Qt 5 (5.15 or later recommended)
- CMake (version 3.16 or higher)
- A C++ compiler (GCC or Clang)
- Git (for cloning the repository)

## Installation and Setup

### Step 1: Install Qt5 and Necessary Tools
Ensure you have Qt5 and the necessary build tools installed:
```bash
sudo apt update
sudo apt upgrade
sudo apt install qt5-default qt5-qmake qtbase5-dev build-essential
sudo apt install qml-module-qtquick-controls qtwebengine5-dev
sudo apt install cmake
sudo apt install qml-module-qtquick-controls2
```

### Step 2: Clone the Repository
Clone the repository to your local machine:

```bash
git clone https://github.com/your-username/QtApplication.git
cd QtApplication
```

### Step 3: Build the Project
Create a build directory and configure the project using CMake:

```bash
mkdir build
cd build
cmake ..
make
```

### Step 4: Run the Application
Execute the application from the build directory:

```bash
./appQtApplication
```

## Configuring the FastAPI Server
> If you are using your own server to interact with the Qt application, then skip this part.

The application expects a FastAPI server running on http://localhost:15555 serving QML files. Ensure your server is configured to respond to /api/v1/getQML with the appropriate QML content.

### Step 1: Set up FastAPI
Install FastAPI and Uvicorn, if not already installed:

```bash
pip install fastapi uvicorn
```

### Step 2: Run the Server
Navigate to your server directory and start the server:

```bash
uvicorn server:app --reload --port 15555
```

## Acknowledgements
- Qt Documentation: https://doc.qt.io
- FastAPI Documentation: https://fastapi.tiangolo.com
