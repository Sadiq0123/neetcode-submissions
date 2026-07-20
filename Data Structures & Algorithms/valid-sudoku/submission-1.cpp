class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> checkerRow(9, 0);
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if (board[i][j]=='.') continue;
                int current = board[i][j] - '1';
                if (checkerRow[i] & (1 << current)) return false;

                checkerRow[i] |= (1 << current);
            }
        }
        checkerRow.assign(9, 0);
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if (board[i][j]=='.') continue;
                int current = board[i][j] - '1';
                if (checkerRow[j] & (1 << current)) return false;

                checkerRow[j] |= (1 << current);
                // cout << "i: " << i << ", j: " << j << ", checker[i]: " << checker[i];
            }
        }
        checkerRow.assign(9, 0);
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if (board[i][j]=='.') continue;
                int current = board[i][j] - '1';
                if (checkerRow[(i/3)*3 + j/3] & (1 << current)) return false;
                checkerRow[(i/3)*3 + j/3] |= (1 << current);
                // cout << "i: " << i << ", j: " << j << ", checker[i]: " << checker[i];
            }
        }
        return true;
    }
};
