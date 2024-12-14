#include <iostream>
#include <raylib.h>

int main (int argc, char** argv)
{
  Color green = {47, 109, 189, 255};

  InitWindow(800, 600, "PPGame");
  SetTargetFPS(60);

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(green);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
