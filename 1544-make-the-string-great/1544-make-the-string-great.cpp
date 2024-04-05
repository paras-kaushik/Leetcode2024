class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(char& c:s){
            if(!st.empty () &&
               (char)tolower(c) == (char)towlower(st.top()) &&
               c!=st.top())
            {
                st.pop();
            }else{
                st.push(c);
            }
        }
        string ans;
        while (!st.empty()) {
            ans=st.top()+ans;
            st.pop();
        }
        
        return ans;
    }
};