#include "include/grocery/io/writer.hpp"
#include <fstream>
#include <string>
namespace grocery::io
{
    void Writer::Write(const std::string &filename, const std::string &data)
    {
        std::ofstream file(filename);

        if (!file.is_open())
        {
            throw std::runtime_error("Could not open file for writing: " + filename);
        }
        file << data;
        file.close();
    }
} // namespace grocery::io
