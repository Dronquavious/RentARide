#include "GUI.h"
#include "raygui.h"
#include <cstdio>

Rectangle MakeRectangle(float x, float y, float width, float height)
{
    return (Rectangle){x, y, width, height};
}

void DrawCarButton(const Rectangle& rect, const char* label)
{
    GuiButton(rect, label);
}

void DrawBudgetInput(float x, float y, float& budget)
{
    GuiLabel(MakeRectangle(x, y, 200, 20), "Enter Your Budget:");
    GuiSliderBar(MakeRectangle(x, y + 30, 200, 30), "Budget", "", &budget, 0.0f, 1000.0f);
    
    char budgetText[50];
    snprintf(budgetText, sizeof(budgetText), "$%.2f", budget);
    GuiLabel(MakeRectangle(x + 210, y + 30, 100, 30), budgetText);
}

void DrawRentalDurationInput(float x, float y, int& duration)
{
    GuiLabel(MakeRectangle(x, y, 200, 20), "Enter Rental Duration (days):");
    float tempDuration = (float)duration;
    GuiSliderBar(MakeRectangle(x, y + 30, 200, 30), "Duration", "", &tempDuration, 1.0f, 30.0f);
    duration = (int)tempDuration;
    
    char durationText[50];
    snprintf(durationText, sizeof(durationText), "%d days", duration);
    GuiLabel(MakeRectangle(x + 210, y + 30, 100, 30), durationText);
}