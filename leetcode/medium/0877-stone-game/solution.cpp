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