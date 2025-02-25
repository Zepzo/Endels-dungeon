/* to do list

* make the generationmore complex
-Allow more rooms and have relevant checks for that
-look in to room ovelap or rooms having more concetions
-maby let user decide how many rooms

* make it look nice
-
*/


#include "raylib.h"
#include "raymath.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct Door{
    Rectangle door1;
    Rectangle door2;
    bool isLocked;
}Door;

int DirectionRight(Rectangle *Room, Rectangle *Coridor, Vector2 *NewDungeonPos, int i, Door *Doors){
    Coridor[i].width = 100;
    Coridor[i].height = 20;
    
    Doors[i].door1.width = 10;
    Doors[i].door1.height = 20;
    
    Doors[i].door2.width = 10;
    Doors[i].door2.height = 20;
    
    Coridor[i].x = Room[i].x + 100;
    Coridor[i].y = Room[i].y + 50;
                
    NewDungeonPos->x = Coridor[i].x + 100;
    NewDungeonPos->y = Coridor[i].y - 50;
    
    Doors[i].door1.x = Coridor[i].x - 5;
    Doors[i].door1.y = Coridor[i].y;
    
    Doors[i].door2.x = Coridor[i].x + 95;
    Doors[i].door2.y = Coridor[i].y;
    return 0;
}

int DirectionLeft(Rectangle *Room, Rectangle *Coridor, Vector2 *NewDungeonPos, int i, Door *Doors){
    Coridor[i].width = 100;
    Coridor[i].height = 20;
    
    Doors[i].door1.width = 10;
    Doors[i].door1.height = 20;
    
    Doors[i].door2.width = 10;
    Doors[i].door2.height = 20;
    
    Coridor[i].x = Room[i].x - 100;
    Coridor[i].y = Room[i].y + 50;
                
    NewDungeonPos->x = Coridor[i].x - 100;
    NewDungeonPos->y = Coridor[i].y - 50;
    
    Doors[i].door1.x = Coridor[i].x -5;
    Doors[i].door1.y = Coridor[i].y;
    
    Doors[i].door2.x = Coridor[i].x + 95;
    Doors[i].door2.y = Coridor[i].y;
    return 0;
}

int DirectionUp(Rectangle *Room, Rectangle *Coridor, Vector2 *NewDungeonPos, int i, Door *Doors){
    Coridor[i].width = 20;
    Coridor[i].height = 100;
    
    Doors[i].door1.width = 20;
    Doors[i].door1.height = 10;
    
    Doors[i].door2.width = 20;
    Doors[i].door2.height = 10;
    
    Coridor[i].x = Room[i].x + 50;
    Coridor[i].y = Room[i].y - 100;
                
    NewDungeonPos->x = Coridor[i].x - 50;
    NewDungeonPos->y = Coridor[i].y - 100;
    
    Doors[i].door1.x = Coridor[i].x;
    Doors[i].door1.y = Coridor[i].y - 5;
    
    Doors[i].door2.x = Coridor[i].x;
    Doors[i].door2.y = Coridor[i].y + 95;
    return 0;
}

int DirectionDown(Rectangle *Room, Rectangle *Coridor, Vector2 *NewDungeonPos, int i, Door *Doors){
    Coridor[i].width = 20;
    Coridor[i].height = 100;
    
    Doors[i].door1.width = 20;
    Doors[i].door1.height = 10;
    
    Doors[i].door2.width = 20;
    Doors[i].door2.height = 10;
    
    Coridor[i].x = Room[i].x + 50;
    Coridor[i].y = Room[i].y + 100;
                
    NewDungeonPos->x = Coridor[i].x - 50;
    NewDungeonPos->y = Coridor[i].y + 100;
    
    Doors[i].door1.x = Coridor[i].x;
    Doors[i].door1.y = Coridor[i].y - 5;
    
    Doors[i].door2.x = Coridor[i].x;
    Doors[i].door2.y = Coridor[i].y + 95;
    return 0;
}

