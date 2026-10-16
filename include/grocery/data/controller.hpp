#pragma once
#include "include/grocery/data/kvstore.hpp"
#include "include/grocery/io/controller.hpp"
#include "include/grocery/data/serializer.hpp"

namespace grocery::data
{
    class DataController
    {
    public:
        DataController() = default;
        virtual ~DataController() = default;

        void LoadData(const std::string &filename);
        void SaveData(const std::string &filename) const;

        std::string FindItem(const std::string &key) const;

    private:
        grocery::io::FileController fileController;
        grocery::data::KVStore& kvStore = grocery::data::KVStore::Instance();
        grocery::data::Serializer serializer;

    }; // class DataController
} // namespace grocery::data
