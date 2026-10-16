#include "include/grocery/app/controller.hpp"
#include "include/grocery/data/controller.hpp"
#include "grocery/ui/controller.hpp"
namespace grocery::app
{

    void AppController::Run()
    {
        grocery::data::DataController dataController;
        dataController.LoadData(INPUT_FILE);
        dataController.SaveData(OUTPUT_FILE);

        grocery::ui::UIController uiController;
        uiController.CreateMenu();
        uiController.ShowMenu();
        uiController.ProcessUserChoice();
    }
} // namespace grocery::app