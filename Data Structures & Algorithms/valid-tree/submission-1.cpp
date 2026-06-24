class Solution {
public:

    vector<bool> visited;
    int count = 0;
    vector<vector<int>> graph;
    int num;

    bool dfs(int node, int parent) {
        if(count == num) {
            return false;
        }

        count++;
        visited[node] = true;

        for(int nei: graph[node]) {

            if(nei == parent) {
                continue;
            }

            if(visited[nei]) {
                return true;
            }

            if(dfs(nei, node)) {
                return true;
            }
        }
        
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        visited = vector<bool>(n, false);
        graph = vector<vector<int>>(n);
        num = n;

        for(auto it: edges) {
            int node1 = it[0];
            int node2 = it[1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }

        if(dfs(0, -1)) {
            return false;
        }

        return count == n;
    }
};
