#pragma once
#include <string>
#include <grocery/io/reader.hpp>
#include <grocery/io/writer.hpp>

namespace grocery::io
{
    /** @brief Facade for the application's file reading and writing operations. */
    class FileController
    {
    public:
        FileController() = default;
        virtual ~FileController() = default;
        /**
         * @brief Reads a complete file into a string.
         * @param filename Path of the file to read.
         * @param data Output string receiving the file contents.
         * @throws std::runtime_error If the file cannot be opened.
         */
        virtual void ReadFromFile(const std::string &filename, std::string &data);

        /**
         * @brief Writes a string to a file.
         * @param filename Path of the file to write.
         * @param data Text to write.
         * @throws std::runtime_error If the file cannot be opened.
         */
        virtual void WriteToFile(const std::string &filename, const std::string &data) const;

    private:
        Reader reader;
        Writer writer;
    }; // class FileController
} // namespace grocery::io