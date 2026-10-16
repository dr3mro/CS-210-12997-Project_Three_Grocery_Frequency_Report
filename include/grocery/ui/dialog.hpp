#pragma once
#include "grocery/data/controller.hpp"
namespace grocery::ui
{
    class Dialog
    {
    private:
        grocery::data::DataController dataController;

    public:
        Dialog() = default;
        virtual ~Dialog() = default;

        void FindItem();
        void ListItemsWithQuantities();
        void PrintHistogram();
    }; // class Dialog
} // namespace grocery::ui