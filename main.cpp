#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int to;
    int weight;
};

vector<int> bounded_multi_source_shortest_path(
    const vector<vector<Edge>>& adjacency_list,
    const vector<int>& source_nodes,
    int max_distance
) {
    int num_nodes = adjacency_list.size();
    vector<int> min_distance(num_nodes, numeric_limits<int>::max());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;

    for (int source : source_nodes) {
        min_distance[source] = 0;
        min_heap.push({0, source});
    }

    while (!min_heap.empty()) {
        auto [current_dist, current_node] = min_heap.top();
        min_heap.pop();

        if (current_dist > max_distance) continue;

        if (current_dist > min_distance[current_node]) continue;

        for (const auto& edge : adjacency_list[current_node]) {
            int new_dist = current_dist + edge.weight;

            if (new_dist < min_distance[edge.to] && new_dist <= max_distance) {
                min_distance[edge.to] = new_dist;
                min_heap.push({new_dist, edge.to});
            }
        }
    }

    return min_distance;
}

int main() {

    int num_nodes = 6;
    vector<vector<Edge>> adjacency_list(num_nodes);

    adjacency_list[0].push_back({1, 2});
    adjacency_list[1].push_back({0, 2});

    adjacency_list[1].push_back({2, 4});
    adjacency_list[2].push_back({1, 4});

    adjacency_list[0].push_back({3, 1});
    adjacency_list[3].push_back({0, 1});

    adjacency_list[3].push_back({4, 3});
    adjacency_list[4].push_back({3, 3});

    adjacency_list[4].push_back({5, 2});
    adjacency_list[5].push_back({4, 2});

    vector<int> source_nodes = {0, 2};

    int max_distance = 5;

    vector<int> result = bounded_multi_source_shortest_path(adjacency_list, source_nodes, max_distance);

    for (int i = 0; i < num_nodes; i++) {
        if (result[i] == numeric_limits<int>::max())
            cout << "Nodo " << i << ": Inalcanzable dentro del límite" << endl;
        else
            cout << "Nodo " << i << ": " << result[i] << endl;
    }

    return 0;
}
