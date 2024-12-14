#include <raylib.h>

struct Circle {
  float radius;
  Vector2 pos;
  Color color;
};

#define WIDTH  800
#define HEIGHT 600

#define BALL_SPEED 5

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
      if(IsKeyPressed(KEY_W)) {
        ball.pos.y -= BALL_SPEED;
      }
      if(IsKeyPressed(KEY_S)) {
        ball.pos.y += BALL_SPEED;
      }
      if(IsKeyPressed(KEY_A)) {
        ball.pos.x -= BALL_SPEED;
      }
      if(IsKeyPressed(KEY_D)) {
        ball.pos.x += BALL_SPEED;
      }
    }
  }

  CloseWindow();

  return 0;
}
