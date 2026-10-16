#include "include/grocery/data/serializer.hpp"

#include <sstream>

namespace grocery::data
{
    void Serializer::Serialize(const KVStore &kvStore, std::string &data) const
    {
        std::ostringstream stream;

        auto delimiter = " \t\v\f\r\n"; // whitespace characters

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

        while (std::getline(stream, line))
        {

            if (!line.empty())
            {
                kvStore.addItem(line);
            }
        }
    }
} // namespace grocery::data