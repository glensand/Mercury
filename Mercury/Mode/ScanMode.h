#pragma once

#include "ModeBase.h"

namespace merc
{

class ScanMode final : public ModeBase
{
public:

    ScanMode(GameInterface& gameInterface);

    virtual ~ScanMode() = default;

    virtual void OnFrame() override;
};

}
