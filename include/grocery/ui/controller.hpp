#pragma once

#include "grocery/ui/menu.hpp"
#include "grocery/ui/dialog.hpp"
namespace grocery::ui
{
    /** @brief Creates and runs the application's interactive console menu. */
    class UIController
    {
    private:
        Menu menu;
        Dialog dialog;

    public:
        UIController() = default;
        ~UIController() = default;

        /** @brief Clears the terminal and positions the cursor at its top left. */
        void cleanScreen() const;

        /** @brief Adds all supported actions to the menu. */
        void CreateMenu();

        /** @brief Displays the current menu. */
        void ShowMenu() const;

        /** @brief Reads and dispatches choices until the user quits. */
        void ProcessUserChoice();

    }; // class UIController
} // namespace grocery::ui