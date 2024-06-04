#include <iostream>
#include <QString>
#include <QApplication>
#include "mywnd.h"
using namespace std;
//int main()
//{
//	QString str("hq0");
//	cout << "hello word " << str.toStdString() << endl;
//	system("pause");
//	return 0;
//}
int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	myWnd w;
	w.show();

	return a.exec();
}
