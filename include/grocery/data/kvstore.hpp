#pragma once
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

        KVStore(const KVStore &) = delete;
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
        KVStore() = default;
        ~KVStore() = default;
    }; // class KVStore
} // namespace grocery::data