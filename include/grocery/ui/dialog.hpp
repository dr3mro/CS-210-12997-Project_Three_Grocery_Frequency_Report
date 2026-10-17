#pragma once

/**
 * @file dialog.hpp
 * @brief Public interface for interactive grocery-data dialogs.
 */

#include "grocery/data/controller.hpp"
namespace grocery::ui
{
    /**
     * @brief Provides interactive dialogs backed by the shared data controller.
     */
    class Dialog
    {
    private:
        grocery::data::DataController &dataController =
            grocery::data::DataController::Instance();

    public:
        /** @brief Construct a dialog using DataController::Instance(). */
        Dialog() = default;

        /** @brief Destroy the dialog without owning the shared data controller. */
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