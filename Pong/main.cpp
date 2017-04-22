#include <iostream>

#include "GameObjects.h"
#include "Player.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    Player p1 = Player();

    p1.saveData();
    p1.loadData("jordy");
    p1.setGamesPlayed(20);
    p1.setGamesWon(10);
    p1.saveData();
    return 0;
}