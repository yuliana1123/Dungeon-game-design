#include "Dungeon.h"
#include <string>
#include <vector>

void Dungeon::startGame(){

    cout << endl;
    cout << "PPPPPPPPPPP        OOOOOO       kk                 \\         " << endl;
    cout << "PP        PP     OOO    OOO     kk                  \\        " << endl;
    cout << "PP        PP    OO        OO    kk      kk           \\       " << endl;
    cout << "PP        PP    OO        OO    kk    kkk         eeeeeee     " << endl;
    cout << "PPPPPPPPPPP     OO        OO    kk  kkk         eee     eee   " << endl;
    cout << "PP              OO        OO    kkkkk          eeeeeeeeeeeee  " << endl;
    cout << "PP              OO        OO    kkkkk          eeeeeeeeeeeee  " << endl;
    cout << "PP              OO        OO    kk  kkk        ee             " << endl;
    cout << "PP               OOO    OOO     kk    kkk       eee     eee   " << endl;
    cout << "PPP                OOOOOO       kk      kkk       eeeeeee     " << endl;
    cout << endl;
    cout << "Welcome ! ! !" << endl;

}

void Dungeon::createPlayer(){

    char character;


    cout << endl;
    cout << "Choose your character." << endl;
    cout << "A. Pika" << endl;
    cout << "B. Squirtle" << endl;//³Ç¥§
    cout << "C. Bulbasaur" << endl;//§®µì

    cin >> character;
    if(character == 'A' || character == 'a'){

        cout << endl << "Hello Pika ~" << endl;
        Dungeon::player.setNo(1);
        Dungeon::player.setMaxHealth(100);
        Dungeon::player.setCurrentHealth(100);
        Dungeon::player.setAttack(40);
        Dungeon::player.setDefense(20);
    }
    else if(character == 'B' || character == 'b'){

        cout << endl << "Hello Squirtle ~" << endl;
        Dungeon::player.setNo(2);
        Dungeon::player.setMaxHealth(100);
        Dungeon::player.setCurrentHealth(100);
        Dungeon::player.setAttack(35);
        Dungeon::player.setDefense(25);

    }
    else if(character == 'C' || character == 'c'){

        cout << endl << "Hello Bulbasaur ~" << endl;
        Dungeon::player.setNo(3);
        Dungeon::player.setMaxHealth(100);
        Dungeon::player.setCurrentHealth(100);
        Dungeon::player.setAttack(30);
        Dungeon::player.setDefense(30);
    }
    else
        createPlayer();

}

void Dungeon::createMap(){

    Dungeon::nowPos = 0;

    int eachRoom[Dungeon::totalRoom][4] = {{-1,-1,-1,1},{-1,2,0,3},{1,-1,-1,-1},{4,7,1,5},{-1,3,-1,-1},{6,-1,3,-1},{-1,5,-1,-1},{3,-1,-1,-1}};
    char roomChar[Dungeon::totalRoom] = {'n','n','m','n','t','n','e','s'};
    int pa;

    pa = 0;

    do{
        Object *o;
        Room* eachr = new Room;

        int dir1, dir2, dir3, dir4;
        dir1 = eachRoom[pa][0];
        dir2 = eachRoom[pa][1];
        dir3 = eachRoom[pa][2];
        dir4 = eachRoom[pa][3];

        eachr->up = dir1;
        eachr->down = dir2;
        eachr->left = dir3;
        eachr->right = dir4;

        char type;
        type = roomChar[pa];

        if(type == 'e'){
            eachr->o = new Endingpos;
        }
        else if(type == 't'){
            eachr->o = new NPC;
        }
        else if(type == 'm'){
            eachr->o = new Monster;
        }
        else if(type == 's'){
            eachr->o = new Trading;
        }
        else
        {eachr->o = nullptr;}


        Dungeon::rooms.push_back(eachr);

        pa++;

    }while(pa < totalRoom);

    pa = 0;

    do{
        if(Dungeon::rooms[pa]->left >= 0) {
            Dungeon::rooms[pa]->left_room = Dungeon::rooms[rooms[pa]->left];
        }
        else{
            Dungeon::rooms[pa]->left_room = nullptr;
        }

        if(Dungeon::rooms[pa]->right >= 0) {
            Dungeon::rooms[pa]->right_room = Dungeon::rooms[rooms[pa]->right];
        }
        else{
            Dungeon::rooms[pa]->right_room = nullptr;
        }

        if(Dungeon::rooms[pa]->up >= 0) {
            Dungeon::rooms[pa]->up_room = Dungeon::rooms[Dungeon::rooms[pa]->up];
        }
        else{
            Dungeon::rooms[pa]->up_room = nullptr;
        }

        if(Dungeon::rooms[pa]->down >= 0) {
            Dungeon::rooms[pa]->down_room = Dungeon::rooms[rooms[pa]->down];
        }
        else{
            Dungeon::rooms[pa]->down_room = nullptr;
        }

        pa++;

    }while(pa < totalRoom);


}

