class Solution {
public:

    vector<bool> visited;
    vector<vector<int>> graph;

    void dfs(int node, int parent) {
        visited[node] = true;

        for(int nei: graph[node]) {
            if(nei == parent) {
                continue;
            }
            if(visited[nei]) {
                continue;
            }
            dfs(nei, node);
        }

        return;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        visited = vector<bool>(n, false);
        graph = vector<vector<int>>(n);

        for(auto &it: edges) {
            int node1 = it[0];
            int node2 = it[1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                count++;
                dfs(i, -1);
            }
        }

        return count;
    }
};
