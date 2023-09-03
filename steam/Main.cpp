#include"public.h"
using namespace std;

Public publicname;
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
        //achievement.Unlockachievements(name, steamUserStats);
        //publicname.achievement.GetUserAchievementAndUnlockTime(GetCurrentPlayerSteamID(), publicname.get_name(), publicname.get_achieved(), publicname.get_unlockTime(), steamUserStats);
        //cout << publicname.utils.getlanguage()<<endl;
        cout << publicname.utils.getIP() << endl;
    }
    return 0;
}