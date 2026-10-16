#pragma once
#include <string>
namespace grocery::io
{
    class Reader
    {
    public:
        Reader() = default;
        virtual ~Reader() = default;
        virtual void Read(std::string &data) = 0;
    }; // class Reader
} // namespace grocery::io