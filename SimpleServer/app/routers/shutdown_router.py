from fastapi import APIRouter, HTTPException
import asyncio

router = APIRouter()


@router.post("/api/shutdown")
async def shutdown(item: Item):
    loop = asyncio.get_event_loop()
    loop.stop()
