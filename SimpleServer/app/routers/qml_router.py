from fastapi import APIRouter, HTTPException
from ..models.item import Item
import random

router = APIRouter()


@router.post("/api/v1/getQML")
async def read_qml(item: Item):
    try:
        with open(item.filename, 'r') as file:
            content = file.read()
        return {"content": content}
    except FileNotFoundError:
        raise HTTPException(status_code=404, detail="File not found")
