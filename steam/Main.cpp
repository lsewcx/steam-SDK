#include "steam_api.h"
#include<iostream>
#include"isteamuserstats.h"
using namespace std;


bool achievementStatus;
//const char* name="ACH_WIN_ONE_GAME";//成就的api
const char* name="01";//成就的api
uint32 unlockTime;//解锁时间

bool InitSteamAPI()
{
    if (!SteamAPI_Init())
    {
        // 处理初始化失败的逻辑
        return false;
    }
    return true;
}

uint64_t GetCurrentPlayerSteamID()//获取当前steam用户的ID
{
    CSteamID steamID = SteamUser()->GetSteamID();
    return steamID.ConvertToUint64();
}


int main()
{
    if (SteamAPI_RestartAppIfNecessary(480))
    {
        return 1;
    }
    if (!SteamAPI_Init())
    {
        printf("Fatal Error - Steam must be running to play this game (SteamAPI_Init() failed).\n");
        return 1;
    }
    if (InitSteamAPI() == true) {
        ISteamUserStats* steamUserStats = SteamUserStats();//新建
        bool success = steamUserStats->RequestCurrentStats();// 获取当前用户状态
        if (success)
        {
            bool achieved = false;
            steamUserStats->ClearAchievement(name);
            //steamUserStats->SetAchievement(name);//解锁成就
            //steamUserStats->GetUserAchievementAndUnlockTime(GetCurrentPlayerSteamID(),name, &achieved, &unlockTime);//获取成就解锁时间和是否解锁
            //cout << achieved << " " << unlockTime;
        }
    }


    return 0;
}