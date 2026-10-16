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

            itemName.erase(itemName.find_last_not_of(" \n\r\t") + 1);
            char response;
            if (!itemName.empty() && toupper(itemName[0]) == 'Q')
            {
                std::cout << "Returning to main menu." << std::endl;
                break;
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
        std::cin.get(); // Wait for user input before returning to the menu
    }

    void Dialog::PrintHistogram()
    {
        std::string result = dataController.GetItemsHistogram();
        std::cout << result;
        std::cout << "Press Enter to return to the main menu...";
        std::cin.get(); // Wait for user input before returning to the menu
    }
} // namespace grocery::ui