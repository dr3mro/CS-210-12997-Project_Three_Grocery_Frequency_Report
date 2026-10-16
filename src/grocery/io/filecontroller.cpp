#include "include/grocery/io/filecontroler.hpp"
#include <fstream>

namespace grocery::io
{
    void FileController::ReadFromFile(const std::string &filename, std::string &data)
    {
        reader.Read(filename, data);
    }

    void FileController::WriteToFile(const std::string &filename, const std::string &data)
    {
        writer.Write(filename, data);
    }
} // namespace grocery::io
