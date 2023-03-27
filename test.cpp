/* Testing File */

#include "connect_four_game.h"


void randomGameTest(int row=10, int col=5) {
    ConnectFourGame game(row, col);
    ConnectFourGame::Players player_red = ConnectFourGame::Players::red;
    ConnectFourGame::Players player_yellow = ConnectFourGame::Players::yellow;
    while (not game.finished()) {
        // red 
        game.move(player_red, rand() % col);
        // yellow
        game.move(player_yellow, rand() % col);
        // print board 
        game.printBoard();
    }
    cout << "The winner is: " << game.getWinner() << endl;
}

void Test1() {
    ConnectFourGame game(5, 5);
    game.setBoard(1, 3, ConnectFourGame::Players::red);
    game.setBoard(2, 2, ConnectFourGame::Players::red);
    game.setBoard(3, 1, ConnectFourGame::Players::red);
    game.move(ConnectFourGame::Players::red, 0);
    game.printBoard();
    cout << "The winner is: " << game.getWinner() << endl;
    return;
}

void Test2() {
    ConnectFourGame game(4, 4);
    game.setBoard(0, 0, ConnectFourGame::Players::red);
    game.setBoard(1, 1, ConnectFourGame::Players::red);
    game.setBoard(2, 2, ConnectFourGame::Players::red);
    game.move(ConnectFourGame::Players::red, 3);
    game.printBoard();
    cout << "The winner is: " << game.getWinner() << endl;
    return;
}

int main()
{
    srand(time(nullptr));
    randomGameTest(10, 10);
    // Test1();
    // Test2();
    return 0;
}