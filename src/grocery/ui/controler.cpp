#include "include/grocery/ui/controller.hpp"
#include <iostream>
#include <limits>

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
                         ShowMenu();
                         ProcessUserChoice();
                     });
        menu.addItem("list items and quantaties.", [this]()
                     {
                         dialog.ListItemsWithQuantities();
                         ShowMenu();
                         ProcessUserChoice(); });
        menu.addItem("print a histogram.", []()
                     { std::cout << "You selected Option 3.\n"; });
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