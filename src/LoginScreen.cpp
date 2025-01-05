#include "LoginScreen.h"
#include "GUI.h"
#include "raygui.h"
#include <cstring>

LoginScreen::LoginScreen()
    : usernameEditMode(false), passwordEditMode(false), showLoginError(false), loggedIn(false)
{
    memset(username, 0, sizeof(username));
    memset(password, 0, sizeof(password));
}

bool LoginScreen::Draw()
{
    GuiLabel(MakeRectangle(20, 20, 200, 20), "Login to RentARide");

    if (GuiTextBox(MakeRectangle(20, 50, 200, 30), username, 50, usernameEditMode))
    {
        usernameEditMode = !usernameEditMode;
        passwordEditMode = false;
    }

    if (GuiTextBox(MakeRectangle(20, 100, 200, 30), password, 50, passwordEditMode))
    {
        passwordEditMode = !passwordEditMode;
        usernameEditMode = false;
    }

    // Handle text input
    if (usernameEditMode)
    {
        int key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125) && (strlen(username) < 49))
            {
                username[strlen(username)] = (char)key;
                username[strlen(username) + 1] = '\0';
            }
            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE) && strlen(username) > 0)
        {
            username[strlen(username) - 1] = '\0';
        }
    }
    else if (passwordEditMode)
    {
        int key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125) && (strlen(password) < 49))
            {
                password[strlen(password)] = (char)key;
                password[strlen(password) + 1] = '\0';
            }
            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE) && strlen(password) > 0)
        {
            password[strlen(password) - 1] = '\0';
        }
    }

    if (GuiButton(MakeRectangle(20, 150, 200, 30), "Login"))
    {
        const char *correctUsername = "admin";
        const char *correctPassword = "password123";

        if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0)
        {
            loggedIn = true;
        }
        else
        {
            memset(username, 0, sizeof(username));
            memset(password, 0, sizeof(password));
            usernameEditMode = false;
            passwordEditMode = false;
            showLoginError = true;
        }
    }

    if (showLoginError)
    {
        GuiLabel(MakeRectangle(20, 190, 200, 20), "Invalid username or password");
    }

    return loggedIn;
}

bool LoginScreen::IsLoggedIn() const
{
    return loggedIn;
}