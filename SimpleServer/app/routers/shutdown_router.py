from fastapi import APIRouter, HTTPException
import asyncio

router = APIRouter()


@router.get("/api/shutdown")
async def shutdown():
    loop = asyncio.get_event_loop()
    loop.stop()
