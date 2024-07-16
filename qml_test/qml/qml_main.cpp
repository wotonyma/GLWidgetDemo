#include <iostream>
#include "fmt/format.h"
#include "fmt/printf.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "boost/pfr.hpp"
#include <optional>
#include <string>
struct Tst {
    int a;
    float b;
    char c;
    std::optional<std::string> str;
};

int main(int argc, char* argv[])
{
	fmt::print("hello qml");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main_ui.qml")));
    //engine.load(":/main_ui.qml"); //ok ,上面那种写法必须要有前缀qrc
    if (engine.rootObjects().isEmpty())
        return -1;

    Tst tst{1, 2.4f, 'y', "hello"};
    auto i = boost::pfr::get<3>(tst);

    return app.exec();
}