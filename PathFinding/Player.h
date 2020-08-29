#pragma once

#include <vector>


class Player {

public:
	int x;
	int y;
	Player(int x, int y);
	void move(char inp, std::vector< std::vector<char> > grid);
};

Player::Player(int x, int y) {
	this->x = x;
	this->y = y;
}

void Player::move(char inp, std::vector< std::vector<char> > grid) {
	switch (inp) {
	case 'a': case 'A':
		if (grid[this->y][this->x - 1] != 'W') {
			this->x--;
		}
		break;
	case 'd': case 'D':
		if (grid[this->y][this->x+1] != 'W') {
			this->x++;
		}
		break;
	case 'w': case 'W':
		if (grid[this->y-1][this->x] != 'W') {
			this->y--;
		}
		break;
	case 's': case 'S':
		if (grid[this->y + 1][this->x] != 'W') {
			this->y++;
		}
		break;
	default:
		std::cout << "Invalid character detected" << std::endl;
	}

	std::cout << this->x << ", " << this->y << std::endl;

}