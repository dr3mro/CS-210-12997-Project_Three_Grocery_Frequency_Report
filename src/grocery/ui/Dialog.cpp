#include "include/grocery/ui/dialog.hpp"
#include <iostream>
namespace grocery::ui
{
    void Dialog::FindItem()
    {
        std::string itemName;
        std::cout << "Enter the name of the item to find: ";
        std::getline(std::cin >> std::ws, itemName);

        std::string result = dataController.FindItem(itemName);
        std::cout << result << std::endl;
    }
} // namespace grocery::ui