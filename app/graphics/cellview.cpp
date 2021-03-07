#include "cellview.h"
#include "world/robot/robot.h"
#include "world/terrain/cell.h"

namespace merc
{

CellView::CellView(TCellTextures& cellTextures, sf::Texture& collector, sf::Texture& sapper)
    : m_cellTextures(cellTextures)
    , m_collector(collector)
    , m_sapper(sapper)
{

}

void CellView::Initialize(std::size_t x, std::size_t y)
{
    m_x = x;
    m_y = y;

    InitializeShape();
}

void CellView::Render(const Cell& cell)
{
    if(cell.GetRobot() != nullptr)
    {
        RenderRobot(*cell.GetRobot());
    }
    else
    {
        RenderCell(cell);
    }
}

void CellView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_shape, states);
}

void CellView::InitializeShape()
{
    m_shape.setTexture(Texture(CellType::Unknown), true);
    m_shape.setPosition(float(m_x), float(m_y));
}

void CellView::RenderRobot(const Robot& robot)
{
    auto&& texture = robot.GetType() == RobotType::Collector ? m_collector : m_sapper;
    m_shape.setTexture(texture);
}

void CellView::RenderCell(const Cell& cell)
{
    m_shape.setTexture(Texture(cell.GetType()));
}

sf::Texture& CellView::Texture(CellType type) const
{
    return m_cellTextures[std::size_t(type)];
}

}
