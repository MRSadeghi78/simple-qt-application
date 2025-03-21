from fastapi import FastAPI
from .routers import qml_router, shutdown_router, cleanup_router

# Initialize FastAPI application
app = FastAPI()

# Register routers from the 'routers' package
# These routers handle different paths and HTTP operations related to QML handling and system management.

# QML Router: Handles requests to fetch QML files.
app.include_router(qml_router.router)

# Shutdown Router: Provides an endpoint to shut down the server.
app.include_router(shutdown_router.router)

# Cleanup Router: Provides an endpoint to clean up resources before shutting down.
app.include_router(cleanup_router.router)
