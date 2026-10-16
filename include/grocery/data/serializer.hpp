#pragma once

/**
 * @file serializer.hpp
 * @brief Public interface for converting grocery data to and from text.
 */

#include <string>
#include "include/grocery/data/kvstore.hpp"
namespace grocery::data
{
    /**
     * @brief Converts grocery records to and from the project's text format.
     *
     * The current format is line-oriented and uses whitespace as the record
     * delimiter expected by the existing input data.
     */
    class Serializer
    {
    public:
        /** @brief Construct a serializer. */
        Serializer() = default;

        /** @brief Destroy a serializer. */
        virtual ~Serializer() = default;
        /**
         * @brief Serializes eligible item names and counts into a string.
         * @param kvStore Store whose contents will be serialized.
         * @param data Output string receiving the serialized records.
         *
         * Item names that do not contain the configured delimiter are not
         * emitted by the current implementation.
         */
        void Serialize(const KVStore &kvStore, std::string &data) const;

        /**
         * @brief Deserializes eligible records and adds them to a store.
         * @param kvStore Store that receives the parsed records.
         * @param data Text containing serialized records.
         *
         * Empty lines and records without the configured delimiter are ignored.
         * Existing counts are incremented rather than replaced.
         */
        void Deserialize(KVStore &kvStore, const std::string &data) const;

    private:
        /** Whitespace characters used to identify record boundaries. */
        const char *delimiter = " \t\v\f\r\n";
    }; // class Serializer
} // namespace grocery::data