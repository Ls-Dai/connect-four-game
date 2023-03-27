/* Testing File */

#include "connect_four_game.h"

void runGame(int row, int col) {
    ConnectFourGame game(row, col);
    ConnectFourGame::Players player_red = ConnectFourGame::Players::red;
    ConnectFourGame::Players player_yellow = ConnectFourGame::Players::yellow;
    while (not game.finished()) {
        int targetCol;
        // red 
        printf("Now it's Player Red's turn, which colomn would you want to choose?\n");
        cin >> targetCol;
        game.move(player_red, targetCol);
        game.printBoard();
        if (game.finished()) 
            break;
        // yellow
        printf("Now it's Player Yellow's turn, which colomn would you want to choose?\n");
        cin >> targetCol;
        game.move(player_yellow, targetCol);
        game.printBoard();
    }
out:
    cout << "The winner is: " << game.getWinner() << endl;
}
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



int main(int argc, char **argv)
{
    int row, col;
    printf("How many rows would you want?\n");
    cin >> row;
    printf("How many cols would you want?\n");
    cin >> col;
    runGame(row, col);
    return 0;
}