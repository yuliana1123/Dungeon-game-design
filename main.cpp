#include <iostream>
#include <string>
#include <vector>
#include "Dungeon.h"
#include "Dungeon.cpp"
#include "Item.h"
#include "Monster.h"
#include "NPC.h"
#include "Player.h"


using namespace std;


int main(){
    /*Dungeon dungeon = Dungeon();
    dungeon.runDungeon();*/
    welcome();
    createPlayer();

    return 0;
}
