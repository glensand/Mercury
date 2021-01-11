#include "ModeBase.h"
#include "App/GameInterface.h"
#include "Player/Player.h"
#include "Graphics/IView.h"

namespace merc
{

ModeBase::ModeBase(GameInterface& gameInterface, Mode mode)
    : m_gameInterface(gameInterface)
    , m_mode(mode)
{

}

Mode ModeBase::GetMode() const
{
    return m_mode;
}

void ModeBase::Render() const
{
    auto&& terrain = m_gameInterface.Player->GetExploredTerrain();
    m_gameInterface.View->Render(terrain);
}

}
