#include "internal.h"
#include "include/cJSON.h"
#include "include/raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "include/raylib.h"

void CreateConfig(void) {
  // 0 = start, 1 = API, 2 = offline username, 3 autoupdater
  int stage = 0;
  cJSON *config = cJSON_CreateObject();
  // Start of Setup menu
  InitWindow(800, 600, "Atlantis Setup");
  SetTargetFPS(60);
  SetExitKey(KEY_NULL);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    if (stage == 0) {
      DrawText("Welcome to Atlantis setup!", 10, 10, 30, WHITE);
      DrawText("This setup guide will help you configure Atlantis to your liking", 10, 50, 16, WHITE);
      DrawRectangleRounded((Rectangle){250, 400, 300, 50}, 0.33, 0, DARKBLUE);
      DrawText("OK", 380, 410, 32, WHITE);
      if (CheckCollisionPointRec(GetMousePosition(),
                                 (Rectangle){250, 400, 300, 50})) {
        DrawRectangleRounded((Rectangle){250, 400, 300, 50}, 0.33, 0, BLUE);
        DrawText("OK", 380, 410, 32, LIGHTGRAY);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
	    stage ++;
        }
      }
    } else if (stage == 1) {
      char API[64] = "Type...";
      bool APITextBoxUsed = false;
      DrawText("API - Setup", 10, 10, 30, WHITE);
      DrawText("You can select none but the API key is required to log on most servers\nYou can find it on: ", 10, 50, 16, WHITE);
      DrawText("\nItch.io", 160, 50, 16, BLUE);
      if (CheckCollisionPointRec(GetMousePosition(),
                                 (Rectangle){160, 66, 56, 16})) {
        DrawText("\nItch.io", 160, 50, 16, DARKBLUE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
	  OpenURL("https://itch.io/user/settings/api-keys");
        }
      }
    }
    EndDrawing();
  }
  CloseWindow();
}
