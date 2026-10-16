#include <functional>
#include <iostream>
#include <string>
#include <utility>

#include "grocery/menu/item.hpp"
namespace grocery::ui
{
    Item::Item(std::string text, std::function<void()> action)
        : text(std::move(text)), action(std::move(action)), index(nextIndex++)
    {
    }

    int Item::nextIndex = 1;

    const std::string &Item::GetText() const
    {
        return text;
    }

    void Item::ExecuteAction() const
    {
        action();
    }

    void Item::PrintItem() const
    {
        std::cout << "Press " << index << " to " << text << std::endl;
    }
} // namespace grocery::ui