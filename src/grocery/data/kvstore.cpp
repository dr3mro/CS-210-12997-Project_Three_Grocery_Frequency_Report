#include "include/grocery/data/kvstore.hpp"

namespace grocery::data
{

    void KVStore::addItem(const std::string &key)
    {
        auto it = find(key);
        if (it != end())
        {
            it->second++;
        }
        else
        {
            this->insert({key, 1});
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