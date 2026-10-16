#include "include/grocery/ui/dialog.hpp"
#include <iostream>
#include <string>
#include <cctype>
namespace grocery::ui
{
    void Dialog::FindItem()
    {
        while (true)
        {
            std::string itemName;
            std::cout << "Enter the name of the item to find (q to return to main menu): ";
            std::getline(std::cin >> std::ws, itemName);

            if (toupper(itemName[0]) == 'Q')
            {
                std::cout << "Returning to main menu." << std::endl;
                break;
            }
            if (itemName == "back")
            {
            }
            std::string result = dataController.FindItem(itemName);
            std::cout << result << std::endl;
        }
    }

    void Dialog::ListItemsWithQuantities()
    {
        std::string result = dataController.ListItemsWithQuantities();
        std::cout << result;
        std::cout << "Press Enter to return to the main menu...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get(); // Wait for user input before returning to the menu
    }
} // namespace grocery::ui