#include "Player.h"
#include "App/GameInterface.h"
#include "World/IWorld.h"

namespace merc
{

Player::Player(GameInterface& gameInterface)
    : m_collector(*gameInterface.World, m_exploredTerrain)
    , m_gameInterface(gameInterface)
{
    m_exploredTerrain.Resize(m_gameInterface.World->GetSizeX(), m_gameInterface.World->GetSizeY());
    m_collector.InitializePosition();
}

Sapper* Player::GetSapper() const
{
    return m_sapper.get();
}

void Player::AddSapper()
{
    m_sapper = std::make_unique<Sapper>(*m_gameInterface.World, m_exploredTerrain);

    m_sapper->InitializePosition();
}

void Player::RemoveSapper()
{
    m_sapper.reset(nullptr);
}

Collector& Player::GetCollector()
{
    return m_collector;
}

const Collector& Player::GetCollector() const
{
    return m_collector;
}

const Terrain& Player::GetExploredTerrain() const
{
    return m_exploredTerrain;
}

}
