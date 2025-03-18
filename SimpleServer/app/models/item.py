from pydantic import BaseModel


class Item(BaseModel):
    """
    Data model to parse and validate incoming data.

    Attributes:
        filename (str): The name of the file to be retrieved by the API.
    """
    filename: str
