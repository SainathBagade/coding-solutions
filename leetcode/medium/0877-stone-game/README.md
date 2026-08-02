# Stone Game

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Alice and Bob play a game with piles of stones. There are an  **even**  number of piles arranged in a row, and each pile has a  **positive**  integer number of stones `piles[i]`.

The objective of the game is to end with the most stones. The  **total**  number of stones across all the piles is  **odd**, so there are no ties.

Alice and Bob take turns, with  **Alice starting first**. Each turn, a player takes the entire pile of stones either from the  **beginning**  or from the  **end**  of the row. This continues until there are no more piles left, at which point the person with the  **most stones wins**.

Assuming Alice and Bob play optimally, return `true` *if Alice wins the game, or* `false` *if Bob wins*.

 

 **Example 1:** 

```
Input: piles = [5,3,4,5]
Output: true
Explanation: 
Alice starts first, and can only take the first 5 or the last 5.
Say she takes the first 5, so that the row becomes [3, 4, 5].
If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alice, so we return true.

```

 **Example 2:** 

```
Input: piles = [3,7,2,3]
Output: true

```

 

 **Constraints:** 

- 2 <= piles.length <= 500
- piles.length is even.
- 1 <= piles[i] <= 500
- sum(piles[i]) is odd.

## Solution

**Language:** C++  
**Runtime:** 8 ms (beats 31.43%)  
**Memory:** 11.4 MB (beats 37.34%)  
**Submitted:** 2026-08-02T06:04:48.308Z  

```cpp
class Solution {
public:
int t[501][501];
 int solve(int i,int j,vector<int>&piles){

        if(i > j) return 0;
        if(i==j) return piles[i];

        if(t[i][j] != -1) return t[i][j];

        int take_i=piles[i] + min(solve(i+2,j,piles),solve(i+1,j-1,piles));

         int take_j=piles[j] + min(solve(i,j-2,piles),solve(i+1,j-1,piles));

         return t[i][j]=max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
          int n=piles.size();
         memset(t,-1,sizeof(t));
        int total_sum=accumulate(piles.begin(),piles.end(),0);

        int player1=solve(0,n-1,piles);

        int player2=total_sum - player1;

        return player1 >= player2;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/stone-game/)