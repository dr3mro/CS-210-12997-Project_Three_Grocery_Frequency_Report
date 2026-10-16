/**
 * @file presenter.cpp
 * @brief Implements table, histogram, and lookup formatting.
 */

#include "include/grocery/data/presenter.hpp"
#include <iomanip>
#include <sstream>

namespace grocery::data
{
    /** @brief Render one item lookup result. */
    std::string DataPresenter::FormatItemWithQuantity(const std::string &item, int quantity) const
    {
        if (quantity > 0)
        {
            // Positive quantities are shown directly to the user.
            return item + ": " + std::to_string(quantity);
        }
        else
        {
            // A zero count indicates that the requested item is absent.
            return item + ": Not found";
        }
    }

    /** @brief Render all item counts in a fixed-width table. */
    std::string DataPresenter::FormatItemsWithQuantities(const std::map<std::string, int> &items) const
    {
        std::stringstream result;

        // The three header lines establish the table's visual boundary.
        result << std::string(30, '-') << std::endl;
        result << std::setw(30) << std::left << "Items with Quantities" << std::endl;
        result << std::string(30, '-') << std::endl;

        // std::map iteration keeps the report in alphabetical item order.
        for (const auto &item : items)
        {
            // Reserve 25 columns for names and four right-aligned columns for counts.
            result << std::setw(25) << std::left << item.first << std::setw(4) << std::right << std::to_string(item.second) << std::endl;
        }

        // Close the table after the final record.
        result << std::string(30, '-') << std::endl;
        // Keep the fallback for future callers that may pass an empty stream.
        return result.str().empty() ? "No items found." : result.str();
    }

    /** @brief Render all item counts as an asterisk histogram. */
    std::string DataPresenter::FormatItemsHistogram(const std::map<std::string, int> &items) const
    {
        std::stringstream result;

        // The histogram uses a wider frame to leave room for the bars.
        result << std::string(50, '-') << std::endl;
        result << std::setw(50) << std::left << "Items Histogram" << std::endl;
        result << std::string(50, '-') << std::endl;

        // One asterisk represents one occurrence of the item.
        for (const auto &item : items)
        {
            // Align the item name, bar, and numeric count for easy comparison.
            result << std::setw(25) << std::left << item.first << std::setw(4) << std::right << std::setw(20) << std::right << std::string(item.second, '*')  << ' '<< std::left << "[" << std::setw(2) << std::right << item.second << "] ";
            result << std::endl;
        }

        // Close the histogram after all bars have been written.
        result << std::string(50, '-') << std::endl;
        // Return the complete assembled view as one printable string.
        return result.str().empty() ? "No items found." : result.str();
    }

} // namespace grocery::data