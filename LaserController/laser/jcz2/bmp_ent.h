#pragma once

#include <QObject>
#include <QDataStream>
#include <QPoint>
#include <QString>
#include <QRect>

struct BmpEntInfo
{
	QString bmpPath;
	int bmpAttrib;
	int scanAttrib;
	double brightness;
	double contrast;
	double pointTime;
	int importDpi;
};
Q_DECLARE_METATYPE(BmpEntInfo)

QDataStream& operator<<(QDataStream& out, const BmpEntInfo& bmpEnt);
QDataStream& operator>>(QDataStream& in, BmpEntInfo& bmpEnt);

inline QDataStream& operator<<(QDataStream& out, const BmpEntInfo& bmpEnt)
{
	out	<< bmpEnt.bmpPath
		<< bmpEnt.bmpAttrib
		<< bmpEnt.scanAttrib
		<< bmpEnt.brightness
		<< bmpEnt.contrast
		<< bmpEnt.pointTime
		<< bmpEnt.importDpi;
	return out;
}

inline QDataStream& operator>>(QDataStream& in, BmpEntInfo& bmpEnt)
{
	in  >> bmpEnt.bmpPath
		>> bmpEnt.bmpAttrib
		>> bmpEnt.scanAttrib
		>> bmpEnt.brightness
		>> bmpEnt.contrast
		>> bmpEnt.pointTime
		>> bmpEnt.importDpi;
	return in;
}