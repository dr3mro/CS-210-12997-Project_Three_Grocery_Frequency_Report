#pragma once
#include <string>
namespace grocery::io
{
    class Writer
    {
    public:
        Writer() = default;
        virtual ~Writer() = default;
        virtual void Write(const std::string &data) = 0;
    }; // class writer
} // namespace grocery::io