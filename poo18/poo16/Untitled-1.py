from fastapi import FastAPI, HTTPException
from pymongo import MongoClient
from pydantic import BaseModel
from motor.motor_asyncio import AsyncIOMotorClient

# Configurar conexión a MongoDB
MONGODB_URL = "mongodb://localhost:27017"
client = AsyncIOMotorClient(MONGODB_URL)
db = client["poo16"]
usuarios_collection = db["Dbase"]

# Definir modelo para solicitudes de inicio de sesión
class UsuarioLogin(BaseModel):
    usuario: str
    clave: str

# Crear instancia de la aplicación FastAPI
app = FastAPI()

# Definir ruta para validar usuarios
@app.post("/validar_usuario/")
async def validar_usuario(usuario: UsuarioLogin):
    # Buscar el usuario en la base de datos
    usuario_encontrado = await usuarios_collection.find_one({
        "usuario": usuario.usuario,
        "clave": usuario.clave
    })

    # Si el usuario no se encuentra, lanzar una excepción HTTP 404
    if usuario_encontrado is None:
        return "denegado"

    # Si se encuentra el usuario, devolver nombre y apellido en el formato especificado
    nombre_apellido = usuario_encontrado["nombre"] + " " + usuario_encontrado["apellido"]
    return nombre_apellido

# Ejecutar la aplicación
if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=8000)

    # La página de FastAPI es: http://localhost:8000/docs

    # Luego se puede consultar en la misma págiuna de FastAPI un usuario a través de la API con  http://localhost:8000/validar_usuario
