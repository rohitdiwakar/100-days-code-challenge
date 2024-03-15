class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                if(s[i]==')' || s[i]=='}' || s[i]==']')return false;
            }
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else if(st.top()=='(' && s[i]==')' || st.top()=='{' && s[i]=='}'|| st.top()=='[' && s[i]==']' ){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        if(st.empty())return true;
        return false;
    }
};