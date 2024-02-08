#include "raylib.h"
int main()
{
  // window dimensions
  int width{1000};
  int height{400};
  InitWindow(width, height, "first window");

  // circle coordinates
  int circle_x{0};
  int circle_y{0};
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

  // game config
  bool collision_with_axe = (b_axe_y >= u_circle_y) &&
                            (u_axe_y <= b_circle_y) &&
                            (l_axe_x <= r_circle_x) &&
                            (r_axe_x >= l_circle_x);


//WindowShouldClose() retuns true until X is clicked 
  SetTargetFPS(60);
  while (WindowShouldClose() != true){

    BeginDrawing();
    ClearBackground(WHITE);

    if(collision_with_axe){
      DrawText("Game Over!", 400, 200, 20, RED);
    } else {

      //Game logic begin
    
      // update collsion boxes
      l_circle_x = circle_x - circle_rad;
      r_circle_x = circle_x + circle_rad;
      u_circle_y = circle_y - circle_rad;
      b_circle_y = circle_y + circle_rad;
      l_axe_x = axe_x;
      r_axe_x = axe_x + axe_rad;
      u_axe_y = axe_y;
      b_axe_y = axe_y + axe_rad;

      // update collision with axe
      collision_with_axe = (b_axe_y >= u_circle_y) &&
                            (u_axe_y <= b_circle_y) &&
                            (l_axe_x <= r_circle_x) &&
                            (r_axe_x >= l_circle_x);

      // draw shapes
      DrawCircle(circle_x, circle_y, circle_rad, BLUE);
      DrawRectangle(axe_x, axe_y, axe_rad, axe_rad, RED);

      // axe movement
      axe_y += direction;
      if(axe_y > height || axe_y < 0){
        direction = -direction; //change sides
      }

      // player movement
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



    }

    // GAME LOGIC END
    EndDrawing();
  }
}