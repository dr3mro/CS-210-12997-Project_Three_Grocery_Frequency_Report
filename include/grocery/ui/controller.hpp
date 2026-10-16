#pragma once

#include "grocery/ui/menu.hpp"
#include "grocery/ui/dialog.hpp"
namespace grocery::ui
{
    class UIController
    {
    private:
        Menu menu;
        Dialog dialog;

    public:
        UIController() = default;
        ~UIController() = default;

        void CreateMenu();
        void ShowMenu() const;
        void ProcessUserChoice();

    }; // class UIController
} // namespace grocery::ui