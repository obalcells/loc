#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

// https://cp-algorithms.com/graph/dijkstra.html
void dijkstra(int s, vector<int>& d, vector<int>& p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    // nodo i
    // d[i] = INF
    // => todavía no sabemos si hay alguun camino para llegar a i

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        /* Esto se puede mejorar: */
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }
        // el siguiente nodo que vamos a relajar
        // es el nodo con d[nodo] mínimo que todavía
        // no hayamos relajado
        /**************************/

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }

    // (d[i] == INF) == true
    // => NO hay ningún camino para llegar a i
}

int main() {
    int s;

    vector<int> distancias;
    vector<int> p;

    dijkstra(s, distancias, p);

    return 0;
}

