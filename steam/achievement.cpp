#include"achievement.hpp"
#include <iostream>
using namespace std;

class Achievement : Achievementinterface {
public:
	void Unlockachievements(const char* name, ISteamUserStats* steamUserStats) override {
		steamUserStats->RequestCurrentStats();// 获取当前用户状态
		steamUserStats->SetAchievement(name);//解锁成就
	}

	void GetUserAchievementAndUnlockTime(uint64_t id, const char* name, bool achieved, uint32 unlockTime, ISteamUserStats* steamUserStats)override {
		steamUserStats->GetUserAchievementAndUnlockTime(id, name, &achieved, &unlockTime);
		cout << achieved << " " << unlockTime<<endl;
	}
	~Achievement()
	{
		cout << "end" << endl;
	}
};