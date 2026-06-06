class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(auto it: strs) {
            s.append(to_string(it.length()));
            s.append("#");
            s.append(it);
        }
        cout << s;
        return s;
    }

    vector<string> decode(string s) {
        vector<string> answer;
        int i = 0;
        string length;
        while(i < s.length()) {
            if(s[i] != '#') {
                length += s[i];
                i++;
            }
            if(s[i] == '#') {
                int len = stoi(length);
                answer.push_back(s.substr(i+1, len));
                length = "";
                i += len + 1;
            }
        }
        return answer;
    }
};
