#ifndef _PLAYERBOT_WOTLKDUNGEONUPACTIONS_H
#define _PLAYERBOT_WOTLKDUNGEONUPACTIONS_H

#include "Action.h"
#include "AttackAction.h"
#include "PlayerbotAI.h"
#include "Playerbots.h"
#include "UtgardePinnacleTriggers.h"

class AvoidFreezingCloudAction : public MovementAction
{
public:
    AvoidFreezingCloudAction(PlayerbotAI* ai) : MovementAction(ai, "avoid freezing cloud") {}
    bool Execute([[maybe_unused]] Event event) override;
};

class AvoidSkadiWhirlwindAction : public MovementAction
{
public:
    AvoidSkadiWhirlwindAction(PlayerbotAI* ai) : MovementAction(ai, "avoid skadi whirlwind") {}
    bool Execute([[maybe_unused]] Event event) override;
};

#endif

