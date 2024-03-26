#include <iostream>
#include <string>
#include <vector>
#include "Dungeon.h"
#include "Dungeon.cpp"
#include "Player.h"
#include "GameCharacter.h"
#include "Monster.h"
#include "NPC.h"
#include "Endingpos.h"
#include "Object.h"
#include "Object.cpp"
#include "Trading.h"


using namespace std;


int main(){

    Dungeon dungeon = Dungeon();
    dungeon.runDungeon();

    return 0;
}
