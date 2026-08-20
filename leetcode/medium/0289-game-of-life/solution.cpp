class Solution {
public:
    void solveZero(vector<vector<int>>& board, vector<vector<int>>& orignal,
                   int currentRow, int currentCol) {
        int cnt = 0;
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr == 0 && dc == 0)
                    continue;
                int neighborRow = currentRow + dr;
                int neighborCol = currentCol + dc;

                if (neighborRow >= 0 && neighborRow < orignal.size() &&
                    neighborCol >= 0 && neighborCol < orignal[0].size() &&
                    orignal[neighborRow][neighborCol] == 1)
                    cnt++;
            }
        }

        if (cnt == 3)
            board[currentRow][currentCol] = 1;
    }

    void solveOne(vector<vector<int>>& board, vector<vector<int>>& orignal,
                  int currentRow, int currentCol) {
        int cnt = 0;
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr == 0 && dc == 0)
                    continue;
                int neighborRow = currentRow + dr;
                int neighborCol = currentCol + dc;

                if (neighborRow >= 0 && neighborRow < orignal.size() &&
                    neighborCol >= 0 && neighborCol < orignal[0].size() &&
                    orignal[neighborRow][neighborCol] == 1)
                    cnt++;
            }
        }
        if (cnt == 2 || cnt == 3)
            board[currentRow][currentCol] = 1;
        else
            board[currentRow][currentCol] = 0;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> orignal = board;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0) {
                    solveZero(board, orignal, i, j);
                } else if (board[i][j] == 1) {
                    solveOne(board, orignal, i, j);
                }
            }
        }
    }
};