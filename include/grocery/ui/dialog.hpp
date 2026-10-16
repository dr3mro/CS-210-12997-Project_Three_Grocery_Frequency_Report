#pragma once
#include "grocery/data/controller.hpp"
namespace grocery::ui
{
    /** @brief Provides interactive dialogs for grocery data operations. */
    class Dialog
    {
    private:
        grocery::data::DataController dataController;

    public:
        Dialog() = default;
        virtual ~Dialog() = default;

        /**
         * @brief Repeatedly prompts for an item name and displays its count.
         *
         * Entering `q` returns to the main menu.
         */
        void FindItem();

        /** @brief Displays all stored items and their quantities. */
        void ListItemsWithQuantities();

        /** @brief Displays the frequency histogram for all stored items. */
        void PrintHistogram();
    }; // class Dialog
} // namespace grocery::ui