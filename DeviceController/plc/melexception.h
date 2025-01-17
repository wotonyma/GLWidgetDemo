#pragma once

#include <exception>
#include <string>

class MelException : public std::exception
{
public:
	MelException(long code, const std::string& msg) noexcept
		:_err_code(code)
		,_err_msg(msg)
	{
	}

	virtual const char* what() const noexcept override
	{
		return _err_msg.c_str();
	}

	long errcode() const noexcept
	{
		return _err_code;
	}
private:
	long _err_code;
	std::string _err_msg;	
};