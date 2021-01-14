#include "GrabMode.h"
#include "World/Terrain/Cell.h"
#include "World/Robot/Robot.h"
#include "App/GameInterface.h"

namespace merc
{

GrabMode::GrabMode(GameInterface& gameInterface)
	: ModeBase(gameInterface, Mode::Grab)
{

}

void GrabMode::OnFrame()
{
	// TODO:: simulate

	Render();
}

}
