/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license, you may redistribute it
 * and/or modify it under version 3 of the License, or (at your option), any later version.
 */

#ifndef _PLAYERBOT_WIPEACTION_H
#define _PLAYERBOT_WIPEACTION_H

#include "Action.h"

class PlayerbotAI;

class WipeAction : public Action
{
public:
    WipeAction(PlayerbotAI* botAI) : Action(botAI, "wipe") {}

    bool Execute([[maybe_unused]] Event event) override;

private:
    std::string bossName;
};

#endif

