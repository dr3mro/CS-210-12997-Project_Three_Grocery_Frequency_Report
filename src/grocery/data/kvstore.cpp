/**
 * @file kvstore.cpp
 * @brief Implements the singleton grocery frequency store.
 */

#include "include/grocery/data/kvstore.hpp"

namespace grocery::data
{
    /** Return the lazily initialized process-wide store. */
    KVStore &KVStore::Instance()
    {
        // Function-local initialization creates the store on first use.
        // Every later caller receives the same process-wide reference.
        static KVStore instance;
        return instance;
    }

    /** Add one occurrence of an item to the frequency map. */
    void KVStore::addItem(const std::string &key)
    {
        // Search first so an existing count can be updated without replacing
        // its map node or changing the key's stored spelling.
        auto it = find(key);
        if (it != end())
        {
            // Each accepted input record represents one additional occurrence.
            it->second++;
        }
        else
        {
            // New grocery items begin with their first occurrence.
            // std::map keeps keys ordered for the presentation layer.
            this->insert({key, 1});
        }
    }
    /** Return the count for an item without modifying the map. */
    int KVStore::getItem(const std::string &key) const
    {
        // Use a non-mutating lookup; operator[] would create a missing entry.
        auto it = find(key);
        if (it != end())
        {
            // Return the count stored for the matching item.
            return it->second;
        }

        // Missing items are represented by a zero count.
        return 0;
    }

    /** Return a snapshot of all currently stored item counts. */
    std::map<std::string, int> KVStore::getItemsWithQuantaties() const
    {
        // Return a copy so callers cannot modify the singleton accidentally.
        // Presenters therefore work from a stable snapshot of the counts.
        return *this;
    }

} // namespace grocery::io