#include <raylib.h>

struct Circle {
  float radius;
  Vector2 pos;
  Color color;
};

struct Bar {
  Vector2 pos;
  Vector2 size;
  Color color;
};

#define WIDTH  800
#define HEIGHT 600

static int ballVelocity = 8;
static bool isGameRunning = false;

Rectangle ConvertBarToRectangle(const Bar& bar)
{
  Rectangle rect;
  rect.x = bar.pos.x;
  rect.y = bar.pos.y;
  rect.width = bar.size.x;
  rect.height = bar.size.y;

  return rect;
}

int main(int argc, char** argv) {
  InitWindow(WIDTH, HEIGHT, "PPGame");

  Color green = {47, 109, 189, 255};
  Circle ball{};
  ball.radius = 20;
  ball.pos = (Vector2) { (int)(WIDTH/2), (int)(HEIGHT/2) };
  ball.color = { 255, 0, 0, 255 };

  Bar playerBar{};
  playerBar.pos = (Vector2) { 20, 150 };
  playerBar.size = (Vector2) { 30, 300 };
  playerBar.color = { 223, 234, 23, 255 };

  Bar computerBar{};
  computerBar.pos = (Vector2) { WIDTH - (20 + 30), 150 };
  computerBar.size = (Vector2) { 30, 300 };
  computerBar.color = { 223, 234, 23, 255 };

  SetTargetFPS(60);
  while(!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(green);
    
    // Rendering stuff
    {
      DrawCircle(ball.pos.x, ball.pos.y, ball.radius, ball.color);
      DrawRectangle(playerBar.pos.x, playerBar.pos.y, playerBar.size.x, playerBar.size.y, playerBar.color);
      DrawRectangle(computerBar.pos.x, computerBar.pos.y, computerBar.size.x, computerBar.size.y, computerBar.color);
    } 

    EndDrawing();

    // Update
    {
      // Game running state update
      if(IsKeyPressed(KEY_SPACE)) {
        isGameRunning = !isGameRunning;
      }

      // Ball pos update
      if(isGameRunning) {
        ball.pos.x -= ballVelocity;
      }
      // Collision check with the bars
      if(CheckCollisionCircleRec(ball.pos, ball.radius, ConvertBarToRectangle(computerBar))) {
        ballVelocity *= -1;
      } else if(CheckCollisionCircleRec(ball.pos, ball.radius, ConvertBarToRectangle(playerBar))) {
        ballVelocity *= -1;
      }

      // Playerbar control
      if(IsKeyDown(KEY_UP)) {
        playerBar.pos.y -= 5;
      }
      if(IsKeyDown(KEY_DOWN)) {
        playerBar.pos.y += 5;
      }
    }
  }

  CloseWindow();

  return 0;
}
