#pragma once
#include <map>
#include <string>

namespace grocery::data
{
    class KVStore : public std::map<std::string, int>
    {
    public:
        static KVStore& Instance();

        KVStore(const KVStore&) = delete;
        KVStore& operator=(const KVStore&) = delete;

        void addItem(const std::string &key);
        int getItem(const std::string &key) const;

    private:
        KVStore() = default;
        ~KVStore() = default;
    }; // class KVStore
} // namespace grocery::data