void Dungeon::handleMovement(){

    char direct;

    cout << endl << "You are in Room" << Dungeon::nowPos << endl;
    cout << "Where do you want to go?" << endl;
    cout << "W. up." << endl;
    cout << "S. down." << endl;
    cout << "A. left." << endl;
    cout << "D. right." << endl;

    cin >> direct;


    if (direct == 'w'||direct == 'W') {

        if (Dungeon::rooms[Dungeon::nowPos]->up_room != nullptr) {

            Dungeon::nowPos = Dungeon::rooms[Dungeon::nowPos]->up;
            cout << endl << "You are in Room" << Dungeon::nowPos << endl;

        }
        else {
            cout << "You can not go this way!" << endl;
            handleMovement();
        }

    }
    else if (direct == 's'||direct == 'S'){

        if (Dungeon::rooms[Dungeon::nowPos]->down_room != nullptr) {
            Dungeon::nowPos = Dungeon::rooms[Dungeon::nowPos]->down;
            cout << endl << "You are in Room" << Dungeon::nowPos << endl;

        }
        else {
            cout << "You can not go this way!" << endl;
            handleMovement();
        }

    }
    else if (direct == 'a'||direct == 'A'){

        if (Dungeon::rooms[Dungeon::nowPos]->left_room != nullptr) {
            Dungeon::nowPos = Dungeon::rooms[Dungeon::nowPos]->left;
            cout << endl << "You are in Room" << Dungeon::nowPos << endl;

        }
        else {
            cout << "You can not go this way!" << endl;
            handleMovement();
        }

    }
    else if (direct == 'd'||direct == 'D'){

        if (Dungeon::rooms[Dungeon::nowPos]->right_room != nullptr) {
            Dungeon::nowPos = Dungeon::rooms[Dungeon::nowPos]->right;
            cout << endl << "You are in Room" << Dungeon::nowPos << endl;

        }
        else {
            cout << "You can not go this way!" << endl;
            handleMovement();
        }

    }
    if(Dungeon::nowPos == 2 || Dungeon::nowPos == 4){

        if (Dungeon::rooms[Dungeon::nowPos]->o != nullptr){

            if (handleMovement(Dungeon::rooms[Dungeon::nowPos]->o)){
                Dungeon::player.levelUp(Dungeon::player.getAttack());
                cout << "Successfully completed the task\n";
                delete Dungeon::rooms[Dungeon::nowPos]->o;
                Dungeon::rooms[Dungeon::nowPos]->o = nullptr;

            }
            else{
                Dungeon::nowPos = Dungeon::nowPos - 1;
                chooseAction();
            }

        }
        else{
            chooseAction();
        }

    }
    else if(Dungeon::nowPos == 7 ){

        if (Dungeon::rooms[7]->o != nullptr && Dungeon::rooms[4]->o == nullptr){

            if (handleMovement(Dungeon::rooms[Dungeon::nowPos]->o)){

                if(pickUpItem()){
                    delete Dungeon::rooms[Dungeon::nowPos]->o;
                    Dungeon::rooms[Dungeon::nowPos]->o = nullptr;
                }

            }
            else
                chooseAction();

        }
        else{
            cout << "You do not have any treasure.\n";
            chooseAction();
        }

    }

    if(Dungeon::nowPos == 6){

        if(payMoney()){
            cout << "\nSuccessfully ENTERING\n";
            if (Dungeon::rooms[Dungeon::nowPos]->o != nullptr){

                if (handleMovement(Dungeon::rooms[Dungeon::nowPos]->o)){

                    delete Dungeon::rooms[Dungeon::nowPos]->o;
                    Dungeon::rooms[Dungeon::nowPos]->o = nullptr;

                }
                else
                chooseAction();

            }

            if(checkGameLogic()){
                cout << "\nFinally you escaped the dungeon.\n";
                cout << "Ash Ketchum is waiting for you~\n";
                exit(0);
            }
            else{
                cout << "\nYou did not finish the mission.\n";
                chooseAction();
            }
        }
        else{
            Dungeon::nowPos = 5;
            chooseAction();
        }

    }
    else{
        chooseAction();
    }

}

