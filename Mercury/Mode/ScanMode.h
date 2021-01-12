#pragma once

#include "ModeBase.h"

namespace merc
{

class ScanMode final : public ModeBase
{
public:

    ScanMode(GameInterface& gameInterface, std::size_t iterations);

    virtual ~ScanMode() = default;

    virtual void OnFrame() override;

private:

    bool CanStep() const;

    void Step();

    std::size_t m_iterations{ 0 };
};

}
