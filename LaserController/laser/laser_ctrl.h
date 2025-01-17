#pragma once

#include <memory>

class Laser;

class LaserControl
{
public:
	LaserControl(LaserControl&) = delete;
	LaserControl& operator=(LaserControl&) = delete;
	~LaserControl() = default;

	static LaserControl& instance();
	bool initial();
	Laser& laser();

private:
	LaserControl() = default;

	std::unique_ptr<Laser> _laser;
};