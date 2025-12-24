#ifndef _PLAYERBOT_WOTLKDUNGEONGDACTIONS_H
#define _PLAYERBOT_WOTLKDUNGEONGDACTIONS_H

#include "Action.h"
#include "AttackAction.h"
#include "PlayerbotAI.h"
#include "Playerbots.h"
#include "GundrakTriggers.h"

class AvoidPoisonNovaAction : public MovementAction
{
public:
    AvoidPoisonNovaAction(PlayerbotAI* ai) : MovementAction(ai, "avoid poison nova") {}
    bool Execute([[maybe_unused]] Event event) override;
};

class AttackSnakeWrapAction : public AttackAction
{
public:
    AttackSnakeWrapAction(PlayerbotAI* ai) : AttackAction(ai, "attack snake wrap") {}
    bool Execute([[maybe_unused]] Event event) override;
};

class AvoidWhirlingSlashAction : public MovementAction
{
public:
    AvoidWhirlingSlashAction(PlayerbotAI* ai) : MovementAction(ai, "avoid whirling slash") {}
    bool Execute([[maybe_unused]] Event event) override;
};

#endif

