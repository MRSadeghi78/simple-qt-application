# FastAPI QML File Server

This project is a simple web server built with FastAPI that serves QML files upon request. Only one REST API endpoint is implemented in the server that by sending a POST request to it, containing the desired file's name, the server will return the file.
## Features

- **Retrieve QML Files**: Users can POST a request with a filename to retrieve the contents of a QML file.
- **Error Handling**: Provides basic error handling to manage file not found errors.

## Requirements

Before you can run this project, you'll need to install the following:

- Python 3.6+
- FastAPI
- Uvicorn

Refer to `requirements.txt` for the complete list of required packages.

## Installation

Follow these steps to get your development environment set up:

1. Install necessary packages:
   ```bash
   sudo apt update
   sudo apt install python3.12-venv
   ```

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/your-project-name.git
   cd your-project-name
   ```

2. Create a virtual environment:

   ```bash
   python -m venv venv
   ```
   Or
   ```bash
   python3 -m venv venv
   ```

4. Activate the virtual environment:

   - On Windows:

     ```bash
     .\venv\Scripts\activate
     ```

   - On Unix or MacOS:

     ```bash
     source venv/bin/activate
     ```

5. Install the dependencies:

   ```bash
   pip install -r requirements.txt
   ```

## Usage
Start the server with the following command:

   ```bash
   uvicorn app.main:app --reload --host 0.0.0.0 --port 15555
   ```

The API can be accessed at http://localhost:15555.

### Making a POST Request

To retrieve the content of a QML file, make a POST request to /api/v1/getQML with the filename as JSON data:

   ```bash
   curl -X POST http://localhost:15555/api/v1/getQML -H "Content-Type: application/json" -d "{\"filename\":\"example.qml\"}"
   ```

## Structure
- app/ - Contains the FastAPI application including routers and models.
  * main.py - The entry point for the application.
  * routers/ - Contains the router definitions for the API.
  * models/ - Contains Pydantic models for data validation.
