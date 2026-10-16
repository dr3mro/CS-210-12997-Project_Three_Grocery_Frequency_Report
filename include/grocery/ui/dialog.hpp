#pragma once

namespace grocery::ui
{
    class Dialog
    {

    public:
        Dialog() = default;
        virtual ~Dialog() = default;

        void FindItem();
    }; // class Dialog
} // namespace grocery::ui