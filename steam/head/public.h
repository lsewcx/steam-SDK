#pragma once
#include"isteamuserstats.h"
#include"achievement.cpp"
#include"friends.cpp"
#include"Utils.cpp"
class Public {
private:
	bool achievementStatus;
	const char* name = "ACH_WIN_ONE_GAME";//成就的api
	uint32 unlockTime;//解锁时间
	const char* langueage;
	bool achieved;
public:
	Achievement achievement;
	Utils utils;
	const char* get_name() { return name; };
	uint32 get_unlockTime() { return unlockTime; };
	bool get_achieved() { return achieved; };
};