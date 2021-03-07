#include "modebase.h"
#include "app/gameinterface.h"

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

void ModeBase::SetOnStepCallback(std::function<void()>&& callback)
{
    m_onStepCallback = std::move(callback);
}

void ModeBase::Render() const
{
    if(m_onStepCallback)
    {
        m_onStepCallback();
    }
}

}