bool Dungeon::handleMovement(Object *dir){

        int chaHealth, chaAttack, chaDefense;
        char ans;

        chaHealth = player.getCurrentHealth();
        chaAttack = player.getAttack();
        chaDefense = player.getDefense();

        dir->tiggerORnot();
        cin >> ans;

        if(ans == 'a'||ans == 'A'){
            if( dir->triggerEvent(chaHealth,chaAttack,chaDefense)){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
}

void Dungeon::chooseAction(){

    char choice;
    bool checkState;

    cout << endl;
    cout << "What do you want to do?" << endl;
    cout << "A.Check your state." << endl;
    cout << "B.Move." << endl;
    cout << "C.Open your backpack." << endl;

    cin >> choice;

    if (choice == 'a' || choice == 'A'){
        checkState = Dungeon::player.checkIsDead();
        chooseAction();
    }
    else if (choice == 'b' || choice == 'B'){
        handleMovement();
    }
    else if (choice == 'c' || choice == 'C'){
        checkBackpack();

        chooseAction();
    }
    else
        chooseAction();
}

bool Dungeon::checkGameLogic(){

    if(Dungeon::rooms[2]->o == nullptr && Dungeon::rooms[4]->o == nullptr && Dungeon::rooms[7]->o == nullptr){
        return true;
    }
    else if(Dungeon::rooms[4]->o == nullptr){
        //checkBackpack();
        cout << "Return you $100\n";
        cout << "Only finished one mission.\n";
        return false;
    }
    else{
        return false;
    }

}

bool Dungeon::payMoney(){

    if(Dungeon::rooms[7]->o != nullptr){

        cout << "You do not have enough money...\n";
        cout << "Will retreat you to Room5\n";
        return false;

    }
    else{
        cout << "PAY 100 for entering.\n";
        return true;
    }

}

bool Dungeon::pickUpItem(){

    cout << "Do you want to pick the money up?\n";
    char ans;
    cout << "A. Yes.\n";
    cout << "B. No.\n";
    cin >> ans;

    if(ans == 'a'||ans == 'A'){
        cout << "$100 is in your bag\n";
        return true;
    }
    else{
        cout << "> < Return the key to you.\n";
        return false;
    }



}



bool Dungeon::checkBackpack(){

    cout << "~~~~~~~~~~~~~~" << endl;
    cout << "Weapon: Punch" << endl;
    if(Dungeon::rooms[4]->o == nullptr){

        if(Dungeon::player.getNo() == 1)
            cout << "Weapon: Thunderbolt" << endl;
        else if(Dungeon::player.getNo() == 2)
            cout << "Weapon: Bubble + Aqua Tail" << endl;
        else
            cout << "Weapon: Vine Whip" << endl;
    }


    if(Dungeon::rooms[4]->o == nullptr && Dungeon::rooms[7]->o == nullptr){
        cout << "Money: $100." << endl;
            return true;
    }
    else if(Dungeon::rooms[4]->o == nullptr){
        cout << "Treasure: Golden key." << endl;
        return true;
    }
    else{
        cout << "No goods." << endl;
        return false;
    }

}

void Dungeon::runDungeon(){

    startGame();
    createPlayer();
    createMap();
    chooseAction();

}

Dungeon::Dungeon(){}
