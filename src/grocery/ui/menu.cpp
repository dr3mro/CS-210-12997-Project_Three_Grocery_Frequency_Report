#include "include/grocery/ui/menu.hpp"
#include <iostream>

namespace grocery::ui
{
    void Menu::addItem(const std::string &text, std::function<void()> action)
    {
        items.emplace_back(text, action);
    }

    void Menu::ShowMenu() const
    {
        std::cout << "Menu:\n";
        for (const auto &item : items)
        {
            item.PrintItem();
        }
    }
    int Menu::GetMenuItemCount() const
    {
        return static_cast<int>(items.size());
    }
    Item *Menu::getItem(int index)
    {
        if (index >= 0 && index < GetMenuItemCount())
        {
            return &items[index];
        }
        std::cerr << "Index out of bounds: " << index << std::endl;
        return nullptr;
    }
} // namespace grocery::ui
