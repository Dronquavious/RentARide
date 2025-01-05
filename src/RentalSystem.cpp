#include "RentalSystem.h"
#include "GUI.h"
#include "raygui.h"
#include <cstdio>

RentalSystem::RentalSystem() : viewRentedVehicles(false)
{
    cars = {
        {1, "Toyota", "Corolla", 50.0f, true},
        {2, "Honda", "Civic", 60.0f, true},
        {3, "Ford", "Focus", 55.0f, true},
        {4, "Chevrolet", "Malibu", 65.0f, true},
        {5, "Nissan", "Altima", 70.0f, true},
        {6, "Hyundai", "Elantra", 45.0f, true},
        {7, "BMW", "3 Series", 75.0f, true},
        {8, "Audi", "A4", 80.0f, true},
        {9, "Mercedes-Benz", "S-Class", 120.0f, true}
    };
}

void RentalSystem::LoadTextures()
{
    const char* textureFiles[] = {
        "resources/toyota.png", "resources/civic.png", "resources/ford.png",
        "resources/chevy.png", "resources/altima.png", "resources/elantra.png",
        "resources/bmw.png", "resources/audi.png", "resources/benzi.png"
    };

    for (int i = 0; i < 9; i++)
    {
        carTextures[i] = LoadTexture(textureFiles[i]);
    }
}

void RentalSystem::UnloadTextures()
{
    for (int i = 0; i < 9; i++)
    {
        UnloadTexture(carTextures[i]);
    }
}

void RentalSystem::Draw(float userBudget, int rentalDuration)
{
    const int carsPerRow = 3;
    const int imageWidth = 200;
    const int imageHeight = 120;
    const int padding = 20;
    const int startX = 20;
    const int startY = 50;

    for (int i = 0; i < 9; i++)
    {
        int col = i % carsPerRow;
        int row = i / carsPerRow;

        int x = startX + col * (imageWidth + padding);
        int y = startY + row * (imageHeight + 2 * padding + 5);

        DrawTexture(carTextures[i], x, y, WHITE);

        float totalCost = cars[i].dailyRate * rentalDuration;

        char buttonLabel[100];
        if (userBudget >= totalCost)
        {
            snprintf(buttonLabel, sizeof(buttonLabel), "%s (%s) - $%.2f", cars[i].make, cars[i].available ? "Available" : "Rented", totalCost);
        }
        else
        {
            snprintf(buttonLabel, sizeof(buttonLabel), "%s (Too Expensive)", cars[i].make);
        }

        if (GuiButton(MakeRectangle(x, y + imageHeight + 10, imageWidth, 30), buttonLabel))
        {
            cars[i].available = !cars[i].available;
        }
    }

    if (viewRentedVehicles)
    {
        DrawRentedVehicles();
    }
}

void RentalSystem::ToggleRentedVehiclesView()
{
    viewRentedVehicles = !viewRentedVehicles;
}

void RentalSystem::DrawRentedVehicles()
{
    GuiLabel(MakeRectangle(800, 20, 200, 20), "Rented Vehicles:");

    int yPosition = 50;
    bool anyRented = false;
    for (const auto& car : cars)
    {
        if (!car.available)
        {
            char rentedCarInfo[100];
            snprintf(rentedCarInfo, sizeof(rentedCarInfo), "%d: %s %s ($%.2f/day)", car.id, car.make, car.model, car.dailyRate);
            GuiLabel(MakeRectangle(800, yPosition, 300, 20), rentedCarInfo);
            yPosition += 30;
            anyRented = true;
        }
    }

    if (!anyRented)
    {
        GuiLabel(MakeRectangle(800, 50, 300, 20), "No vehicles rented.");
    }
}