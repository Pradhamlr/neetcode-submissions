class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for(auto it: tokens) {
            if(it == "+" || it == "*" || it == "/" || it == "-") {
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                int res;
                
                if(it == "+") {       
                    res = b + a;
                }
                else if(it == "*") {
                    res = b * a;
                }
                else if(it == "/") {
                    res = b / a;
                }
                else if(it == "-") {
                    res = b - a;
                }
                st.push(to_string(res));
            }
            else {
                st.push(it);
            }
        }

        return stoi(st.top());
    }
};
