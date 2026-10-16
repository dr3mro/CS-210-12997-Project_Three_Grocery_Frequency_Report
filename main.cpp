/**
 * @file main.cpp
 * @brief Program entry point for the Grocery frequency application.
 */

#include <iostream>
#include "include/grocery/app/controller.hpp"

/** @brief Starts the Grocery frequency-report application. */
int main()
{
    // The application controller owns the startup and interactive workflow.
    grocery::app::AppController appController;
    appController.Run();
    return 0;
}