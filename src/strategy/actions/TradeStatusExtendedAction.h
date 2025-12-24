#ifndef _PLAYERBOT_TRADESTATUSEXTENDEDACTION_H
#define _PLAYERBOT_TRADESTATUSEXTENDEDACTION_H

#include "QueryItemUsageAction.h"

class Player;
class PlayerbotAI;

class TradeStatusExtendedAction : public QueryItemUsageAction
{
public:
    TradeStatusExtendedAction(PlayerbotAI* botAI) : QueryItemUsageAction(botAI, "trade status extended") {}

    bool Execute([[maybe_unused]] Event event) override;
};

#endif

