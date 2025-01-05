#pragma once
#include "Car.h"
#include "raylib.h"
#include <vector>

class RentalSystem
{
public:
    RentalSystem();
    void LoadTextures();
    void UnloadTextures();
    void Draw(float userBudget, int rentalDuration);
    void ToggleRentedVehiclesView();

private:
    std::vector<Car> cars;
    Texture2D carTextures[9];
    bool viewRentedVehicles;

    void DrawRentedVehicles();
};