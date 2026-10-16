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
        // Function-local initialization provides one lazily created store.
        // The same reference is returned to every controller and dialog.
        static KVStore instance;
        return instance;
    }

    /** Add one occurrence of an item to the frequency map. */
    void KVStore::addItem(const std::string &key)
    {
        // Search first so an existing count can be updated in place.
        auto it = find(key);
        if (it != end())
        {
            // Every input record represents one additional occurrence.
            it->second++;
        }
        else
        {
            // New grocery items begin with their first occurrence.
            // insert() also preserves the map's sorted-key ordering.
            this->insert({key, 1});
        }
    }
    /** Return the count for an item without modifying the map. */
    int KVStore::getItem(const std::string &key) const
    {
        // Use a non-mutating lookup; operator[] would create missing entries.
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
        // The copied map also gives presenters a stable read-only snapshot.
        return *this;
    }

} // namespace grocery::io