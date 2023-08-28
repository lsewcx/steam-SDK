#include"friend.h"

class Friends : Freinds_interface {
public:
	void showfriends()override {
		SteamFriends()->ActivateGameOverlay("Friends");
	}
};