#include "GrabMode.h"
#include "Cell.h"
#include <vector>
#include "Robot.h"
#include"GaneInterface.h"

namespace merc
{

	GrabMode::GrabMode(GameInterface& gameInterface)
		: ModeBase(gameInterface, Mode::Grab)
	{

	}


	typedef
		struct node {
		int x, y;
		Direction unmove;
		node* prev;
		node(int x, int y, Direction m = Direction(5), node* prev = nullptr) : x(x), y(y), unmove(m), prev(prev) {	};
		~node() {
			if (this->prev != nullptr) {
				delete this->prev;
			}
		}
	} node;

	bool GrabMode::check_collector_move(std::vector<std::vector<Cell>> map, size_t x, size_t y, size_t rs_x, size_t rs_y, size_t length, size_t width, bool sapper_exist) {
		if (x < 0 || x >(length - 1) || y < 0 || y >(width - 1)) {
			return false;
		}
		if (map[x][y].GetType() == CellType::Rock || map[x][y].GetType() == CellType::Bomb || map[x][y].GetType() == CellType::Unknown) {
			return false;
		}
		if (sapper_exist == false) {
			return true;
		}
		if ((x == rs_x) && (y == rs_y)) {
			return false;
		}
		return true;
	}
	bool GrabMode::check_sapper_move(std::vector<std::vector<Cell>> map, size_t x, size_t y, size_t rc_x, size_t rc_y, size_t length, size_t width) {
		if (x < 0 || x > length - 1 || y < 0 || y > width - 1) {
			return false;
		}
		if (map[x][y].GetType() == CellType::Rock || map[x][y].GetType() == CellType::Unknown) {
			return false;
		}
		if ((x == rc_x) && (y == rc_y)) {
			return false;
		}
		return true;
	}

	std::vector<Direction> GrabMode::find_way_collector() {

		size_t length = (GameInterface.World).GetSizeX();
		size_t width = (GameInterface.World).GetSizeY();

		(GameInterface.Player).AddSapper();
		bool sapper_exist = true;

		std::vector<std::vector<bool>> check(length, std::vector<bool>(width, true));

		size_t robot_sapper_x = 0, robot_sapper_y = 0;

		if ((GameInterface.PLayer).GetSapper() != nullptr) {

			std::pair<size_t, size_t> robot_sapper_coords = ((GameInterface.Player).GetSapper()).GetCoords();
			robot_sapper_x = robot_sapper_coords.first;
			robot_sapper_y = robot_sapper_coords.second;
		}

		std::pair<size_t, size_t> robot_collector_coords = ((GameInterface.Player).GetCollector()).GetCoords();

		node* begin = new node(robot_collector_coords.first, robot_collector_coords.second);
		check[robot_collector_coords.first][robot_collector_coords.second] = false;

		node* result = nullptr;
		std::queue<node*>* q = new std::queue<node*>();
		q->push(begin);

		while (!q->empty()) {
			node* n = (q->front());
			if ((((GameInterface.Player).m_sapper).m_exploredTerrain[n->x][n->y]).GetType() == CellType::Apple) {
				result = n;
				break;
			}
			q->pop();
			if (check_collector_move(((GameInterface.Player).GetSapper()).m_exploredTerrain, n->x, n->y + 1, robot_sapper_x, robot_sapper_y, length, width, sapper_exist) == true && check[n->x][n->y + 1] == true) {
				node* tmp = new node(n->x, n->y + 1, Direction::Up, n);
				check[n->x][n->y + 1] = false;
				q->push(tmp);
			}
			if (check_collector_move(((GameInterface.Player).GetSapper()).m_exploredTerrain, n->x + 1, n->y, robot_sapper_x, robot_sapper_y, length, width, sapper_exist) == true && check[n->x + 1][n->y] == true) {
				node* tmp = new node(n->x + 1, n->y, Direction::Right, n);
				check[n->x + 1][n->y] = false;
				q->push(tmp);
			}
			if (check_collector_move(((GameInterface.Player).GetSapper()).m_exploredTerrain, n->x, n->y - 1, robot_sapper_x, robot_sapper_y, length, width, sapper_exist) == true && check[n->x][n->y - 1] == true) {
				node* tmp = new node(n->x, n->y - 1, Direction::Down, n);
				check[n->x][n->y - 1] = false;
				q->push(tmp);
			}
			if (check_collector_move(((GameInterface.Player).GetSapper()).m_exploredTerrain, n->x - 1, n->y, robot_sapper_x, robot_sapper_y, length, width, sapper_exist) == true && check[n->x - 1][n->y] == true) {
				node* tmp = new node(n->x - 1, n->y, Direction::Left, n);
				check[n->x - 1][n->y] = false;
				q->push(tmp);
			}
		}

		std::vector<Direction> way = {};
		while (result != nullptr && result->prev != nullptr) {
			way.push_back(result->unmove);
			result = result->prev;
		}

		std::vector<Direction> result2(way.size());
		for (size_t i = 0; i < way.size(); ++i) {
			result2[i] = way[way.size() - 1 - i];
		}
		delete q;
		delete result;
		return result2;
	}
	std::vector<Direction> GrabMode::find_way_sapper() {

		std::pair<size_t, size_t> robot_sapper_coords = ((GameInterface.Player).m_sapper).GetCoords();
		std::pair<size_t, size_t> robot_collector_coords = ((GameInterface.Player).m_collector).GetCoords();

		size_t length = (GameInterface.World).GetSizeX();
		size_t width = (GameInterface.World).GetSizeY();

		size_t robot_collector_x = robot_collector_coords.first;
		size_t robot_collector_y = robot_collector_coords.second;

		std::vector<std::vector<bool>> check(length, std::vector<bool>(width, true));

		node* begin = new node(robot_sapper_coords.first, robot_sapper_coords.second);
		check[robot_sapper_coords.first][robot_sapper_coords.second] = false;

		node* result = nullptr;
		std::queue<node*>* q = new std::queue<node*>();
		q->push(begin);
		while (!q->empty()) {
			node* n = (q->front());
			if ((((GameInterface.Player).m_sapper).m_exploredTerrain[n->x][n->y]).GetType() == CellType::Bomb) {
				result = n;// new node(n->x, n->y, n->unmove, n->prev);
				break;
			}
			q->pop();
			if (this->check_sapper_move(((GameInterface.Player).GetSapper()).m_exploredTerrain, n->x, n->y + 1, robot_collector_x, robot_collector_y, length, width) == true && check[n->x][n->y + 1] == true) {
				node* tmp = new node(n->x, n->y + 1, Direction::Up, n);
				check[n->x][n->y + 1] = false;
				q->push(tmp);
			}
			if (this->check_sapper_move(((GameInterface.Player).GetSapper()).m_exploredTerrain, n->x + 1, n->y, robot_collector_x, robot_collector_y, length, width) == true && check[n->x + 1][n->y] == true) {
				node* tmp = new node(n->x + 1, n->y, Direction::Right, n);
				check[n->x + 1][n->y] = false;
				q->push(tmp);
			}
			if (this->check_sapper_move(((GameInterface.Player).GetSapper()).m_exploredTerrain, n->x, n->y - 1, robot_collector_x, robot_collector_y, length, width) == true && check[n->x][n->y - 1] == true) {
				node* tmp = new node(n->x, n->y - 1, Direction::Down, n);
				check[n->x][n->y - 1] = false;
				q->push(tmp);
			}
			if (this->check_sapper_move(((GameInterface.Player).GetSapper()).m_exploredTerrain, n->x - 1, n->y, robot_collector_x, robot_collector_y, length, width) == true && check[n->x - 1][n->y] == true) {
				node* tmp = new node(n->x - 1, n->y, Direction::Left, n);
				check[n->x - 1][n->y] = false;
				q->push(tmp);
			}
		}
		std::vector<Direction> way = {};
		while (result != nullptr && result->prev != nullptr) {
			way.push_back(result->unmove);
			result = result->prev;
		}

		std::vector<Direction> result2(way.size());
		for (size_t i = 0; i < way.size(); ++i) {
			result2[i] = way[way.size() - 1 - i];
		}

		delete q;
		delete result;
		return result2;
	}



