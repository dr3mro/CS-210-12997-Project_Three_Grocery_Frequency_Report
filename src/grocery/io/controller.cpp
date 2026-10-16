/**
 * @file controller.cpp
 * @brief Implements delegation between the file facade and stream helpers.
 */

#include "include/grocery/io/controller.hpp"

namespace grocery::io
{
    /** Route file input through the Reader component. */
    void FileController::ReadFromFile(const std::string &filename, std::string &data)
    {
        // Delegate stream handling to the dedicated reader.
        // Keeping this facade thin lets the data layer avoid stream details.
        reader.Read(filename, data);
    }

    /** Route file output through the Writer component. */
    void FileController::WriteToFile(const std::string &filename, const std::string &data) const
    {
        // Delegate stream handling to the dedicated writer.
        // Writer owns file-open and error handling for output operations.
        writer.Write(filename, data);
    }
} // namespace grocery::io
