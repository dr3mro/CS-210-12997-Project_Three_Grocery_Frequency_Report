#pragma once

#include <vector>
#include <functional>

#include "grocery/ui/item.hpp"
namespace grocery::ui
{
    class Menu
    {
    private:
        std::vector<Item> items;

    public:
        Menu() = default;
        ~Menu() = default;
        void addItem(const std::string &text, std::function<void()> action);
        void ShowMenu() const;
        int GetMenuItemCount() const;
        Item *getItem(int index);
    }; // class Menu
} // namespace grocery::ui