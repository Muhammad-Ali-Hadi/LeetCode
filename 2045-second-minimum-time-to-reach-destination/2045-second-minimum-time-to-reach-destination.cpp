class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n + 1);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<vector<int>> dist(n + 1, vector<int>(2, INT_MAX));
        dist[1][0] = 0;

        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 1});

        while (!pq.empty()) {
            auto [current_time, u] = pq.top();
            pq.pop();

            for (int v : graph[u]) {
                int travel_time = current_time;
                if ((travel_time / change) % 2 == 1) {
                    travel_time = (travel_time / change + 1) * change;
                }
                travel_time += time;

                if (travel_time < dist[v][0]) {
                    dist[v][1] = dist[v][0];
                    dist[v][0] = travel_time;
                    pq.push({travel_time, v});
                } else if (travel_time > dist[v][0] && travel_time < dist[v][1]) {
                    dist[v][1] = travel_time;
                    pq.push({travel_time, v});
                }
            }
        }

        return dist[n][1];
    }
};