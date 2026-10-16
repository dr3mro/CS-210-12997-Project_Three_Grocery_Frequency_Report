#pragma once
#include <string>
#include <map>

namespace grocery::data
{
    class DataPresenter
    {
    public:
        DataPresenter() = default;
        virtual ~DataPresenter() = default;

        std::string FormatItemWithQuantity(const std::string &item, int quantity) const;
        std::string FormatItemsWithQuantities(const std::map<std::string, int> &items) const;
        std::string FormatItemsHistogram(const std::map<std::string, int> &items) const;

    }; // class DataPresenter

} // namespace grocery::data