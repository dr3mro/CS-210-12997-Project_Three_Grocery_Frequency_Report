#include "include/grocery/app/controller.hpp"
#include "include/grocery/data/datacontroller.hpp"
#include "grocery/menu/controler.hpp"
namespace grocery::app
{

    void AppController::Run()
    {
        grocery::data::DataController dataController;
        dataController.LoadData(INPUT_FILE);
        dataController.SaveData(OUTPUT_FILE);

        grocery::ui::MenuController menuController;
        menuController.CreateMenu();
        menuController.ShowMenu();
        menuController.ProcessUserChoice();
    }
} // namespace grocery::app