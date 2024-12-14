#include <iostream>
#include <raylib.h>

int main (int argc, char** argv) {
  std::cout << "Hello World!" << std::endl;

  InitWindow(800, 600, "PPGame");

  while (!WindowShouldClose())
  {
    BeginDrawing();
      ClearBackground(RAYWHITE);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
