#pragma once
#include "include/grocery/data/kvstore.hpp"
#include "include/grocery/io/filecontroler.hpp"
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

    private:
        grocery::io::FileController fileController;
        grocery::data::KVStore kvStore;
        grocery::data::Serializer serializer;

    }; // class DataController
} // namespace grocery::data
