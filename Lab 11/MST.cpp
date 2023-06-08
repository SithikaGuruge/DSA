#include <iostream>
#include<vector>
using namespace std;

int getMinVertex(int n,bool vis[],int dist[]) {
    int minVertex = -1;
    for(int i=0;i<n;i++) {
        if(!vis[i] && (minVertex == -1 || dist[i] < dist[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

int prims(int src,bool vis[],int dist[],vector<vector<int>> adj,int MAX,int parent[]) {
    fill(dist, dist+MAX, INT_MAX);
    dist[src] = 0;
    parent[src] = -1;

    for(int i=0;i<MAX;i++) {
        int u = getMinVertex(MAX,vis,dist);
        vis[u] = true;

        for(int v=0;v<MAX;v++) {
            if(adj[u][v]!=0 && !vis[v] && dist[v] > adj[u][v]) {
                dist[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }

    int minCost = 0;
    for(int i=0;i<MAX;i++) {
        if(vis[i])
            minCost += dist[i];
    }
    return minCost;
}

void printMST(vector<vector<int>> adj, int parent[], int MAX) {
    cout << "Edges of minimum spanning tree: "<<endl;
    for(int i=1; i<MAX; i++) {
        if(parent[i] != -1) {
            cout << parent[i] << " - " << i << endl;
        }
    }
}

int main() {
    int MAX = 6;
    vector<vector<int>> adj = {{0, 3, 0, 0, 0,1},
                               {3, 0, 2, 1, 10,0},
                               {0, 2, 0, 3, 0,5},
                               {0, 1, 3, 0, 5,0},
                               {0, 10, 0, 5, 0,4},
                               {1, 0, 5, 0, 4, 0}};

    bool vis[MAX];
    int dist[MAX], parent[MAX];

    fill(vis, vis+MAX, false);

    int minCost = prims(0, vis, dist, adj, MAX, parent);
    cout<<"Minimum cost of MST: "<<minCost<<endl;

    printMST(adj, parent, MAX);

    return 0;
}
