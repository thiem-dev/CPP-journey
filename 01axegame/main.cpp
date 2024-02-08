#include "raylib.h"
int main()
{
  int width = 1000;
  int height = 400;
  InitWindow(width, height, "first window");

//WindowShouldClose() retuns true until X is clicked 
  while (WindowShouldClose() != true){
    BeginDrawing();
    ClearBackground(WHITE);
    EndDrawing();
  }
}