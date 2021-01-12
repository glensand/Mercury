#pragma once
#include "IMode.h"

namespace merc
{

struct GameInterface;
class Terrain;

class ModeBase : public IMode
{
public:
    ModeBase(GameInterface& gameInterface, Mode mode);
    virtual ~ModeBase() = default;

    virtual Mode GetMode() const override final;

    virtual void SetOnStepCallback(std::function<void()>&& callback) override final;
protected:

    void Render() const;

    std::function<void()> m_onStepCallback;
    GameInterface& m_gameInterface;
    Mode m_mode;
};

}
