#pragma once

#include "Mode/AutoMode.h"

namespace merc
{

class ScanMode final : public AutoMode
{
public:

    ScanMode(GameInterface& gameInterface, std::size_t iterations);

    virtual ~ScanMode() = default;

private:

    virtual bool Step() override;

    std::size_t m_iterations{ 0 };
};

}
