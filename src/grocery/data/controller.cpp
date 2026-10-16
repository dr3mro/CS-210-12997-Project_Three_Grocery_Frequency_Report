#include "include/grocery/data/controller.hpp"

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

        auto items = kvStore.getItemsWithQuantaties();
        return presenter.FormatItemsWithQuantities(items);
    }
} // namespace grocery::data