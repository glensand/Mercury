#include "World/Terrain/TerrainLoader.h"
#include <fstream>

namespace merc
{

TerrainLoader::TerrainLoader(std::string fileName)
    : m_fileName(std::move(fileName))
{
}

TerrainLoader::TMap TerrainLoader::Load() const
{
	std::ifstream in(m_fileName);
	if (!in.is_open())
		throw std::runtime_error("File " + m_fileName + " can't be opened");

	std::size_t width;
	std::size_t height;

	in >> width;
	in >> height;

	if(width == 0 || height == 0)
		throw std::runtime_error("Map size cannot be zero");

	TMap map(height,std::vector<Cell>(width));

	for(std::size_t i { 0 }; i < height; ++i)
	{
	    for(std::size_t j { 0 }; j < width; ++j)
	    {
			char symb{ };
			in >> symb;
			map[i][j].SetType(DispatchType(symb));
	    }
	}

    return map;
}

CellType TerrainLoader::DispatchType(char symb)
{
	if (symb == '*') return CellType::Empty;
	if (symb == '#') return CellType::Rock;
	if (symb == 'a') return CellType::Apple;
	if (symb == 'b') return CellType::Bomb;

	return CellType::Unknown;
}

}
