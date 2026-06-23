class Solution {
public:

    vector<bool> path;
    vector<bool> visited;
    vector<vector<int>> graph;

    bool dfs(int node) {
        if(path[node] == true) {
            return true;
        }

        if(visited[node]) {
            return false;
        }

        visited[node] = true;
        path[node] = true;

        for(int nei: graph[node]) {
            if(dfs(nei) == true) {
                return true;
            }
        }

        path[node] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        path = vector<bool>(numCourses, false);
        visited = vector<bool>(numCourses, false);
        graph = vector<vector<int>>(numCourses);

        for(auto it: prerequisites) {
            int course = it[0];
            int preReq = it[1];

            graph[preReq].push_back(course);
        }

        for(int i = 0; i < numCourses; i++) {
            if(dfs(i) == true) {
                return false;
            }
        }

        return true;
    }
};