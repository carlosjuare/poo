from fastapi import FastAPI, HTTPException
from pydantic import BaseModel
from motor.motor_asyncio import AsyncIOMotorClient

app = FastAPI()

# Conexión a MongoDB
MONGO_URI = "mongodb://localhost:27017"
DATABASE_NAME = "fastapi_users"
COLLECTION_NAME = "users"

client = AsyncIOMotorClient(MONGO_URI)
db = client[DATABASE_NAME]
users_collection = db[COLLECTION_NAME]

# Definir el modelo de usuario
class User(BaseModel):
    nombre_usuario: str
    apellido_usuario: str
    usuario: str
    clave_usuario: str

# Endpoint para registrar un usuario
@app.post("/register/")
async def register_user(user: User):
    user_data = {
        'nombre_usuario': user.nombre_usuario,
        'apellido_usuario': user.apellido_usuario,
        'usuario': user.usuario,
        'clave_usuario': user.clave_usuario
    }
    # Insertar el usuario en la base de datos
    await users_collection.insert_one(user_data)
    return {"message": "Usuario registrado exitosamente"}

# Endpoint para validar un usuario
@app.post("/login/")
async def login_user(username: str, password: str):
    # Buscar el usuario en la base de datos
    user = await users_collection.find_one({'usuario': username, 'clave_usuario': password})
    if user:
        return {"message": "Inicio de sesión exitoso"}
    else:
        raise HTTPException(status_code=401, detail="Credenciales incorrectas")

