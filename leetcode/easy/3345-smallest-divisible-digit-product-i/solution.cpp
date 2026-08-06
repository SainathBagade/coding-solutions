class Solution {
public:
    int solve(int i){
        int prod=1;
        while(i > 0){
            int digit=i%10;
            i/=10;
            prod*=digit;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
    for(int i=n;i<=100;i++){

        int product=solve(i);
        if(product % t ==0){
            return i;
        }
    }
    return -1;
    }
};