#pragma once
#include "ModeBase.h"

namespace merc
{

class ManualMode final : public ModeBase
{
public:
    ManualMode(GameInterface& gameInterface);
    virtual ~ManualMode() = default;

    virtual void OnFrame() override;
};

}
