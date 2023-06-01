#include <iostream>
#include <vector>

using namespace std;

const int INF = INT_MAX;

int dijkstra(vector<vector<int>>& graph, int start, int end) {
    vector<int> dist(graph.size(), INF);
    vector<bool> visited(graph.size(), false);

    dist[start] = 0;

    for (int i = 0; i < graph.size(); ++i) {
        int u = -1;
        for (int j = 0; j < graph.size(); ++j) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == INF) {
            break;
        }

        visited[u] = true;

        for (int v = 0; v < graph.size(); ++v) {
            if (graph[u][v] != INF && !visited[v]) {
                int alt = dist[u] + graph[u][v];
                if (alt < dist[v]) {
                    dist[v] = alt;
                }
            }
        }
    }

    return dist[end] == INF ? -1 : dist[end];
}

int main() {
    vector<vector<int>> graph = {{0,10,INF,INF,15,5},
                                 {10,0,10,30,INF,INF},
                                 {INF,10,0,12,5,INF},
                                 {INF,30,12,0,INF,20},
                                 {15,INF,5,INF,0,INF},
                                 {5,INF,INF,20,INF,0}};

    for(int i=0;i<6;i++){
        cout<<"Start Node: "<<i<<endl;
        for(int j=0;j<6;j++){
            if(i!=j){
                int shortest_dist = dijkstra(graph, i, j);
                cout<<"Start: "<< i<<" End: "<<j<<" Shortest Time Taken: "<<shortest_dist<<endl;
            }
        }
    }

    return 0;
}
