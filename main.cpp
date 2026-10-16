/*
 * Amr Osman
 * amr.osman@snhu.edu
 * CS-210-12997-Project_Three_Grocery_Frequency_Report
 *
 * This program reads grocery item names from an input file, counts each
 * item's frequency, writes the results to a report file, and provides an
 * interactive menu for searching and displaying the collected data.
 */

/**
 * @file main.cpp
 * @brief Program entry point for the Grocery frequency application.
 *
 * This translation unit contains the narrow application boundary. The
 * AppController owns the actual startup sequence, data processing, and
 * interactive user interface.
 */

#include <iostream>
#include "include/grocery/app/controller.hpp"

/**
 * @brief Starts the Grocery frequency-report application.
 *
 * The controller is created on the stack so its lifetime covers the complete
 * execution of the application. Run() loads the grocery data, creates the
 * output report, and starts the interactive menu.
 *
 * Any exception that escapes the controller is reported here, at the
 * application boundary, and converted into a non-zero process exit status.
 *
 * @return 0 when the application completes normally; 1 when an exception
 *         reaches the entry point.
 */
int main()
{
    // Keep startup orchestration out of main; the controller owns that workflow.
    try
    {
        grocery::app::AppController appController;

        // Run the complete load, save, and interactive-menu sequence.
        appController.Run();

        // A normal return indicates that no fatal application error occurred.
        return 0;
    }
    catch (const std::exception &error)
    {
        // Report the original exception message instead of silently continuing.
        std::cerr << "Application error: " << error.what() << '\n';

        // Non-zero status allows shells and scripts to detect the failure.
        return 1;
    }
}