#pragma once

/**
 * @file serializer.hpp
 * @brief Public interface for converting grocery data to and from text.
 */

#include <string>
#include "include/grocery/data/kvstore.hpp"
namespace grocery::data
{
    /** @brief Converts the grocery store to and from its text representation. */
    class Serializer
    {
    public:
        /** @brief Construct a serializer. */
        Serializer() = default;

        /** @brief Destroy a serializer. */
        virtual ~Serializer() = default;
        /**
         * @brief Serializes item names and counts into a string.
         * @param kvStore Store whose contents will be serialized.
         * @param data Output string receiving the serialized records.
         */
        void Serialize(const KVStore &kvStore, std::string &data) const;

        /**
         * @brief Deserializes records and adds them to a store.
         * @param kvStore Store that receives the parsed records.
         * @param data Text containing serialized records.
         */
        void Deserialize(KVStore &kvStore, const std::string &data) const;

    private:
        const char *delimiter = " \t\v\f\r\n"; // whitespace characters
    }; // class Serializer
} // namespace grocery::data