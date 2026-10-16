#pragma once

#include <string>
#include <functional>

namespace grocery::ui
{

    class Item
    {
    public:
        explicit Item(std::string text, std::function<void()> action);
        ~Item() = default;
        const std::string &GetText() const;
        void ExecuteAction() const;
        void PrintItem() const;

    private:
        std::string text;
        std::function<void()> action;
        int index{0};
        static int nextIndex;
    }; // class Item

} // namespace grocery::ui