	bool GrabMode::apples_on_map() {

		size_t length = (GameInterface.World).GetSizeX();
		size_t width = (GameInterface.World).GetSizeY();

		for (size_t i = 0; i < length; ++i) {
			for (size_t j = 0; j < width; ++j) {
				if ((((GameInterface.Player).GetSapper()).m_exploredTerrain[i][j]).GetType() == CellType::apple) {
					return true;
				}
			}
		}
		return false;
	}


	bool GrabMode::bombs_on_map() {

		size_t length = (GameInterface.World).GetSizeX();
		size_t width = (GameInterface.World).GetSizeY();

		for (size_t i = 0; i < length; ++i) {
			for (size_t j = 0; j < width; ++j) {
				if ((((GameInterface.Player).GetSapper()).m_exploredTerrain[i][j]).GetType() == CellType::Bomb) {
					return true;
				}
			}
		}
		return false;
	}

	bool GrabMode::move_collector(Direction m) {
		switch (m) {
		case Direction::Up:
		case Direction::Right:
		case Direction::Down:
		case Direction::Left: {
			((GameInterface.Player).GetCollector()).Move(m);
			break;
		}
		default: {return false; }
		}
		return true;
	}
	void GrabMode::move_sapper(Direction m) {
		if (((GameInterface.Player).GetSapper() == nullptr) {
			return;
		}
		switch (m) {
		case Direction::Up:
		case Direction::Right:
		case Direction::Down:
		case Direction::Left: {

			((GameInterface.Player).GetSapper()).Move(m);
				break;
		}
		default: {	return; }
		}
		return;
	}


	void GrabMode::auto_grab() {

		if (GameInterface. == block::apple) {
			this->grab(context);
		}

		while (apples_on_map()) {

			std::vector<Direction> way = find_way_collector();
			if (way.size() == 0) {
				break;
			}
			for (size_t i = 0; i < way.size(); ++i) {
				move_collector(way[i]);
			}
			this->grab(context);

		}
		if ((GameInterface.Player).GetSapper() == nullptr) {
			return;
		}
		if ((((GameInterface.Player).GetSapper()).m_exploredTerrain[m_x][m_y]).GetType() == CellType::Bomb) {
			Delouse();

		}

		while (bombs_on_map()) {
			std::vector<Direction> way = find_way_sapper();
			if (way.size() == 0) {
				break;
			}
			for (int i = 0; i < way.size(); ++i) {
				move_sapper(way[i]);

			}
			Delouse();
		}
		return;
	}


	void GrabMode::OnFrame()
	{
		// TODO:: simulate
		auto_grab();

		Render();
	}

}
