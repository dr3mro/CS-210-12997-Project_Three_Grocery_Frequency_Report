#pragma once

constexpr const char *INPUT_FILE = "CS210_Project_Three_Input_File.txt";
constexpr const char *OUTPUT_FILE = "frequency.dat";

namespace grocery::app
{
    class AppController
    {
    public:
        AppController() = default;
        virtual ~AppController() = default;
        void Run();

    private:
    }; // class AppController
} // namespace grocery::app
