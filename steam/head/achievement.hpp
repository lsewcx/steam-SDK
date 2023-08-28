
#ifndef ACHIEVEMENT_HPP
#define ACHIEVEMENT_HPP
#include "steam_api.h"

// 类的定义和实现
class Achievementinterface {
public:
	virtual void Unlockachievements(const char* name, ISteamUserStats* steamUserStats) = 0;

	virtual void GetUserAchievementAndUnlockTime(uint64_t id, const char* name, bool achieved, uint32 unlockTime, ISteamUserStats* steamUserStats) = 0;
};

#endif // ACHIEVEMENT_HPP