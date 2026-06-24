class Solution {
public:

    vector<int> parent;

    int find(int node) {
        if(parent[node] == node) {
            return node;
        }

        return find(parent[node]);
    }

    bool dsu(int u, int v) {
        int rootu = find(u);
        int rootv = find(v);

        if(rootu == rootv) {
            return true;
        }

        parent[rootv] = rootu;
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        parent = vector<int>(n + 1);

        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for(auto &it: edges) {
            int u = it[0];
            int v = it[1];

            if(dsu(u, v)) {
                return it;
            }
        }

        return {};
    }
};