#include "include/grocery/menu/controler.hpp"
#include <iostream>
#include <limits>

namespace grocery::ui
{
    void MenuController::CreateMenu()
    {
        // Add menu items with their associated actions.
        menu.addItem("find an item.", []()
                     { std::cout << "You selected Option 1.\n"; });
        menu.addItem("list items and quantaties.", []()
                     { std::cout << "You selected Option 2.\n"; });
        menu.addItem("print a histogram.", []()
                     { std::cout << "You selected Option 3.\n"; });
        menu.addItem("exit.", []()
                     { std::cout << "Exiting the program.\n"; });
    }

    void MenuController::ShowMenu() const
    {
        menu.ShowMenu();
    }

    void MenuController::ProcessUserChoice()
    {
        int choice;
        while (true)
        {
            std::cout << "Please select menu option (1-" << menu.GetMenuItemCount() << "): ";
            std::cin >> choice;

            if (std::cin.fail() || choice < 1 || choice > static_cast<int>(menu.GetMenuItemCount()))
            {
                std::cin.clear();                                                   // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                std::cout << "Invalid choice. Please try again.\n";
                continue;
            }
            // Get the selected item and execute its action.
            auto item = menu.getItem(choice - 1);
            if (item)
            {
                item->ExecuteAction();
            }
            else
            {
                std::cerr << "Error: Menu item not found for choice " << choice << std::endl;
            }

            if (choice == static_cast<int>(menu.GetMenuItemCount()))
            {
                break;
            }
        }
    }
} // namespace grocery::ui