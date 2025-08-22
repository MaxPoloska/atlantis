#include <unistd.h>
#include "include/cJSON.h"
#include "internal.h"
#include "include/raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "include/raygui.h"

int main(void) {
  // Check if config exists if not start config loop
  if (access("config.json", F_OK)) {
    write(STDOUT_FILENO, "Work in Progress :D\n", 22);
    CreateConfig();
  }

  // Start main loop
  InitWindow(800, 600, "Atlantis Launcher");
  SetTargetFPS(60);
  SetExitKey(KEY_NULL);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    DrawRectangleRounded((Rectangle){325, 300, 150, 50}, 0.5f, 0, DARKPURPLE);
    DrawText("Play", 355, 305, 40, (Color){0, 255, 255, 255});
    if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){325, 300, 150, 50})) {
      DrawRectangleRounded((Rectangle){325, 300, 150, 50}, 0.5f, 0, VIOLET);
      DrawText("Play", 355, 305, 40, (Color){0, 198, 198, 255});
      if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
	system("export COSMIC_REACH_LAUNCHER_NAME=ATLNATIS ; export COSMIC_REACH_OFFLINE_DISPLAY_NAME=Saturn ; export ITCHIO_API_KEY=lKEmrRDA66MJkP3eOuGRGxo3u4QPR7RVBrZDqzpq ; java -jar cosmic_reach.jar &");
      }
    }
    EndDrawing();
  }
}
