#include <iostream>

#include "qapplication.h"
#include "client_wnd.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	ClientWidget* wnd = new ClientWidget;
	wnd->show();

	return app.exec();
}