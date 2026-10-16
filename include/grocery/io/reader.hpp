#pragma once
#include <string>
namespace grocery::io
{
    class Reader
    {
    public:
        Reader() = default;
        virtual ~Reader() = default;
        void Read(const std::string &filename, std::string &data);
    }; // class Reader
} // namespace grocery::i