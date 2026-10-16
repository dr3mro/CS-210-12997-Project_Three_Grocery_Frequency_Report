#pragma once

/**
 * @file controller.hpp
 * @brief Public interface for coordinating grocery data operations.
 */

#include "include/grocery/data/kvstore.hpp"
#include "include/grocery/io/controller.hpp"
#include "include/grocery/data/serializer.hpp"
#include "include/grocery/data/presenter.hpp"
namespace grocery::data
{
    /** @brief Coordinates persistence, storage, and presentation of grocery data. */
    class DataController
    {
    public:
        /** @brief Construct a data-operation controller. */
        DataController() = default;

        /** @brief Destroy the data-operation controller. */
        virtual ~DataController() = default;

        /**
         * @brief Loads item records from a text file into the shared data store.
         * @param filename Path of the file to read.
         * @throws std::runtime_error If the file cannot be opened.
         */
        void LoadData(const std::string &filename);

        /**
         * @brief Serializes the shared data store and writes it to a file.
         * @param filename Path of the file to write.
         * @throws std::runtime_error If the file cannot be opened.
         */
        void SaveData(const std::string &filename) const;

        /**
         * @brief Formats the quantity of one item for display.
         * @param key Item name to look up.
         * @return A quantity message, or a not-found message if absent.
         */
        std::string FindItem(const std::string &key) const;

        /**
         * @brief Formats every stored item and its quantity as a table.
         * @return A display-ready quantity table.
         */
        std::string ListItemsWithQuantities() const;

        /**
         * @brief Formats every stored item as an asterisk histogram.
         * @return A display-ready histogram.
         */
        std::string GetItemsHistogram() const;

    private:
        grocery::io::FileController fileController;
        grocery::data::KVStore &kvStore = grocery::data::KVStore::Instance();
        grocery::data::Serializer serializer;
        grocery::data::DataPresenter presenter;

    }; // class DataController
} // namespace grocery::data
