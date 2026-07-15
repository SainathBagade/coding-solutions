class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int result = 0;
        vector<int> prefixXor;
        prefixXor.push_back(0);
        int Xor = 0;
        for (int i = 0; i < arr.size(); i++) {
            Xor ^= arr[i];
            prefixXor.push_back(Xor);
        }

        for (int i = 0; i < prefixXor.size() - 1; i++) {
            for (int k = i + 1; k < prefixXor.size(); k++) {
                if (prefixXor[i] == prefixXor[k]) {
                    result += (k - i - 1);
                }
            }
        }
        return result;
    }
};