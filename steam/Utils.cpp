#include"Utils.h"


class Utils:Utils_interface {
public:
	const char* getlanguage() override {
		return SteamUtils()->GetSteamUILanguage();
	}
};