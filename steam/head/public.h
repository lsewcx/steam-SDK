#pragma once
#include"isteamuserstats.h"
#include"achievement.cpp"
#include"friends.cpp"
#include"Utils.cpp"
class Public {
public:
	bool achievementStatus;
	const char* name = "ACH_WIN_ONE_GAME";//成就的api
	uint32 unlockTime;//解锁时间
	const char* langueage;
	bool achieved;

	Achievement achievement;
	Utils utils;
};