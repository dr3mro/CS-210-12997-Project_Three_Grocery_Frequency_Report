#pragma once

/**
 * @file writer.hpp
 * @brief Public interface for writing text files.
 */

#include <string>
namespace grocery::io
{
    /** @brief Writes strings to text files. */
    class Writer
    {
    public:
        /** @brief Construct a file writer. */
        Writer() = default;

        /** @brief Destroy the file writer. */
        virtual ~Writer() = default;
        /**
         * @brief Replaces a file's contents with a string.
         * @param filename Path of the file to write.
         * @param data Text to write.
         * @throws std::runtime_error If the file cannot be opened.
         *
         * Stream failures that occur after opening are reported by the
         * underlying stream state and are not converted here.
         */
        void Write(const std::string &filename, const std::string &data) const;
    }; // class writer
} // namespace grocery::io