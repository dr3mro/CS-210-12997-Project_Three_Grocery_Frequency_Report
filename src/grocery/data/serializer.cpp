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
            // Find the first configured delimiter in the item name.
            auto pos = pair.first.find_first_of(delimiter);
            if (pos != std::string::npos)
            {
                // Emit the prefix and count in the existing report format.
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
                // Ignore lines that do not contain a configured delimiter.
                auto pos = line.find_first_of(delimiter);
                if (pos != std::string::npos)
                {
                    // Only the text before the delimiter becomes the item key.
                    kvStore.addItem(line.substr(0, pos));
                }
            }
        }
    }
} // namespace grocery::data