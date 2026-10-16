#include <include/grocery/io/reader.hpp>
#include <fstream>
#include <string>

namespace grocery::io
{
    void Reader::Read(const std::string &filename, std::string &data)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            throw std::runtime_error("Could not open file for reading: " + filename);
        }
        std::string line;
        while (std::getline(file, line))
        {
            data += line + "\n";
        }
        file.close();
    }
} // namespace grocery::io