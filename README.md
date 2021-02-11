# Mercury
Project represents casual game with robots on mars;
There are board divided on cells, and robots placed on some of them. When game starts, the map is hidden and only one robot is placed on the single cell: Sapper.

Each cell may contain one of the folowing types of entity:
  - Rock, this cell is not available for any robot
  - Empty, just free space
  - Apple or good, something for collector, 1 apple costs 1 point
  - Bomb, collector could not be placed on this type of cell, but supper may dellouse it and make it of Empty type
Robots also divided on two types:
  - Sapper, to delouse bombs
  - Collector to scan the map and collect apples

The purpose of the game is apple collecting. For it player should scan the map, delouse bombs and collect apples.
## How to build
You should use Microsoft Visual Studio 2019 to build this project. Just clone whole repository and calmly run the build. All dependencies will be cloned so.
Cmake coming soon!
## Gameplay
If it maybe named so...
Game represents board, divided by cells. Game
There are three different modes:
  - Manual. The player have to use console commands to move the collector:
    - MOVE[D|U|L|R], to move robot for one cell to the desired direction
    - SCAN, to scan cell around the robot(sibling cells)
    - GRAB, to collect the apple under robor
  - automatic scaning, collector trying to scan all available cells and make map known
  - automatic collecting and delousing. Collector and sapper moves step by step and do proper work to clear cell.
  
  This student project was quickly developed for a good friend of mine
