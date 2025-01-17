#pragma once

#include <string>

class InitConfigMgr
{
public:
	~InitConfigMgr() = default;
	static InitConfigMgr& Instance();
	void LoadCfg();

	struct InitConf
	{
		//acs
		std::string acs_ip;	//acs ip
		int acs_port;			//acs port
		//service
		std::string svr_host;	//node ip
		int svr_port;			//node port
	};
	const InitConf& Cfg() const { return cfg; }

private:
	InitConfigMgr() = default;
	InitConfigMgr(const InitConfigMgr&) = delete;
	InitConfigMgr& operator=(const InitConfigMgr&) = delete;

	InitConf cfg;
};