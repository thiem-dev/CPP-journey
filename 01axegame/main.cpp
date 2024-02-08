#include "raylib.h"
int main()
{
  // window dimensions
  int width{1000};
  int height{400};
  InitWindow(width, height, "first window");

  // circle coordinates
  int circle_x{175};
  int circle_y{100};


//WindowShouldClose() retuns true until X is clicked 
  SetTargetFPS(60);
  while (WindowShouldClose() != true){
    BeginDrawing();
    ClearBackground(WHITE);

    //Game logic begin

    DrawCircle(circle_x, circle_y, 25, BLUE);

    if(IsKeyDown(KEY_D)){
      circle_x = circle_x + 10;
    }
    if(IsKeyDown(KEY_A)){
      circle_x = circle_x - 10;
    }

    // GAME LOGIC END
    EndDrawing();
  }
}