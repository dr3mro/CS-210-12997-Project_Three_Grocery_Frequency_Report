/**
 * @file menu.cpp
 * @brief Implements menu storage, display, and indexed lookup.
 */

#include "include/grocery/ui/menu.hpp"
#include <iostream>

namespace grocery::ui
{
    /**
     * @brief Append a configured item to the menu.
     * @param text Label displayed for the new item.
     * @param action Callback invoked when the item is selected.
     */
    void Menu::addItem(const std::string &text, std::function<void()> action)
    {
        // Store items by value so the menu owns their lifetime.
        items.emplace_back(text, action);
    }

    /**
     * @brief Print the menu heading and every numbered menu item.
     *
     * Items are printed in the same order in which they were added.
     */
    void Menu::ShowMenu() const
    {
        std::cout << std::endl
                  << "Menu:" << std::endl;

        for (const auto &item : items)
        {
            // Item controls its own label/index formatting.
            item.PrintItem();
        }
    }
    /**
     * @brief Return the number of selectable entries currently stored.
     * @return Number of items available in the menu.
     */
    int Menu::GetMenuItemCount() const
    {
        // Convert the container size to the signed type used by the public API.
        return static_cast<int>(items.size());
    }
    /**
     * @brief Return a mutable menu item at a zero-based index.
     * @return The selected item, or nullptr when the index is outside bounds.
     */
    Item *Menu::getItem(int index)
    {
        if (index >= 0 && index < GetMenuItemCount())
        {
            // Bounds checking above makes this pointer safe while the menu lives.
            return &items[index];
        }
        // Returning nullptr lets the caller report an invalid selection safely.
        std::cerr << "Index out of bounds: " << index << std::endl;
        return nullptr;
    }
} // namespace grocery::ui
