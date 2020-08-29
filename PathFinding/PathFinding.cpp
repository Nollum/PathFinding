//The program uses the Breadth First Search algorithm to locate the goal and construct the path to it

#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include "Map.h"
#include "Player.h"

void Clear()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}


std::vector<std::vector <int>> getNeighbors(std::vector<int> current, Map* map);

void showPath(Map* map, std::vector<std::vector<int> > path, Player* player);

int main()
{
    Player* player = new Player(1, 1);
    Map* map = new Map(40, 20, player, 30, 15);

    std::queue<std::vector<int>> frontier;

    frontier.push({ player->x, player->y });
    std::map<std::vector<int>, std::vector<int>> coord_pairs;

    std::vector<int> current;

    bool goal_found = false;

    while (!frontier.empty()) {
        current = frontier.front();
        frontier.pop();
        for (auto cell : getNeighbors(current, map)) {
            if (cell == std::vector<int>{map->goal_x, map->goal_y}) {
                goal_found = true;
            }
            if (coord_pairs.count(cell) == 0) {
                frontier.push(cell);
                coord_pairs.insert({ cell, current });
            }
            map->grid[cell[1]][cell[0]] = '*';
        }
    }

    if (goal_found) {
        current = { map->goal_x, map->goal_y };

        std::vector<std::vector<int> > path;

        while (current != std::vector<int>{player->x, player->y}) {
            path.push_back(current);
            current = coord_pairs.find(current)->second;
        }

        path.push_back({ player->x, player->y });

        std::reverse(path.begin(), path.end());

        showPath(map, path, player);
    }
    else {
        map->draw();
        std::cout << "Goal unreachable" << std::endl;
    }
    
}

std::vector<std::vector<int> > getNeighbors(std::vector<int> current, Map* map) {
    std::vector<std::vector<int> > neighbors;

    if (current[0] + 1 < map->width && map->grid[current[1]][current[0] + 1] != 'W') {
        neighbors.push_back({ current[0] + 1, current[1] });
    }
    if (current[0] - 1 > 0 && map->grid[current[1]][current[0] - 1] != 'W') {
        neighbors.push_back({ current[0] - 1, current[1] });
    }
    if (current[1] + 1 < map->height && map->grid[current[1] + 1][current[0]] != 'W') {
        neighbors.push_back({ current[0], current[1] + 1 });
    }
    if (current[1] - 1 > 0 && map->grid[current[1] - 1][current[0]] != 'W') {
        neighbors.push_back({ current[0], current[1] - 1 });
    }

    return neighbors;
}

void showPath(Map* map, std::vector<std::vector<int> > path, Player* player) {
    for (auto cell : path) {
        Clear();
        map->grid[cell[1]][cell[0]] = '-';
        map->grid[player->y][player->x] = 'P';
        map->grid[map->goal_y][map->goal_x] = 'X';
        map->draw();
    }
}

//int heuristic(int node_x, int node_y, int goal_x, int goal_y) {
//    int dx = std::abs(node_x - goal_x);
//    int dy = std::abs(node_y - goal_y);
//    return (dx + dy);
//}




