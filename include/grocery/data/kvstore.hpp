#pragma once

/**
 * @file kvstore.hpp
 * @brief Shared in-memory storage for grocery item frequencies.
 */

#include <map>
#include <string>

namespace grocery::data
{
    /** @brief Singleton map of grocery item names to occurrence counts. */
    class KVStore : public std::map<std::string, int>
    {
    public:
        /**
         * @brief Returns the process-wide data store.
         * @return Reference to the singleton store.
         */
        static KVStore &Instance();

        /** @brief Prevent copying the process-wide store. */
        KVStore(const KVStore &) = delete;

        /** @brief Prevent assigning to the process-wide store. */
        KVStore &operator=(const KVStore &) = delete;

        /**
         * @brief Increments an item's count, adding it when necessary.
         * @param key Item name to increment.
         */
        void addItem(const std::string &key);

        /**
         * @brief Gets an item's current count.
         * @param key Item name to find.
         * @return The stored count, or zero when the item is absent.
         */
        int getItem(const std::string &key) const;

        /**
         * @brief Copies all item counts into a standard map.
         * @return Map containing every stored item and its count.
         */
        std::map<std::string, int> getItemsWithQuantaties() const;

    private:
        /** @brief Construct the store; only Instance() may do so. */
        KVStore() = default;

        /** @brief Destroy the process-wide store at program termination. */
        ~KVStore() = default;
    }; // class KVStore
} // namespace grocery::data