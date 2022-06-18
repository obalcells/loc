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

    // defino la cola
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, s));

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        // saco el elemento más grande y lo borro de la cola
        pair<int, int> par = pq.top();
        pq.pop();

        // en que nodo estoy?
        int v = par.second;

        // comprobar que no lo haya relajado ya
        if(u[v] == true)
            continue;

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                // metemos un nuevo par en la cola de prioridades
                pq.push(make_pair(-d[to], to));
            }
        }
    }
}

int main() {
    int s;

    vector<int> distancias;
    vector<int> p;

    dijkstra(s, distancias, p);

    return 0;
}

