#pragma once
#include <map>
#include <string>

namespace grocery::data
{
    class KVStore : public std::map<std::string, int>
    {
    public:
        KVStore() = default;
        virtual ~KVStore() = default;

        void addItem(const std::string &key);
        int getItem(const std::string &key) const;
    }; // class KVStore
} // namespace grocery::io