#pragma once
#include <string>
#include "include/grocery/data/kvstore.hpp"
namespace grocery::data
{
    class Serializer
    {
    public:
        Serializer() = default;
        virtual ~Serializer() = default;
        void Serialize(const KVStore &kvStore, std::string &data) const;
        void Deserialize(KVStore &kvStore, const std::string &data) const;

    private:
        const char *delimiter = " \t\v\f\r\n"; // whitespace characters
    }; // class Serializer
} // namespace grocery::data