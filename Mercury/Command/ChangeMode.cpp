#include "ChangeMode.h"
#include "Command/CommandType.h"
#include "App/GameInterface.h"
#include "Graphics/IView.h"
#include "Player/Player.h"
#include "Mode/GrabMode.h"
#include "Mode/ManualMode.h"
#include "Mode/ScanMode.h"

namespace merc
{
ChangeMode::ChangeMode(Mode mode, std::any&& argument)
    : m_mode(mode)
    , m_argument(argument)
{

}

// TODO:: use mode factory
void ChangeMode::Execute(GameInterface& gameInterface)
{
    // not too bad
    delete gameInterface.Mode;
    gameInterface.Mode = CreateByType(gameInterface);
    gameInterface.Mode->SetOnStepCallback([&]
        {
            gameInterface.View->Render(gameInterface);
        });
}

void ChangeMode::Undo(GameInterface& gameInterface)
{
    // TODO:: cash prev mode
}

CommandType ChangeMode::GetCommandType() const
{
    return CommandType::SetMode;
}

IMode* ChangeMode::CreateByType(GameInterface& gameInterface) const
{
    // NOTE:: switch-case operator is nasty piece of nastiness
    if (m_mode == Mode::Manual) return new ManualMode(gameInterface);
    if (m_mode == Mode::Grab) return new GrabMode(gameInterface);
    if (m_mode == Mode::Scan) return new ScanMode(gameInterface, std::any_cast<int>(m_argument));

    return nullptr;
}

}
