class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // int n = source.size();
        // if (n != target.size()) return -1;

        // unordered_map<char, vector<pair<char, int>>> graph;
        // for (int i = 0; i < original.size(); ++i) {
        //     graph[original[i]].emplace_back(changed[i], cost[i]);
        // }

        // auto dijkstra = [&](int start,int end) -> int {
        //     if (start == end) 
        //     return 0;
        //     unordered_map<char, int> minCost;
        //     priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
        //     pq.emplace(0, start);

        //     while (!pq.empty()) {
        //         auto [currentCost, currentChar] = pq.top();
        //         pq.pop();

        //         if (currentChar == end) return currentCost;

        //         if (minCost.find(currentChar) != minCost.end() && currentCost > minCost[currentChar]) continue;

        //         minCost[currentChar] = currentCost;

        //         for (auto& [nextChar, weight] : graph[currentChar]) {
        //             int newCost = currentCost + weight;
        //             if (minCost.find(nextChar) == minCost.end() || newCost < minCost[nextChar]) {
        //                 minCost[nextChar] = newCost;
        //                 pq.emplace(newCost, nextChar);
        //             }
        //         }
        //     }
        //     return INT_MAX;
        // };

        // long long totalCost = 0;
        // for (int i = 0; i < n; ++i) {
        //     if (source[i] != target[i]) {
        //         int cost = dijkstra(source[i], target[i]);
        //         if (cost == INT_MAX) return -1;
        //         totalCost += cost;
        //     }
        // }
        // return totalCost;

        int n = source.size();
        if (n != target.size()) return -1;

        vector<vector<int>> dist(128, vector<int>(128, INT_MAX));

        for (int i = 0; i < original.size(); ++i) {
            dist[original[i]][changed[i]] = cost[i];
        }

        for (int i = 0; i < 128; ++i) {
            dist[i][i] = 0;
        }

        for (int k = 0; k < 128; ++k) {
            for (int i = 0; i < 128; ++i) {
                for (int j = 0; j < 128; ++j) {
                    if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long totalCost = 0;
        for (int i = 0; i < n; ++i) {
            if (source[i] != target[i]) {
                int cost = dist[source[i]][target[i]];
                if (cost == INT_MAX) return -1;
                totalCost += cost;
            }
        }
        return totalCost;
    }
};