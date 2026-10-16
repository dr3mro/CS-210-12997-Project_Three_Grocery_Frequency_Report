#pragma once
#include <string>
#include <map>

namespace grocery::data
{
    /** @brief Produces human-readable views of grocery data. */
    class DataPresenter
    {
    public:
        DataPresenter() = default;
        virtual ~DataPresenter() = default;

        /**
         * @brief Formats one item and its quantity.
         * @param item Item name.
         * @param quantity Item count.
         * @return Formatted quantity text, or a not-found message for zero.
         */
        std::string FormatItemWithQuantity(const std::string &item, int quantity) const;

        /**
         * @brief Formats item counts as an aligned table.
         * @param items Items and their counts.
         * @return Formatted table text.
         */
        std::string FormatItemsWithQuantities(const std::map<std::string, int> &items) const;

        /**
         * @brief Formats item counts as an asterisk histogram.
         * @param items Items and their counts.
         * @return Formatted histogram text.
         */
        std::string FormatItemsHistogram(const std::map<std::string, int> &items) const;

    }; // class DataPresenter

} // namespace grocery::data