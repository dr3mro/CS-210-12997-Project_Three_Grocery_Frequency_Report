#include "include/grocery/data/controller.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
namespace grocery::data
{
    void DataController::LoadData(const std::string &filename)
    {
        std::string data;
        fileController.ReadFromFile(filename, data);
        serializer.Deserialize(kvStore, data);
    }

    void DataController::SaveData(const std::string &filename) const
    {
        std::string data;
        serializer.Serialize(kvStore, data);
        fileController.WriteToFile(filename, data);
    }

    std::string DataController::FindItem(const std::string &key) const
    {
        int count = kvStore.getItem(key);
        return presenter.FormatItemWithQuantity(key, count);
    }
    std::string DataController::ListItemsWithQuantities() const
    {
        std::stringstream result;
        auto items = kvStore.getItemsWithQuantaties();
        std::cout << std::string(30, '-') << std::endl;
        std::cout << std::setw(30) << std::left << "Items with Quantities" << std::endl;
        std::cout << std::string(30, '-') << std::endl;
        for (const auto &item : items)
        {
            result << std::setw(25) << std::left << item.first << std::setw(4) << std::right << std::to_string(item.second) << std::endl;
        }
        result << std::string(30, '-') << std::endl;
        return result.str().empty() ? "No items found." : result.str();
    }
} // namespace grocery::data