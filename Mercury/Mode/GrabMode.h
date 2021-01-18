#pragma once

#include "Mode/AutoMode.h"

namespace merc
{

class GrabMode final : public AutoMode
{
public:

    GrabMode(GameInterface& gameInterface);

    virtual ~GrabMode() = default;

    virtual void OnFrame() override;

private:

    bool Step();
};

}
