#include <iostream>
#include "grocery/menu/controler.hpp"

int main()
{
    grocery::ui::MenuController menuController;
    menuController.CreateMenu();
    menuController.ShowMenu();
    menuController.ProcessUserChoice();
    return 0;
}