#pragma once

/**
 * @file controller.hpp
 * @brief Public interface for the interactive console controller.
 */

#include "grocery/ui/dialog.hpp"
#include "grocery/ui/menu.hpp"
namespace grocery::ui
{
    /** @brief Creates and runs the application's interactive console menu. */
    class UIController
    {
    private:
        Menu menu;
        Dialog dialog;

    public:
        /** @brief Construct an empty UI controller. */
        UIController() = default;

        /** @brief Destroy the UI controller and its menu/dialog members. */
        ~UIController() = default;

        /** @brief Clears the terminal and positions the cursor at its top left. */
        void cleanScreen() const;

        /** @brief Adds all supported actions to the menu. */
        void CreateMenu();

        /** @brief Displays the current menu. */
        void ShowMenu() const;

        /**
         * @brief Reads and dispatches choices until the user quits.
         *
         * Numeric choices are one-based in the user interface and converted
         * to zero-based menu indexes internally.
         */
        void ProcessUserChoice();

    }; // class UIController
} // namespace grocery::ui