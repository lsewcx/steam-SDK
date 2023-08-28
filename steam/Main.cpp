#include"isteamuserstats.h"
#include"achievement.cpp"
#include"friends.cpp"
using namespace std;


bool achievementStatus;
const char* name="ACH_WIN_ONE_GAME";//成就的api
uint32 unlockTime;//解锁时间
const char* langueage;
bool achieved;


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

void show()
{
    SteamUtils()->SetOverlayNotificationPosition(k_EPositionBottomRight);
}

const char* getlangueage()//获取客户端语言
{
    langueage = SteamUtils()->GetSteamUILanguage();
    return langueage;
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
    else
    {
        //startfreinds();
        ISteamUserStats* steamUserStats = SteamUserStats();//新建
        /*手动形式
        Achievement* achievement = new Achievement();
        achievement->Unlockachievements(name, steamUserStats);
        achievement->GetUserAchievementAndUnlockTime(GetCurrentPlayerSteamID(), name, achieved, unlockTime, steamUserStats);
        delete achievement;
        */
        //析构函数自动调用形式
        Achievement achievement;
        achievement.GetUserAchievementAndUnlockTime(GetCurrentPlayerSteamID(), name, achieved, unlockTime, steamUserStats);
        
    }
    return 0;
}