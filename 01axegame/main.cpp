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
  int circle_rad{25};

  // circle collision boxes
  int l_circle_x{circle_x - circle_rad};
  int r_circle_x{circle_x + circle_rad};
  int u_circle_y{circle_y - circle_rad};
  int b_circle_y{circle_y + circle_rad};

  // axe coordinates 
  int axe_x{500};
  int axe_y{200};
  int axe_rad{25};
  int direction{10};

  // circle collision boxes
  int l_axe_x{axe_x};
  int r_axe_x{axe_x + axe_rad};
  int u_axe_y{axe_y};
  int b_axe_y{axe_y + axe_rad};

//WindowShouldClose() retuns true until X is clicked 
  SetTargetFPS(60);
  while (WindowShouldClose() != true){
    BeginDrawing();
    ClearBackground(WHITE);

    //Game logic begin

    DrawCircle(circle_x, circle_y, circle_rad, BLUE);
    DrawRectangle(axe_x, axe_y, axe_rad, axe_rad, RED);

    // move axe
    axe_y += direction;
    if(axe_y > height || axe_y < 0){
      direction = -direction; //change sides
    }

    if(IsKeyDown(KEY_W) && circle_y > 0){
      circle_y -= 10;
    }
    if(IsKeyDown(KEY_A) && circle_x > 0){
      circle_x -= 10;
    }
    if(IsKeyDown(KEY_S) && circle_y < height){
      circle_y += 10;
    }
    if(IsKeyDown(KEY_D) && circle_x < width){
      circle_x += 10;
    }




    // GAME LOGIC END
    EndDrawing();
  }
}