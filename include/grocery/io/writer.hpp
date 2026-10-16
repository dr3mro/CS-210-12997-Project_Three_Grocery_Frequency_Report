#pragma once
#include <string>
namespace grocery::io
{
    /** @brief Writes strings to text files. */
    class Writer
    {
    public:
        Writer() = default;
        virtual ~Writer() = default;
        /**
         * @brief Replaces a file's contents with a string.
         * @param filename Path of the file to write.
         * @param data Text to write.
         * @throws std::runtime_error If the file cannot be opened.
         */
        void Write(const std::string &filename, const std::string &data) const;
    }; // class writer
} // namespace grocery::io