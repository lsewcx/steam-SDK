#pragma once
#include "steam_api.h"

class Utils_interface {
public:
	virtual const char* getlanguage() = 0;

	virtual const char* getIP() = 0;
};