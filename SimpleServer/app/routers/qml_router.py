from fastapi import APIRouter, HTTPException
from ..models.item import Item
import random

router = APIRouter()


@router.post("/api/v1/getQML")
async def read_qml(item: Item):
    """
    Endpoint to handle POST requests for retrieving QML files.

    Args:
        item (Item): The item containing the filename of the QML file to retrieve.

    Returns:
        dict: A dictionary containing the content of the QML file.

    Raises:
        HTTPException: 404 error if the specified file is not found.
    """
    try:
        with open(item.filename, 'r') as file:
            content = file.read()
        return {"content": content}
    except FileNotFoundError:
        raise HTTPException(status_code=404, detail="File not found")
