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
protected:

    void Render() const;

    GameInterface& m_gameInterface;
    Mode m_mode;
};

}
