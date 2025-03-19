from fastapi import APIRouter, HTTPException
from ..models.item import Item
import os

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
    qml_directory = os.path.join(os.path.dirname(__file__), '../qml_files/')  # Path to the qml directory
    file_path = os.path.join(qml_directory, item.filename)  # Full file path

    if not os.path.exists(file_path):
        raise HTTPException(status_code=404, detail="File not found")

    with open(file_path, 'r') as file:
        content = file.read()
    
    return {"content": content}
