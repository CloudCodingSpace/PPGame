#include <raylib.h>

struct Circle {
  float radius;
  Vector2 pos;
  Color color;
};

#define WIDTH  800
#define HEIGHT 600

#define ball_speed 5

int main(int argc, char** argv) {
  InitWindow(WIDTH, HEIGHT, "PPGame");

  Color green = {47, 109, 189, 255};
  Circle ball{};
  ball.radius = 30;
  ball.pos = (Vector2) { (int)(WIDTH/2), (int)(HEIGHT/2) };
  ball.color = {255, 0, 0, 255};

  SetTargetFPS(60);
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(green);
    
    // Rendering stuff
    {
      DrawCircle(ball.pos.x, ball.pos.y, ball.radius, ball.color);
    } 

    EndDrawing();

    // Update
    {
      if(IsKeyPressedRepeat(KEY_W))
    {
      ball.pos.y -= ball_speed * 2.0;
      if(ball.pos.y < 0)
        ball.pos.y = 0.0f;
    }
    if(IsKeyPressedRepeat(KEY_S))
    {
      ball.pos.y += ball_speed * 2.0;
      if(ball.pos.y > HEIGHT)
        ball.pos.y = (float) HEIGHT;
    }
    if(IsKeyPressedRepeat(KEY_A))
    {
      ball.pos.x -= ball_speed * 2.0;
      if(ball.pos.x < 0)
        ball.pos.x = 0.0f;
    }
    if(IsKeyPressedRepeat(KEY_D))
    {
      ball.pos.x += ball_speed * 2.0;
      if(ball.pos.y > WIDTH)
        ball.pos.y = (float) WIDTH;
    }
    }
  }

  CloseWindow();

  return 0;
}
