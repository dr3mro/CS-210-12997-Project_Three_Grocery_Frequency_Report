#pragma once

/**
 * @file dialog.hpp
 * @brief Public interface for interactive grocery-data dialogs.
 */

#include "grocery/data/controller.hpp"
namespace grocery::ui
{
    /** @brief Provides interactive dialogs for grocery data operations. */
    class Dialog
    {
    private:
        grocery::data::DataController dataController;

    public:
        /** @brief Construct a dialog backed by a data controller. */
        Dialog() = default;

        /** @brief Destroy the dialog and its data controller. */
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