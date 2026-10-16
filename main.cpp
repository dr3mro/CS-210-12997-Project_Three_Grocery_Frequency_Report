#include <iostream>
#include "include/grocery/app/controller.hpp"

/** @brief Starts the Grocery frequency-report application. */
int main()
{
    grocery::app::AppController appController;
    appController.Run();
    return 0;
}