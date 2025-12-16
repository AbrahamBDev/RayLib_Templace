#include "raylib.h"
#include "math.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Inizialicacion
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    int x = 50;
    int y = 200;
    float spd = 3.4;
    float normal;
    Vector2 direccion = {0,0};
    Vector2 posicion = {40, 80};
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------

        direccion = {0,0};

        // Ejemplo de movimiento 

        if (IsKeyDown(KEY_A)){
            direccion.x = -1;
        }else if (IsKeyDown(KEY_D)){
            direccion.x = 1;
        }
        if (IsKeyDown(KEY_W)){
            direccion.y = -1;
        } else if (IsKeyDown(KEY_S)){
            direccion.y = 1;
        } 
        /*
        Para evitar que al momento de querer movernos en y, va a ocurrir una suma de fuerzas vetoriales, una
        en x, y otra en y, {1,1}, esto hace que la velocidad sea mayor en diagonal, 
        Ejemplo:
        {1,0} = va a la derecha
        se aplica la formula de la suma de vectores tanto en x + y y se le saca raiz:
        normal = root(1^2+0^2) = 1.

        sin embargo, cuando toca la suma de dos desplazamientos:
        {1,1} 
        Se mueve tanto en x e y.
        aplicamos la formula:
        normal = root(1^2 + 1^2) = 1.41 (va mas rapido)


        por esto hay que normalizar la suma de esos vector. para eso se aplica la formula de el teorema de pitagoras:
        root(x^2 +y^2), x sera la direccion en donde va en x, y y sera la direccion en donde va en y.
        el resultado de la normal, vamos a dividirlo entre la direccion. Esto se llama, normalizacion de vector, donde solo ajustamos
        su tamaño, pero se conserva la direccion. Este proceso lo vamos a hacer tanto en x como en y, y posteriormente
        vamos a actualizar la posicion tanto en x como en y, multiplicando la velocidad por la direcion en x e y.
        teniendo en cuenta que eso se lo vamos a sumar a la posicion.

        
        if (normal > 0){
            // Esta parte del proceso, se encarga de ajustar los vectores de las direccion, tanto
            en x, como en y, con el fin de normalizarlos, manteniendo su direccion, pero ajustando su tamaño
            direccion.x /= normal; 
            direccion.y /= normal;


            // Esta parte se encarga de multiplicar la velocidad en que quieres que el personaje se mueva por la direccion
            la cual ya obtuvimos antes mediante la normalizacion. Con esto, el personaje u objeto, se moveria
            de manera uniforme y a la misma velocidad

            posicion.x += spd * direccion.x;
            posicion.y += spd * direccion.y;
        }

        */

        normal = sqrt(direccion.x * direccion.x + direccion.y * direccion.y);
        if (normal > 0){
            direccion.x /= normal;
            direccion.y /= normal;
            posicion.x += spd * direccion.x;
            posicion.y += spd * direccion.y;
        }


        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawText("BEBE, LO LOGRAMOS", posicion.x, posicion.y, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}