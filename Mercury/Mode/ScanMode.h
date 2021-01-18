#pragma once

#include "Mode/AutoMode.h"

namespace merc
{

class ScanMode final : public AutoMode
{
public:

    ScanMode(GameInterface& gameInterface, std::size_t iterations);

    virtual ~ScanMode() = default;

    virtual void OnFrame() override;

private:

    bool Step() const;

    std::size_t m_iterations{ 0 };
};

}
