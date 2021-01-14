#pragma once
#include "ModeBase.h"

namespace merc
{

class GrabMode final : public ModeBase
{
public:
    GrabMode(GameInterface& gameInterface);

    virtual ~GrabMode() = default;

    virtual void OnFrame() override;

private:

};

}
