#pragma once

/**
 * @file controller.hpp
 * @brief Application-level orchestration for the Grocery program.
 */

/** @brief Default input file containing one grocery item per line. */
constexpr const char* INPUT_FILE = "CS210_Project_Three_Input_File.txt";

/** @brief Default output file for the serialized item frequencies. */
constexpr const char* OUTPUT_FILE = "frequency.dat";

namespace grocery::app
{
    /** @brief Coordinates data loading, report generation, and user interaction. */
    class AppController
    {
    public:
        /** @brief Construct an application workflow controller. */
        AppController() = default;

        /** @brief Destroy the application workflow controller. */
        virtual ~AppController() = default;
        /**
         * @brief Runs the complete grocery application.
         *
         * Loads the default input file, writes the frequency report, creates
         * the interactive menu, and processes user selections.
         */
        static void Run();

    private:
    }; // class AppController
} // namespace grocery::app
