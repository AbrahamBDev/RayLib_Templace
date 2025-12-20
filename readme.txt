Es igual que compilar un programa en c++, sin embargo, vamos a incluir librerias necesarias para el juego, tales como el opengl, el raylib y demas.
La estructura del comando es el siguiente:

Para compilar el juego, podemos usar el siguiente comando: 


g++ src/main.cpp -o build/game.exe -Iinclude -Llib -lraylib -lopengl32 -lgdi32 -lwinmm


Esta plantilla tiene la libreria rayLib compilada manualmente, porloque no hay que descargarla.

Como recomendacion, es preferible estructurar el preyecto y organizarlo en carpetas; unas para las cabeceras (.h / hpp) otro para los procedimientos y logica
(c/cpp) y otra para guardar el archivo compilado (la carpeta build).

