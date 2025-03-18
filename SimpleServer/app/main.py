from fastapi import FastAPI
from .routers import qml_router

app = FastAPI()

app.include_router(qml_router.router)
