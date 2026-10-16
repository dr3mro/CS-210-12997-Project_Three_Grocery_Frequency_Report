/**
 * @file serializer.cpp
 * @brief Implements text serialization and deserialization.
 */

#include "include/grocery/data/serializer.hpp"

#include <sstream>

namespace grocery::data
{
    /** Convert each serializable stored item into one text record. */
    void Serializer::Serialize(const KVStore &kvStore, std::string &data) const
    {
        std::ostringstream stream;

        for (const auto &pair : kvStore)
        {
            // Stop an item name at the first whitespace delimiter.
            auto pos = pair.first.find_first_of(delimiter);
            if (pos != std::string::npos)
            {
                // Keep the count after a colon so the report is human-readable.
                stream << pair.first.substr(0, pos) << ":" << pair.second << "\n";
            }
        }
        // Replace the caller's output instead of appending to previous data.
        data = stream.str();
    }

    /**
     * @brief Parse input records and add their item names to the store.
     *
     * Empty lines are ignored, and records without a recognized delimiter
     * are skipped rather than being inserted as malformed item names.
     */
    void Serializer::Deserialize(KVStore &kvStore, const std::string &data) const
    {
        std::istringstream stream(data);

        std::string line;

        while (std::getline(stream >> std::ws, line))
        {
            if (!line.empty())
            {
                // Ignore malformed lines that contain no field delimiter.
                auto pos = line.find_first_of(delimiter);
                if (pos != std::string::npos)
                {
                    // The item name is the first field in each input record.
                    kvStore.addItem(line.substr(0, pos));
                }
            }
        }
    }
} // namespace grocery::data