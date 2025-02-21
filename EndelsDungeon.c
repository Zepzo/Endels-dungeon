#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int DirectionRight(Rectangle *Room, Rectangle *Coridor, Vector2 *NewDungeonPos, int i){
    Coridor[i].width = 100;
    Coridor[i].height = 20;
    
    Coridor[i].x = Room[i].x + 100;
    Coridor[i].y = Room[i].y + 50;
                
    NewDungeonPos->x = Coridor[i].x + 100;
    NewDungeonPos->y = Coridor[i].y - 50;
    
    return 0;
}

int DirectionLeft(Rectangle *Room, Rectangle *Coridor, Vector2 *NewDungeonPos, int i){
    Coridor[i].width = 100;
    Coridor[i].height = 20;
    
    Coridor[i].x = Room[i].x - 100;
    Coridor[i].y = Room[i].y + 50;
                
    NewDungeonPos->x = Coridor[i].x - 100;
    NewDungeonPos->y = Coridor[i].y - 50;
    
    return 0;
}

int DirectionUp(Rectangle *Room, Rectangle *Coridor, Vector2 *NewDungeonPos, int i){
    Coridor[i].width = 20;
    Coridor[i].height = 100;
    
    Coridor[i].x = Room[i].x + 50;
    Coridor[i].y = Room[i].y - 100;
                
    NewDungeonPos->x = Coridor[i].x - 50;
    NewDungeonPos->y = Coridor[i].y - 100;
    
    return 0;
}

int DirectionDown(Rectangle *Room, Rectangle *Coridor, Vector2 *NewDungeonPos, int i){
    Coridor[i].width = 20;
    Coridor[i].height = 100;
    
    Coridor[i].x = Room[i].x + 50;
    Coridor[i].y = Room[i].y + 100;
                
    NewDungeonPos->x = Coridor[i].x - 50;
    NewDungeonPos->y = Coridor[i].y + 100;
    
    return 0;
}

int main(void)
{
    InitWindow(900, 900, "Endless Dugneon");
    
    srand(time(0));
    
    Rectangle Room[3] = {{80, 450, 100, 100}, 
    {80, 450, 100, 100}, 
    {80, 450, 100, 100}};
    
    Rectangle Coridor[2] = {{80, 80, 100, 20}, {80, 80, 100, 20}};
    
    Vector2 NewDungeonPos;
    
    int StopGoingBack = 5;// keeps track of the direction to prevent a room fom being placed on another room

    while (!WindowShouldClose())
    {
        NewDungeonPos.x = 400;
        NewDungeonPos.y = 400;
        
        if(IsKeyPressed(KEY_SPACE)){
            for(int i = 0; i < 3; i++){
                Again:
                int Num = (rand() % (4));
                
                if(i == 2){
                    Room[i].x = NewDungeonPos.x;
                    Room[i].y = NewDungeonPos.y;
                }
                else if (Num == 0 && StopGoingBack != 1){
                    Room[i].x = NewDungeonPos.x;
                    Room[i].y = NewDungeonPos.y;
                    
                    DirectionRight(Room, Coridor, &NewDungeonPos, i);
                }
                else if(Num == 1 && StopGoingBack != 0){
                    Room[i].x = NewDungeonPos.x;
                    Room[i].y = NewDungeonPos.y;
                    
                    DirectionLeft(Room, Coridor, &NewDungeonPos, i);
                }
                else if(Num == 2 && StopGoingBack != 3){
                    Room[i].x = NewDungeonPos.x;
                    Room[i].y = NewDungeonPos.y;
                    
                    DirectionUp(Room, Coridor, &NewDungeonPos, i);
                }
                else if(Num == 3 && StopGoingBack != 2){
                    Room[i].x = NewDungeonPos.x;
                    Room[i].y = NewDungeonPos.y;
                    
                    DirectionDown(Room, Coridor, &NewDungeonPos, i);
                }
                else{
                    goto Again;
                }
                StopGoingBack = Num;
            }
        }
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            for(int i = 0; i < 3; i++){
                DrawRectangle(Room[i].x, Room[i].y, Room[i].width, Room[i].height, BLACK);
                
                if(i == 0){
                    DrawText("Start", Room[i].x + 10, Room[i].y + 20, 30, WHITE);
                }
                else if(i == 2){
                    DrawText("End", Room[i].x + 10, Room[i].y + 20, 30, WHITE);
                }
            }
            for(int i = 0; i < 2; i++){
                DrawRectangle(Coridor[i].x, Coridor[i].y, Coridor[i].width, Coridor[i].height, GRAY);
            }
            
        EndDrawing();
    }

    CloseWindow();

    return 0;
}