class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> result, arr1, arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int n = nums.size();
        int i = 2;

        while (i < n) {
            cout<<"ends "<<arr1.back()<<"--"<<arr2.back()<<endl;
            if (arr1.back() > arr2.back()) {
                cout << "first" << nums[i] << endl;
                arr1.push_back(nums[i]);

            } else {
                arr2.push_back(nums[i]);
                cout << "second" << nums[i] << endl;
            }
            i++;
        }

        result = arr1;
        for (auto it : arr2)
            result.push_back(it);
        return result;
    }
};