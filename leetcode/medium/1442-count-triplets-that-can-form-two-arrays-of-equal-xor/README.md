# Count Triplets That Can Form Two Arrays of Equal XOR

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of integers `arr`.

We want to select three indices `i`, `j` and `k` where `(0 <= i < j <= k < arr.length)`.

Let's define `a` and `b` as follows:

- a = arr[i] ^ arr[i + 1] ^... ^ arr[j - 1]
- b = arr[j] ^ arr[j + 1] ^... ^ arr[k]

Note that  **^**  denotes the  **bitwise-xor**  operation.

Return  *the number of triplets*  (`i`, `j` and `k`) Where `a == b`.

 

 **Example 1:** 

```
Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)

```

 **Example 2:** 

```
Input: arr = [1,1,1,1,1]
Output: 10

```

 

 **Constraints:** 

- 1 <= arr.length <= 300
- 1 <= arr[i] <= 108

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 10.3 MB (beats 59.21%)  
**Submitted:** 2026-07-15T11:38:54.250Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/)