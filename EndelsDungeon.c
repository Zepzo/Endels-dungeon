#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    InitWindow(1000, 800, "Endless Dugneon");
    
    Rectangle Room[3] = {{80, 450, 100, 100}, 
    {80, 450, 100, 100}, 
    {80, 450, 100, 100}};
    
    Rectangle Coridor[2] = {{80, 80, 100, 20}, {80, 80, 100, 20}};
    
    Vector2 NewDungeonPos = {0, 0};

    while (!WindowShouldClose())
    {
        for(int i = 0; i < 3; i++){
            if(i == 0){
                Room[i].x = 400;
                Room[i].y = 300;
                
                Coridor[i].x = Room[i].x + 100;
                Coridor[i].y = Room[i].y + 50;
                
                NewDungeonPos.x = Coridor[i].x + 100;
                NewDungeonPos.y = Coridor[i].y - 50;
            }
            else if(i == 1){
                Room[i].x = NewDungeonPos.x;
                Room[i].y = NewDungeonPos.y;
                
                Coridor[i].x = Room[i].x + 100;
                Coridor[i].y = Room[i].y + 50;
                
                NewDungeonPos.x = Coridor[i].x + 100;
                NewDungeonPos.y = Coridor[i].y - 50;
            }
            else if(i == 2){
                Room[i].x = NewDungeonPos.x;
                Room[i].y = NewDungeonPos.y;
            }
            
        }
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            for(int i = 0; i < 3; i++){
                DrawRectangle(Room[i].x, Room[i].y, Room[i].width, Room[i].height, BLACK);
            }
            for(int i = 0; i < 2; i++){
                DrawRectangle(Coridor[i].x, Coridor[i].y, Coridor[i].width, Coridor[i].height, GRAY);
            }
            
        EndDrawing();
    }

    CloseWindow();

    return 0;
}