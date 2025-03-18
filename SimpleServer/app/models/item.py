from pydantic import BaseModel


class Item(BaseModel):
    filename: str
