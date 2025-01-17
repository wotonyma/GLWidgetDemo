#pragma once

#include "qstring.h"

class LaserCfgMgr
{
public:
	static LaserCfgMgr& instance();
	~LaserCfgMgr();
	LaserCfgMgr(const LaserCfgMgr&) = delete;
	LaserCfgMgr& operator=(const LaserCfgMgr&) = delete;

	bool Load();

public:
	LaserCfgMgr();

	//ezcad
	QString install_path;
	QString tmpl_path;
	//service
	QString host;
	int port;
};

