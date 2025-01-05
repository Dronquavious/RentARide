#pragma once
#include "raylib.h"

Rectangle MakeRectangle(float x, float y, float width, float height);
void DrawCarButton(const Rectangle& rect, const char* label);
void DrawBudgetInput(float x, float y, float& budget);
void DrawRentalDurationInput(float x, float y, int& duration);