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
         * @param data String that receives the file contents.
         * @throws std::runtime_error If the file cannot be opened.
         */
        void Read(const std::string &filename, std::string &data);
    }; // class Reader
} // namespace grocery::i