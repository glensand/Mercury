# Mercury
The project represents a casual game with robots on mars;
There is a board divided into cells, and robots placed on some of them. When the game starts, the map is hidden and only one robot is placed on the single-cell: the robot of sapper type.

Each cell may contain one of the following types of entity:
  - Rock, this cell is not available for any robot
  - Empty, just free space
  - Apple or good, something for the collector, 1 apple costs 1 point
  - Bomb, a collector could not be placed on this type of cell, but sapper may delouse it and make it of Empty type
Robots also divided into two types:
  - Sapper, to delouse bombs
  - Collector to scan the map and collect apples

## How to build
You should use Microsoft Visual Studio 2019 to build this project. Just clone the whole repository and calmly run the build. All dependencies will be cloned too, it is not needed to find additional dependencies.
Cmake coming soon!
## Gameplay
There are three different game modes:
  - Manual. The player has to use console commands to move the collector:
    - MOVE[D|U|L|R], to move the robot for one cell to the desired direction
    - SCAN, to scan cell around the robot(sibling cells)
    - GRAB, to collect the apple under robor
  - automatic scaning, collector trying to scan all available cells and make map known
  - automatic collecting and delousing. Collector and sapper moves step by step and do proper work to clear cell.
 
The mode may be changed via next command: SET_MODE [manual|scan N|auto]. N is a count of the scanning iterations which the collector will try to do.

To add or remove the sapper use folowing commands:
- SAPPER_ON to add sapper
- SAPPER_OFF to remove sapper

This student project was quickly developed for a good friend of mine
