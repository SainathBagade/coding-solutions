# Game of Life

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

According to Wikipedia's article: "The  **Game of Life**, also known simply as  **Life**, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an `m x n` grid of cells, where each cell has an initial state:  **live**  (represented by a `1`) or  **dead**  (represented by a `0`). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

- Any live cell with fewer than two live neighbors dies as if caused by under-population.
- Any live cell with two or three live neighbors lives on to the next generation.
- Any live cell with more than three live neighbors dies, as if by over-population.
- Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the `m x n` grid `board`. In this process, births and deaths occur  **simultaneously**.

Given the current state of the `board`,  **update**  the `board` to reflect its next state.

 **Note**  that you do not need to return anything.

 

 **Example 1:** 

```
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

```

 **Example 2:** 

```
Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]

```

 

 **Constraints:** 

- m == board.length
- n == board[i].length
- 1 <= m, n <= 25
- board[i][j] is 0 or 1.

 

 **Follow up:** 

- Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
- In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.7 MB (beats 11.62%)  
**Submitted:** 2026-08-20T06:21:38.820Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/game-of-life/)