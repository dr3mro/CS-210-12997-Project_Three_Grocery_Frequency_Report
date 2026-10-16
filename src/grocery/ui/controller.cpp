#include "include/grocery/ui/controller.hpp"
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

namespace grocery::ui
{
    void UIController::cleanScreen() const
    {
        std::cout << "\033[2J\033[1;1H"; // ANSI escape code to clear the screen and move the cursor to the top-left corner
    }
    void UIController::CreateMenu()
    {
        // Add menu items with their associated actions.
        menu.addItem("find an item.",
                     [this]()
                     {
                         dialog.FindItem();
                     });
        menu.addItem("list items and quantaties.", [this]()
                     { dialog.ListItemsWithQuantities(); });
        menu.addItem("print a histogram.", [this]()
                     { dialog.PrintHistogram(); });
        menu.addItem("exit.", []()
                     { std::cout << "Exiting the program.\n"; 
                    exit(0); });
    }

    void UIController::ShowMenu() const
    {
        cleanScreen();
        menu.ShowMenu();
    }

    void UIController::ProcessUserChoice()
    {
        std::string input;
        while (true)
        {
            std::cout << "Please select menu option (1-" << menu.GetMenuItemCount() << ", q to quit): ";
            std::getline(std::cin, input);

            if (input == "q" || input == "Q")
            {
                std::cout << "Exiting the program.\n";
                break;
            }

            std::istringstream inputStream(input);
            int choice;
            char extra;
            if (!(inputStream >> choice) || (inputStream >> extra) ||
                choice < 1 || choice > static_cast<int>(menu.GetMenuItemCount()))
            {
                std::cout << "Invalid choice. Please try again.\n";
                continue;
            }

            auto item = menu.getItem(choice - 1);
            if (item)
            {
                item->ExecuteAction();
                ShowMenu();
            }
            else
            {
                std::cerr << "Error: Menu item not found for choice " << choice << std::endl;
            }
        }
    }
} // namespace grocery::ui