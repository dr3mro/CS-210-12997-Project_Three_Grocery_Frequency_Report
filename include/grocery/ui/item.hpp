#pragma once

/**
 * @file item.hpp
 * @brief Public interface for an individual menu item.
 */

#include <string>
#include <functional>

namespace grocery::ui
{
    /** @brief A numbered menu entry and its associated callback. */
    class Item
    {
    public:
        /**
         * @brief Creates a menu item.
         * @param text Text displayed for the item.
         * @param action Function executed when the item is selected.
         */
        explicit Item(std::string text, std::function<void()> action);

        /** @brief Destroy the menu item and its callback. */
        ~Item() = default;

        /** @return The item's display text. */
        const std::string &GetText() const;

        /** @brief Executes the item's callback. */
        void ExecuteAction() const;

        /** @brief Prints the item's number and display text. */
        void PrintItem() const;

    private:
        std::string text;
        std::function<void()> action;
        int index{0};
        static int nextIndex;
    }; // class Item

} // namespace grocery::ui
