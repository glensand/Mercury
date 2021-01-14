#include "World/Terrain/TerrainLoader.h"

namespace merc
{

TerrainLoader::TerrainLoader(std::string fileName)
    : m_fileName(std::move(fileName))
{
}

TerrainLoader::TMap TerrainLoader::Load() const
{
    // TODO:: load terrain... use csv-like format
    const char* str = m_fileName.c_str();
	FILE* fin = fopen(str, "r");
	int length, width;
	fscanf(fin, "%d %d", &length, &width);

	
	TMap map(length,std::vector<Cell>(width));

	char tmp;
	fscanf(fin, "%c", &tmp);
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < width; ++j) {
			char buff;
			fscanf(fin, "%c", &buff);
			Cell b;
			b.SetType(CellType::Empty);
			switch (buff) {
			case ' ': { b.SetType(CellType::Empty); break; }
			case '#': { b.SetType(CellType::Rock); break; }
			case 'a': { b.SetType(CellType::Apple); break; }
			case 'b': { b.SetType(CellType::Bomb); break; }
			}
			map[j][length - i - 1] = b;
		}
		fscanf(fin, "%c", &tmp);
	}

	fclose(fin);

    return map;

    return {};
}

}
