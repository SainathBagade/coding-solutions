class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>temp(nums.size(),0);
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            temp[i]+=maxi;
        }

         for(int i=nums.size()-1;i>=0;i--){
            mini=min(mini,nums[i]);
            temp[i]-=mini;
        }

        for(int i=0;i<temp.size();i++){
            if(temp[i] <= k) return i;
        }

        return -1;
    }
};