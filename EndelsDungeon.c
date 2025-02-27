/* to do list

* make the generationmore complex
-Allow more rooms and have relevant checks for that-(done)
-look in to room ovelap or rooms having more concetions-(done)
-maby let user decide how many rooms

* make it look nice
-nice colors-(done)
-maby outline for rectangels to look like walls-(done)
-maby have a start screen, probaly not like the way it is now
-

* add player (most likely not)
-add a square that can move
-add colition
-locked doors?

* maby refactor(almost 100% sure I wont do this)
-move direction stuff to its own file, not a lot so probaly not
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

int OutOfBoundce(Vector2 *NewDungeonPos){
    if(NewDungeonPos->x > 900){
        return 1;
    }
    else if(NewDungeonPos->x < 0){
        return 1;
    }
    else if(NewDungeonPos->y > 900){
        return 1;
    }
    else if(NewDungeonPos->y < 0){
        return 1;
    }
    else{
        return 0;
    }
}

int main(void)
{
    InitWindow(900, 900, "Endless Dugneon");
    
    srand(time(0));
    
    int RoomAmount = 30;
    int CoridorAmount = RoomAmount - 1;
    
    Rectangle Room[RoomAmount];
    
    Rectangle Coridor[CoridorAmount];
    
    struct Door Doors[CoridorAmount];
    
    for(int i = 0; i < RoomAmount; i++){
        Room[i].x = 400;
        Room[i].y = 400;
        Room[i].width = 100;
        Room[i].height = 100;
    }
    
    for(int i = 0; i < CoridorAmount; i++){
        Doors[i].door1.x = 400;
        Doors[i].door1.y = 400;
        Doors[i].door1.width = 10;
        Doors[i].door1.height = 20;
        
        Doors[i].door2.x = 400;
        Doors[i].door2.y = 400;
        Doors[i].door2.width = 10;
        Doors[i].door2.height = 20;
        
        Doors[i].isLocked = false;
        
        Coridor[i].x = 400;
        Coridor[i].y = 400;
        Coridor[i].width = 100;
        Coridor[i].height = 20;
    }
    
    Vector2 NewDungeonPos;
    
    int StopGoingBack = 5; // keeps track of the direction to prevent a room fom being placed on another room
    int StopOutOfBounce = 0; // check for out of bounce
    
    bool SpaceBoutton = false;
    bool SpaceIsPressed = false;
    bool EscBoutton = false;
    
    bool exitWindow = false; // Flag to set window to exit

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
            for(int i = 0; i < RoomAmount; i++){
                
                Room[i].x = NewDungeonPos.x;
                Room[i].y = NewDungeonPos.y;
                
                Again: // Stop rooms from spwaning out of bounce
                StopOutOfBounce = 0; // rests check for out of bounce
                int Num = (rand() % (4));
                  
                if(i == RoomAmount - 1){
                    
                }
                else if (Num == 0 && StopGoingBack != 1){
                    DirectionRight(Room, Coridor, &NewDungeonPos, i, Doors);
                }
                else if(Num == 1 && StopGoingBack != 0){
                    DirectionLeft(Room, Coridor, &NewDungeonPos, i, Doors);
                }
                else if(Num == 2 && StopGoingBack != 3){
                    DirectionUp(Room, Coridor, &NewDungeonPos, i, Doors);
                }
                else if(Num == 3 && StopGoingBack != 2){
                    DirectionDown(Room, Coridor, &NewDungeonPos, i, Doors);
                }
                
                StopOutOfBounce = OutOfBoundce(&NewDungeonPos);
                
                if(StopOutOfBounce == 1){
                    goto Again; // Stop rooms from spwaning out of bounce
                }
            }
        }
        
        if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) exitWindow = true;
        
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            for(int i = 0; i < RoomAmount; i++){
                DrawRectangle(Room[i].x, Room[i].y, Room[i].width, Room[i].height, GRAY);
                DrawRectangleLinesEx(Room[i], 5.0, DARKGRAY);
                
                DrawText("Start", 410, 410, 30, WHITE);
                
                if(i == RoomAmount - 1){
                    DrawText("End", Room[i].x + 10, Room[i].y + 60, 30, WHITE);
                }
            }
            for(int i = 0; i < CoridorAmount; i++){
                DrawRectangle(Coridor[i].x, Coridor[i].y, Coridor[i].width, Coridor[i].height, GRAY);
                DrawRectangleLinesEx(Coridor[i], 5.0, DARKGRAY);
                
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