# Valid Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.

 

 **Example 1:** 

 **Input:**  s = "()"

 **Output:**  true

 **Example 2:** 

 **Input:**  s = "()[]{}"

 **Output:**  true

 **Example 3:** 

 **Input:**  s = "(]"

 **Output:**  false

 **Example 4:** 

 **Input:**  s = "([])"

 **Output:**  true

 **Example 5:** 

 **Input:**  s = "([)]"

 **Output:**  false

 

 **Constraints:** 

- 1 <= s.length <= 104
- s consists of parentheses only '()[]{}'.

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 9.35%)  
**Memory:** 10.1 MB (beats 6.20%)  
**Submitted:** 2026-10-01T01:47:30.500Z  

```cpp
#include <string>
#include<stack>
using namespace std;

class Solution {
public:
stack<int>st;
    bool isValid(string s) {
      for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch=='{' || ch=='[' || ch=='('){
            st.push(ch);
        }else{
            if(st.empty()){
                return false;
            }
                int top=st.top();
                if((ch=='}' && top=='{') ||
                ( ch==']' && top=='[') ||
                ( ch==')' && top=='(')){
                    st.pop();
                }else{
                    return false;
                }
        }
      }
        return st.empty();
      }
    
};

```

---

[View on LeetCode](https://leetcode.com/problems/valid-parentheses/)