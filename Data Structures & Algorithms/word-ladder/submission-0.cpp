class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int length = beginWord.length();
        unordered_set<string> us;

        for(auto word: wordList) {
            us.insert(word);
        }

        if(!us.count(endWord)) {
            return 0;
        }
        if(us.count(beginWord)) {
            us.erase(beginWord);
        }

        queue<string> q;
        q.push(beginWord);
        int count = 1;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();
                for(int i = 0; i < length; i++) {
                    string newWord = word;
                    for(char c = 'a'; c <= 'z'; c++) {
                        newWord[i] = c;
                        if(us.count(newWord)) {
                            if(newWord == endWord) {
                                return count + 1;
                            }
                            q.push(newWord);
                            us.erase(newWord);
                        }
                    }
                }
            }       
            count++;
        }

        return 0;
    }
};
