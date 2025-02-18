#include "raylib.h"

int main(void)
{
    InitWindow(1000, 600, "Endless Dugneon");
    
    Rectangle Room[3] = {{400, 200, 100, 100}, 
    {400, 200, 100, 100}, 
    {400, 200, 100, 100}};
    
    Rectangle Coridor[2] = {{600, 300, 100, 100}, {600, 300, 100, 100}};
    
    

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            for(int i = 0; i < 3; i++){
                DrawRectangle(Room[i].x, Room[i].y, Room[i].width, Room[i].height, BLACK);
            }
            for(int i = 0; i < 2; i++){
                DrawRectangle(Coridor[i].x, Coridor[i].y, Coridor[i].width, Coridor[i].height, BLACK);
            }
            
            //DrawRectangle(Room.x, Room.y, Room.width, Room.height, BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}