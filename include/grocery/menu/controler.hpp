#pragma once

#include "grocery/menu/menu.hpp"

namespace grocery::ui
{
    class MenuController
    {
    private:
        Menu menu;

    public:
        MenuController() = default;
        ~MenuController() = default;

        void CreateMenu();
        void ShowMenu() const;
        void ProcessUserChoice();

    }; // class MenuController
} // namespace grocery::ui