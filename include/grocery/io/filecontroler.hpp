#pragma once
#include <string>
#include <grocery/io/reader.hpp>
#include <grocery/io/writer.hpp>

namespace grocery::io
{
    class FileController
    {
    public:
        FileController() = default;
        virtual ~FileController() = default;
        virtual void ReadFromFile(const std::string &filename, std::string &data);
        virtual void WriteToFile(const std::string &filename, const std::string &data) const;

    private:
        Reader reader;
        Writer writer;
    }; // class FileController
} // namespace grocery::io