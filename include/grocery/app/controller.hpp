#pragma once

/** @brief Default input file containing one grocery item per line. */
constexpr const char *INPUT_FILE = "CS210_Project_Three_Input_File.txt";

/** @brief Default output file for the serialized item frequencies. */
constexpr const char *OUTPUT_FILE = "frequency.dat";

namespace grocery::app
{
    /** @brief Coordinates data loading, report generation, and user interaction. */
    class AppController
    {
    public:
        AppController() = default;
        virtual ~AppController() = default;
        /**
         * @brief Runs the complete grocery application.
         *
         * Loads the default input file, writes the frequency report, creates
         * the interactive menu, and processes user selections.
         */
        void Run();

    private:
    }; // class AppController
} // namespace grocery::app
