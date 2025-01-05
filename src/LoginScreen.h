#pragma once
#include "raylib.h"

class LoginScreen
{
public:
    LoginScreen();
    bool Draw();
    bool IsLoggedIn() const;

private:
    char username[50];
    char password[50];
    bool usernameEditMode;
    bool passwordEditMode;
    bool showLoginError;
    bool loggedIn;
};