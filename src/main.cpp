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

struct CollisionDetails {
  bool player_collision;
  bool computer_collision;
  bool line_collision;
};

#define WIDTH  800
#define HEIGHT 600

#define ball_speed 5

bool first_move = true;
bool game_resumed = false;

Rectangle ConvertBarToRectangle(Bar& bar);
CollisionDetails CheckCollision(Circle circle, Bar player_bar, Bar computer_bar);

int main(int argc, char** argv) {
  InitWindow(WIDTH, HEIGHT, "PPGame");

  Color green = {47, 109, 189, 255};
  Circle ball{};
  ball.radius = 30;
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
      if(IsKeyPressed(KEY_SPACE))
      {
        game_resumed = true;
      }
      if(game_resumed)
      {
        if(first_move)
        {
          ball.pos.x -= ball_speed * 2.0f;
          CheckCollision(ball, playerBar, computerBar);

          first_move = false;
        }
      }
    }
  }

  CloseWindow();

  return 0;
}

Rectangle ConvertBarToRectangle(Bar& bar)
{
  Rectangle rect;
  rect.x = bar.pos.x;
  rect.y = bar.pos.y;
  rect.width = bar.size.x;
  rect.height = bar.size.y;

  return rect;
}

CollisionDetails CheckCollision(Circle circle, Bar player_bar, Bar computer_bar)
{
  Rectangle playerRect = ConvertBarToRectangle(player_bar);
  Rectangle computerRect = ConvertBarToRectangle(computer_bar);
  bool collsion_with_player = CheckCollisionCircleRec(circle.pos, circle.radius, playerRect);
  bool collision_with_computer = CheckCollisionCircleRec(circle.pos, circle.radius, computerRect);

}
