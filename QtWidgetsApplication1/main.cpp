#include "qtwidgetsapplication1.h"
#include <QtWidgets/QApplication>
#include <type_traits>
#include <iostream>
#include <string>
#include <filesystem>
#include <exception>
#include <thread>

#include "GLWidget.h"


struct TrivialClass {
    int st_no;
    int age;
    int ch;
    int en;
    int math;
    double avg;
};

int main(int argc, char *argv[])
{
    //auto br = std::is_trivially_copy_constructible<TrivialClass>::value;
    //std::cout << std::is_trivially_copy_constructible<TrivialClass>::value << std::endl;

    QApplication a(argc, argv);
    //QtWidgetsApplication1 w;
    //QWidget w;
    GLWidget w;

    w.show();
    return a.exec();




    auto path = std::filesystem::path("d:/test");
    std::vector<std::string> sub_dir;
    std::string exp;

    try {
        for (auto& entry : std::filesystem::directory_iterator(path))
        {
            if (!entry.is_directory())
                continue;
            sub_dir.emplace_back(entry.path().filename().string());
        }
    }
    catch (std::exception& e) {
        exp = e.what();
        std::cout << e.what() << std::endl;
    }


    return 0;
}
