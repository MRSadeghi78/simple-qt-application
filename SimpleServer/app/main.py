from fastapi import FastAPI
from .routers import qml_router, shutdown_router

app = FastAPI()  # Create an instance of the FastAPI class.

# Include the qml_router from the routers package to handle routing.
app.include_router(qml_router.router)
app.include_router(shutdown_router.router)
