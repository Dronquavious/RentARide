#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "LoginScreen.h"
#include "RentalSystem.h"
#include "GUI.h"

int main()
{
    InitWindow(1280, 720, "RentARide");

    LoginScreen loginScreen;
    RentalSystem rentalSystem;
    rentalSystem.LoadTextures();

    float userBudget = 0.0f;
    int rentalDuration = 1;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (!loginScreen.IsLoggedIn())
        {
            loginScreen.Draw();
        }
        else
        {
            GuiLabel(MakeRectangle(20, 20, 200, 20), "Welcome to RentARide");

            rentalSystem.Draw(userBudget, rentalDuration);

            const int bottomRightX = 900;
            const int bottomRightY = 500;

            DrawBudgetInput(bottomRightX, bottomRightY, userBudget);
            DrawRentalDurationInput(bottomRightX, bottomRightY + 70, rentalDuration);

            if (GuiButton(MakeRectangle(20, 600, 200, 30), "View Rented Vehicles"))
            {
                rentalSystem.ToggleRentedVehiclesView();
            }
        }

        EndDrawing();
    }

    rentalSystem.UnloadTextures();
    CloseWindow();
    return 0;
}