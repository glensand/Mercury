#include "Player.h"
#include "App/GameInterface.h"

namespace merc
{

Player::Player(GameInterface& gameInterface)
    : m_collector(*gameInterface.World, m_exploredTerrain)
    , m_gameInterface(gameInterface)
{

}

Sapper* Player::GetSapper() const
{
    return m_sapper.get();
}

void Player::AddSapper()
{
    m_sapper = std::make_unique<Sapper>(*m_gameInterface.World, m_exploredTerrain);

    // TODO: random cell and add
}

void Player::RemoveSapper()
{
    m_sapper.reset(nullptr);
}

Collector& Player::GetCollector()
{
    return m_collector;
}

const Terrain& Player::GetExploredTerrain() const
{
    return m_exploredTerrain;
}
}
