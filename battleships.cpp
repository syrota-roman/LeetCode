/*
Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:

    You receive a valid board, made of only battleships or empty slots.
    Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
    At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.

Example:

X..X
...X
...X

In the above board there are 2 battleships.

Invalid Example:

...X
XXXX
...X

This is an invalid board that you will not receive - as battleships will always have a cell separating between them.

Follow up:
Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for ( int i = 0; i < board.size(); i++ ) {
            for ( int j = 0; j < board[i].size(); j++ ) {
                if ( board[i][j] == 'X' && (i == 0 || board[i - 1][j] != 'X') &&
                                           (j == 0 || board[i][j - 1] != 'X') ) {
                    count++;
                }
            }
        }
        return count;
    }
};

void printBoard(vector<vector<char>>& board) {
    for ( int i = 0; i < board.size(); i++ ) {
        for ( int j = 0; j < board[i].size(); j++ ) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[]) {
    vector<char> tmp  = {'X', '.', 'X', 'X'};
    vector<char> tmp1 = {'.', '.', '.', '.'};
    vector<char> tmp2 = {'X', '.', 'X', 'X'};
    vector<vector<char>> board;
    board.push_back(tmp);
    board.push_back(tmp1);
    board.push_back(tmp2);
    
    printBoard(board);
    
    Solution sol;
    int count = sol.countBattleships(board);
    
    cout << "Count = " << count << endl;
    
    return 0;
}
