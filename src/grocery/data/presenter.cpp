#include "include/grocery/data/presenter.hpp"

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
} // namespace grocery::data