class Solution {
public:

    vector<bool> visited;
    vector<bool> path;
    vector<vector<int>> graph;
    vector<int> answer;

    bool dfs(int node) {
        if(path[node]) {
            return true;
        }
        if(visited[node]) {
            return false;
        }

        visited[node] = true;
        path[node] = true;

        for(int nei: graph[node]) {
            if(dfs(nei)) {
                return true;
            }
        }

        answer.push_back(node);
        path[node] = false;

        return false;
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        visited = vector<bool>(numCourses, false);
        path = vector<bool>(numCourses, false);
        graph = vector<vector<int>>(numCourses);

        for(auto &it: prerequisites) {
            int course = it[0];
            int preReq = it[1];

            graph[preReq].push_back(course);
        }

        for(int i = 0; i < numCourses; i++) {
            if(dfs(i)) {
                return {};
            }
        }
        reverse(answer.begin(), answer.end());

        return answer;
    }
};