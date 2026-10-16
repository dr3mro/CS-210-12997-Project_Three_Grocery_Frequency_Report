#include "include/grocery/data/presenter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
namespace grocery::data
{
    std::string DataPresenter::FormatItemWithQuantity(const std::string &item, int quantity) const
    {
        if (quantity > 0)
        {
            return item + ": " + std::to_string(quantity);
        }
        else
        {
            return item + ": Not found";
        }
    }

    std::string DataPresenter::FormatItemsWithQuantities(const std::map<std::string, int> &items) const
    {
        std::stringstream result;
        result << std::string(30, '-') << std::endl;
        result << std::setw(30) << std::left << "Items with Quantities" << std::endl;
        result << std::string(30, '-') << std::endl;
        for (const auto &item : items)
        {
            result << std::setw(25) << std::left << item.first << std::setw(4) << std::right << std::to_string(item.second) << std::endl;
        }
        result << std::string(30, '-') << std::endl;
        return result.str().empty() ? "No items found." : result.str();
    }
} // namespace grocery::data