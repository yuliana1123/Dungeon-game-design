#include "Dungeon.h"
#include "Player.h"
#include <string>

void welcome(){

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

void createPlayer(){

    char character;
    string na;
    cout << endl;
    cout << "Choose your character." << endl;
    cout << "A. Pika" << endl;
    cout << "B. Squirtle" << endl;//³Ç¥§
    cout << "C. Bulbasaur" << endl;//§®µì

    cin >> character;
    //Player player("n");
    if(character == 'A' || character == 'a'){

        cout << endl << "Hello Pika ~" << endl;
//      player = player("Pika",100,100,60,45);
        //player = player("ap");


    }
    else if(character == 'B' || character == 'b'){

        cout << endl << "Hello Squirtle ~" << endl;
        //player = player("Squirtle",100,100,50,55);

    }
    else if(character == 'C' || character == 'c'){

        cout << endl << "Hello Bulbasaur ~" << endl;
        //player = player("Squirtle",100,100,55,50);
    }
    else
        createPlayer();

}
