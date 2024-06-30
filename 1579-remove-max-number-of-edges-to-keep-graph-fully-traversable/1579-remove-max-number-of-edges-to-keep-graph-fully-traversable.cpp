class Solution {
public:
    int find(vector<int>& parents, int x) 
    {
        if (parents[x] != x) 
        {
            parents[x] = find(parents, parents[x]);
        }
        return parents[x];
    }

    void unionNodes(vector<int>& parents, int x, int y) 
    {
        int root_x = find(parents, x);
        int root_y = find(parents, y);
        if (root_x != root_y) 
        {
            parents[root_x] = root_y;
        }
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> parent_a(n + 1);
        vector<int> parent_b(n + 1);
        for (int i = 1; i <= n; ++i) 
        {
            parent_a[i] = i;
            parent_b[i] = i;
        }

        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });

        int removed_edges = 0;

        for (const auto& edge : edges)
        {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (type == 3) 
            {
                bool aliceConnected = find(parent_a, u) != find(parent_a, v);
                bool bobConnected = find(parent_b, u) != find(parent_b, v);
                if (aliceConnected || bobConnected) 
                {
                    unionNodes(parent_a, u, v);
                    unionNodes(parent_b, u, v);
                } 
                else
                {
                    ++removed_edges;
                }
            }
        }

        for (const auto& edge : edges) 
        {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (type == 1) 
            {
                if (find(parent_a, u) != find(parent_a, v)) 
                {
                    unionNodes(parent_a, u, v);
                } 
                else 
                {
                    ++removed_edges;
                }
            } else if (type == 2) 
            {
                if (find(parent_b, u) != find(parent_b, v)) 
                {
                    unionNodes(parent_b, u, v);
                } 
                else 
                {
                    ++removed_edges;
                }
            }
        }

        int alice = 0;
        int bob = 0;
        for (int i = 1; i <= n; ++i) 
        {
            if (find(parent_a, i) == i) 
            {
                ++alice;
            }
            if (find(parent_b, i) == i) 
            {
                ++bob;
            }
        }

        if (alice == 1 && bob == 1) 
        {
            return removed_edges;
        } 
        else 
        {
            return -1;
        }
    }
};