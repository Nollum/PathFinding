#pragma once

#include <vector>
#include <string>
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

	void createBoundaries(Player* player);

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

	std::cout << "Map created with width of " << this->width << " and height of " << this->height << std::endl;

	this->createBoundaries(player);

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

void Map::update(Player* player) {

	for (size_t j = 0; j < this->height; j++) {
		for (size_t i = 0; i < this->width; i++) {
			if (j == 0 || i == 0 || j == this->height - 1 || i == this->width - 1) {
				this->grid[j][i] = 'W';
			}
			else {
				this->grid[j][i] = '_';

			}
		}
	}
	this->grid[player->y][player->x] = 'p';
	this->grid[this->goal_y][this->goal_x] = 'X';

	for (int i = 1; i < this->width - 2; i++) {
		this->grid[10][i] = 'W';
	}
}

void Map::createBoundaries(Player* player) {

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




