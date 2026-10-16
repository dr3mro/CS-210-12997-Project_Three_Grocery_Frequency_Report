#pragma once
#include <string>
namespace grocery::data
{
    class DataPresenter
    {
    public:
        DataPresenter() = default;
        virtual ~DataPresenter() = default;

        std::string FormatItemWithQuantity(const std::string &item, int quantity) const;

    }; // class DataPresenter

} // namespace grocery::data