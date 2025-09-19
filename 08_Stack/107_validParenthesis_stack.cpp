#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack <char>st;

        for(int i = 0; i<s.length(); i++){
            char ch = s[i];

            if(ch=='(' || ch == '[' || ch == '{'){
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    char top = st.top();
                    if( ( ch == ')' && top == '(' ) || ( ch == ']' && top == '[' ) || ( ch == '}' && top == '{' ) ){
                        st.pop();
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }

        if(st.empty()){
            return true;
        }else{
            return false;
        }
    }
};

int main() {
    Solution sol;
    string input;

    cout << "Enter a string of brackets: ";
    cin >> input;

    if (sol.isValid(input)) {
        cout << "Valid bracket sequence.\n";
    } else {
        cout << "Invalid bracket sequence.\n";
    }

    return 0;
}