int main(void)
{
    InitWindow(900, 900, "Endless Dugneon");
    
    srand(time(0));
    
    Rectangle Room[3] = {{400, 400, 100, 100}, 
    {400, 400, 100, 100}, 
    {400, 400, 100, 100}};
    
    Rectangle Coridor[2] = {{400, 400, 100, 20}, {400, 400, 100, 20}};
    
    struct Door Doors[2];
    
    for(int i = 0; i < 2; i++){
        Doors[i].door1.x = 400;
        Doors[i].door1.y = 400;
        Doors[i].door1.width = 10;
        Doors[i].door1.height = 20;
        
        Doors[i].door2.x = 400;
        Doors[i].door2.y = 400;
        Doors[i].door2.width = 10;
        Doors[i].door2.height = 20;
        
        Doors[i].isLocked = false;
    }
    
    Vector2 NewDungeonPos;
    
    int StopGoingBack = 5;// keeps track of the direction to prevent a room fom being placed on another room
    
    bool SpaceBoutton = false;
    bool SpaceIsPressed = false;
    bool EscBoutton = false;
    
    bool exitWindow = false;    // Flag to set window to exit

    while (!exitWindow)
    {
        NewDungeonPos.x = 400;
        NewDungeonPos.y = 400;
        
        Vector2 mouse = GetMousePosition();
                if (CheckCollisionPointRec(mouse, (Rectangle){10, 750, 200, 50, RAYWHITE})) {
                  SpaceBoutton = true;
                  if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                      SpaceIsPressed = true;
                  }
                }
                else if (CheckCollisionPointRec(mouse, (Rectangle){10, 810, 200, 50, RAYWHITE})) {
                  EscBoutton = true;
                  if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                      exitWindow = true;
                  }
                }
                else{
                    SpaceBoutton = false;
                    EscBoutton = false;
                }
        
        if(IsKeyPressed(KEY_SPACE) || SpaceIsPressed){ // randomly generate a direction a new room spwans in
            SpaceIsPressed = false;
            for(int i = 0; i < 3; i++){
                Again:  // we want to roll back to this point if ..
                int Num = (rand() % (4)); 
                
                if(i == 2){
                    Room[i].x = NewDungeonPos.x;
                    Room[i].y = NewDungeonPos.y;
                }
                else if (Num == 0 && StopGoingBack != 1){
                    Room[i].x = NewDungeonPos.x;
                    Room[i].y = NewDungeonPos.y;
                    
                    DirectionRight(Room, Coridor, &NewDungeonPos, i, Doors);
                }
                else if(Num == 1 && StopGoingBack != 0){
                    Room[i].x = NewDungeonPos.x;
                    Room[i].y = NewDungeonPos.y;
                    
                    DirectionLeft(Room, Coridor, &NewDungeonPos, i, Doors);
                }
                else if(Num == 2 && StopGoingBack != 3){
                    Room[i].x = NewDungeonPos.x;
                    Room[i].y = NewDungeonPos.y;
                    
                    DirectionUp(Room, Coridor, &NewDungeonPos, i, Doors);
                }
                else if(Num == 3 && StopGoingBack != 2){
                    Room[i].x = NewDungeonPos.x;
                    Room[i].y = NewDungeonPos.y;
                    
                    DirectionDown(Room, Coridor, &NewDungeonPos, i, Doors);
                }
                else{
                    goto Again; // if there is overlap it runs the loop again but stays on the same i vale
                }
                StopGoingBack = Num;
            }
        }
        
        if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) exitWindow = true;
        
        
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
                
                DrawRectangle(Doors[i].door1.x, Doors[i].door1.y, Doors[i].door1.width, Doors[i].door1.height, BROWN);
                DrawRectangle(Doors[i].door2.x, Doors[i].door2.y, Doors[i].door2.width, Doors[i].door2.height, BROWN);
            }
            
            DrawText("To generate dungeon press [Space]", 10, 20, 20, BLACK);
            DrawText("To exit dungeon press [ESC]", 10, 70, 20, BLACK);
            
            DrawRectangle(10, 750, 200, 50, SpaceBoutton ? GRAY : WHITE);
            DrawRectangleLines(10, 750, 200, 50, BLACK);
            DrawText("Space", 50, 760, 30, BLACK);
            
            DrawRectangle(10, 810, 200, 50, EscBoutton ? GRAY : WHITE);
            DrawRectangleLines(10, 810, 200, 50, BLACK);
            DrawText("ESC", 50, 820, 30, BLACK);
            
        EndDrawing();
    }

    CloseWindow();

    return 0;
}