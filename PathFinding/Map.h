#pragma once

#include <vector>
#include "Player.h"

class Map {


public:
	
	std::vector< std::vector<char> > grid;

	int goal_x;
	int goal_y;

	size_t width;
	size_t height;

	Map(int width, int height, Player *player, int goal_x, int goal_y);
	void draw();
	void update(Player* player);
	void createMap(Player* player);
	void addWalls(std::vector<int> pos);

};

Map::Map(int width, int height, Player *player, int goal_x, int goal_y) {

	this->width = width;
	this->height = height;
	this->goal_x = goal_x;
	this->goal_y = goal_y;

	std::vector<char> row(this->width, '*');

	for (size_t y = 0; y < this->height; y++) {
		grid.push_back(row);
	}

	this->createMap(player);

	this->grid[this->goal_y][this->goal_x] = 'X';
}

void Map::draw() {

	for (auto y : this->grid) {
		for (auto x : y) {
			std::cout << x;
		}
		std::cout << "\n";
	}
}

void Map::createMap(Player* player) {

	for (size_t j = 0; j < this->height; j++) {
		for (size_t i = 0; i < this->width; i++) {
			if (player->y == j && player->x == i) {
				this->grid[j][i] = 'p';
			}
			else if (j == 0 || i == 0 || j == this->height - 1 || i == this->width - 1) {
				this->grid[j][i] = 'W';
			}
			else {
				this->grid[j][i] = '_';
			}
		}
	}
}

void Map::addWalls(std::vector<int> pos) {
	this->grid[pos[1]][pos[0]] = 'W';
}




