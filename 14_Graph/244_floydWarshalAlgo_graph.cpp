#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> &dist) {
    int n = dist.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] == 1e8 || dist[k][j] == 1e8) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Check for negative cycle
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative cycle detected\n";
            return;
        }
    }
}

int main() {
    int INF = 1e8;  // large value representing infinity
    int n = 4;      // number of vertices

    // Manually define adjacency matrix
    vector<vector<int>> dist = {
        {0,   3,   INF, 7},
        {8,   0,   2,   INF},
        {5,   INF, 0,   1},
        {2,   INF, INF, 0}
    };

    cout << "Initial matrix:"<<endl;
    for (auto &row : dist) {
        for (auto &val : row) {
            if (val == INF) cout << "INF";
            else cout <<val<< " ";
        }
        cout << "\n";
    }

    floydWarshall(dist);

    cout << "\nShortest distance matrix:"<<endl;
    for (auto &row : dist) {
        for (auto &val : row) {
            if (val==INF) cout << "INF ";
            else cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}