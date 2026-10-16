#include "include/grocery/data/kvstore.hpp"
#include <iostream>
namespace grocery::data
{
    KVStore &KVStore::Instance()
    {
        static KVStore instance;
        return instance;
    }

    void KVStore::addItem(const std::string &key)
    {
        auto it = find(key);
        if (it != end())
        {
            it->second++;
            // std::cout << key << "::" << it->first << "::" << it->second << std::endl;
        }
        else
        {
            this->insert({key, 1});
            // std::cout << key << "::" << it->first << "::" << it->second << std::endl;
        }
    }
    int KVStore::getItem(const std::string &key) const
    {
        auto it = find(key);
        if (it != end())
        {
            return it->second;
        }
        return 0;
    }

} // namespace grocery::io