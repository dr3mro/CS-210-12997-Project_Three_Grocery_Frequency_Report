#pragma once
#include <string>
namespace grocery::io
{
    class Writer
    {
    public:
        Writer() = default;
        virtual ~Writer() = default;
        void Write(const std::string &filename, const std::string &data);
    }; // class writer
} // namespace grocery::io