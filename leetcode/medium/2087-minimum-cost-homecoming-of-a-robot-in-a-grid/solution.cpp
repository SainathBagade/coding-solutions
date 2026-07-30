class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int result=0;

            int r1=startPos[0];
            int c1=startPos[1];

            int r2=homePos[0];
            int c2=homePos[1];

            if(r1 <= r2){
                for(int i=r1+1;i<=r2;i++){
                    result+=rowCosts[i];
                }
            }else{
                 for(int i=r1-1;i>=r2;i--){
                    result+=rowCosts[i];
                }
            }
                
        if(c2 >= c1){
                for(int i=c1+1;i<=c2;i++){
                    result+=colCosts[i];
                }
        }else{
             for(int i=c1-1;i>=c2;i--){
                    result+=colCosts[i];
                }
        }
               
            

        return result;
    }
};