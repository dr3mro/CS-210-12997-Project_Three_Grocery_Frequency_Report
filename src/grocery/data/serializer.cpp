#include "include/grocery/data/serializer.hpp"

#include <sstream>

namespace grocery::data
{
    void Serializer::Serialize(const KVStore &kvStore, std::string &data) const
    {
        std::ostringstream stream;

        for (const auto &pair : kvStore)
        {
            auto pos = pair.first.find_first_of(delimiter);
            if (pos != std::string::npos)
            {
                stream << pair.first.substr(0, pos) << ":" << pair.second << "\n";
            }
        }
        data = stream.str();
    }

    void Serializer::Deserialize(KVStore &kvStore, const std::string &data) const
    {
        std::istringstream stream(data);

        std::string line;

        while (std::getline(stream >> std::ws, line))
        {
            if (!line.empty())
            {
                auto pos = line.find_first_of(delimiter);
                if (pos != std::string::npos)
                {
                    kvStore.addItem(line.substr(0, pos));
                }
            }
        }
    }
} // namespace grocery::data