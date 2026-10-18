#pragma once

/**
 * @file reader.hpp
 * @brief Public interface for reading text files.
 */

#include <string>
namespace grocery::io
{
    /** @brief Reads text files into strings. */
    class Reader
    {
    public:
        /** @brief Construct a file reader. */
        Reader() = default;

        /** @brief Destroy the file reader. */
        virtual ~Reader() = default;
        /**
         * @brief Appends a file's contents to a string.
         * @param filename Path of the file to read.
         * @param data String to which the file contents are appended.
         * @throws std::runtime_error If the file cannot be opened.
         *
         * Each source line is followed by a newline in the destination.
         */
        void Read(const std::string &filename, std::string &data);
    }; // class Reader
} // namespace grocery::io