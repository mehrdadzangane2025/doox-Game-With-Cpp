#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
Restart:
    char board[3][3] = {
        { '0', '0', '0' },
        { '0', '0', '0' },
        { '0', '0', '0' }
    };

    int x = 0;
    int y = 0;
    int turn = 1;
    int inputPlayer = 0;
    bool winner = false;
    bool isOver = false;

    while (!isOver) {
        system("cls"); // For Windows (use "clear" on Linux)

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '0') {
                    cout << " | | ";
                }
                else {
                    cout << " |" << board[i][j] << "| ";
                }
            }
            cout << endl;
        }

        // Check rows
        for (int row = 0; row < 3; row++) {
            if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
                if (board[row][0] == 'X') {
                    winner = true;
                    isOver = true;
                }
                else if (board[row][0] == 'O') {
                    winner = false;
                    isOver = true;
                }
            }
        }

        // Check columns
        for (int col = 0; col < 3; col++) {
            if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
                if (board[0][col] == 'X') {
                    winner = true;
                    isOver = true;
                }
                else if (board[0][col] == 'O') {
                    winner = false;
                    isOver = true;
                }
            }
        }

        // Check diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if (board[0][0] == 'X') {
                winner = true;
                isOver = true;
            }
            else if (board[0][0] == 'O') {
                winner = false;
                isOver = true;
            }
        }

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            if (board[0][2] == 'X') {
                winner = true;
                isOver = true;
            }
            else if (board[0][2] == 'O') {
                winner = false;
                isOver = true;
            }
        }
        int sum = 0;
        for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                    {
                        if(board[i][j] != '0'){
                            sum++;
                    }
            }
        if(sum == 9)
        {
            goto Restart;
        }
        if (isOver) {
            cout << endl;
            if (winner) {
                cout << "   (X is win)" << endl;
            }
            else {
                cout << "   (O is win)" << endl;
            }
            break;
        }

        cout << "\nPlease do your turn (1-9): ";
        cin >> inputPlayer;

        x = (inputPlayer - 1) / 3;
        y = (inputPlayer - 1) % 3;

        if (turn == 1) {
            board[x][y] = 'X';
        }
        else {
            board[x][y] = 'O';
        }

        turn *= -1;
    }

    return 0;
}
