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
