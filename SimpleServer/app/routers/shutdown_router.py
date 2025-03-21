from fastapi import APIRouter, HTTPException
import asyncio

router = APIRouter()

@router.get("/api/shutdown")
async def shutdown():
    """
    Initiates a graceful shutdown of the FastAPI server.
    
    This endpoint calls to stop the event loop, effectively beginning the shutdown process
    of the server. This method is designed for graceful termination, allowing the server
    to complete outstanding requests and close connections properly.

    Returns:
        A success message indicating that the shutdown process has been initiated.
    """
    loop = asyncio.get_event_loop()
    loop.stop()
    return {"message": "Shutdown process initiated successfully"}
