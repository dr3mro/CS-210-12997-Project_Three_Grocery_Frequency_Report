#include "include/grocery/data/datacontroller.hpp"
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
} // namespace grocery::data