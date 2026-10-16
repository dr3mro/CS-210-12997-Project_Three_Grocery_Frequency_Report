/**
 * @file controller.cpp
 * @brief Implements the grocery data-operation facade.
 */

#include "include/grocery/data/controller.hpp"

namespace grocery::data
{
    /** Read raw input, then convert it into store entries. */
    void DataController::LoadData(const std::string &filename)
    {
        std::string data;
        // Read the whole file first so parsing remains independent of streams.
        fileController.ReadFromFile(filename, data);
        // Deserialization converts each record into a store increment.
        serializer.Deserialize(kvStore, data);
    }

    /** Serialize the current store and persist the resulting report. */
    void DataController::SaveData(const std::string &filename) const
    {
        std::string data;
        // Serialization is kept separate from file I/O so both responsibilities
        // can be changed independently.
        serializer.Serialize(kvStore, data);
        // Writing happens only after serialization has completed successfully.
        fileController.WriteToFile(filename, data);
    }

    /** Look up one item and delegate its display formatting. */
    std::string DataController::FindItem(const std::string &key) const
    {
        int count = kvStore.getItem(key);
        // The presenter owns user-facing wording and formatting.
        return presenter.FormatItemWithQuantity(key, count);
    }

    /** Create the formatted table view for all stored items. */
    std::string DataController::ListItemsWithQuantities() const
    {
        // Presenters receive copies rather than direct access to the singleton.
        auto items = kvStore.getItemsWithQuantaties();
        return presenter.FormatItemsWithQuantities(items);
    }

    /** Create the formatted histogram view for all stored items. */
    std::string DataController::GetItemsHistogram() const
    {
        // Both display modes use the same current frequency snapshot.
        auto items = kvStore.getItemsWithQuantaties();
        return presenter.FormatItemsHistogram(items);
    }
} // namespace grocery::data