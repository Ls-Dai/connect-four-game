/* 

Design class that simulates the game of Connect 4

1. The board can be a m x n matrix
2. The players have to alternate moves. This means Red goes first and then Yellow goes afterwards
3. When a game completes (either a player wins, or you cannot place any further moves), we should be able to know
4. We want to be able to know what the board looks like at any given point


Exercise: Design and implement the classes that can simulate playing this game.
1. Design & discuss the classes/function/etc you are going to implement
2. Execute through the actual implementation

*/

#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;


class ConnectFourGame {
// member variables
public:
    enum class Players {
        done = -2,
        invalid,
        null,
        red,
        yellow,
    };

    std::unordered_map<Players, char> Players_Char = {
        {Players::null, 'X'}, 
        {Players::red, 'R'}, 
        {Players::yellow, 'Y'},
    };

private:
    vector<vector<Players>> board{};
    int board_height = 0;
    int board_width = 0;
    bool isFinished = false;
    Players winner = Players::null;

// member functions 
private:
    Players _checkWin(Players id, int r, int c);

public:
    ConnectFourGame(int m, int n);
    ConnectFourGame() = default;
    ConnectFourGame(ConnectFourGame &game) = default;

    Players move(Players player, int colomn);
    void printBoard();
    bool finished();
    string getWinner();
    void setBoard(int row, int col, Players player=Players::null);
};

ConnectFourGame::ConnectFourGame(int m, int n): board_height(m), board_width(n) {
    board.resize(board_height);
    for (auto& row: board) {
        row.resize(board_width);
    }
    return;
}

ConnectFourGame::Players ConnectFourGame::move(Players player, int colomn) {
    if (isFinished) {
        return Players::done;
    }

    int row;
    if (board[board_height - 1][colomn] == Players::null) {
        board[board_height - 1][colomn] = player;
        row = board_height - 1;
        return _checkWin(player, row, colomn);
    }
    for (int i = 0; i < board_height; i++) {
        if (board[i][colomn] != Players::null) {
            if (i == 0) {
                return Players::invalid;
            }
            board[i - 1][colomn] = player;
            row = i - 1;
            break;
        }
    }
    return _checkWin(player, row, colomn);
}

ConnectFourGame::Players ConnectFourGame::_checkWin(Players player, int row, int col) {
    int cons;
    
    // col
    cons = 0;
    for (int i = max(0, col - 4); i < min<int>(board_width, col + 5); i++) {
        if (board[row][i] == player) {
            ++cons;
        } else {
            cons = 0;
        }
        if (cons == 4) {
            goto winning;
        }
    }

    // row
    cons = 0;
    for (int i = max(0, row - 4); i < min<int>(board_height, row + 5); i++) {
        if (board[i][col] == player) {
            ++cons;
        } else {
            cons = 0;
        }
        if (cons == 4) {
            goto winning;
        }
    }


    // slants 
    cons = 0;
    for (int i = 0; i < 7; i++) {
        if (row - 3 + i < 0 or col - 3 + i < 0)
            continue;
        if (row - 3 + i > board_width - 1 or col - 3 + i > board_height - 1)
            continue;

        if (board[row - 3 + i][col - 3 + i] == player) {
            ++cons;
        } else {
            cons = 0;
        }
        if (cons == 4) {
            goto winning;
        }
    }

    cons = 0;
    for (int i = 0; i < 7; i++) {
        if (row + 3 - i < 0 or col - 3 + i < 0)
            continue;
        if (row + 3 - i > board_width - 1 or col - 3 + i > board_height - 1)
            continue;
            
        if (board[row + 3 - i][col - 3 + i] == player) {
            ++cons;
        } else {
            cons = 0;
        }
        if (cons == 4) {
            goto winning;
        }
    }

    return Players::null;

winning:
    isFinished = true;
    winner = player;
    return player;
}

void ConnectFourGame::printBoard() {
    cout << "=== Board Info ===" << endl;
    for (auto const& row: board) {
        for (auto const& player: row) {
            cout << ConnectFourGame::Players_Char[player] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}

bool ConnectFourGame::finished() {
    return isFinished;
}

string ConnectFourGame::getWinner() {
    if (isFinished) {
        return string({Players_Char[winner]});
    }
    return "No Winner Yet";
};

void ConnectFourGame::setBoard(int row, int col, Players player) {
    board[row][col] = player;
    return;
}