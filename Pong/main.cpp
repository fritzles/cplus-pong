#include <iostream>

#include "GameObjects.h"
#include "Player.h"

using namespace std;

int main() {
    Player p1 = Player();
    //tests player class
    p1.saveData();
    p1.loadData("jordy");
    p1.setGamesPlayed(20);
    cout << p1.getGamesLost() << p1.getGamesPlayed() << p1.getGamesWon() << p1.getName() << endl;
    p1.setGamesWon(10);
    p1.saveData();
    return 0;
}