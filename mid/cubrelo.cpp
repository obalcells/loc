#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
vector<int> adj[maxn];

int main() {
    int t;
    cin >> t;

    for(int tt = 1; tt <= t; tt++) {
        int n, m;
        cin >> n >> m;

        for(int i = 0; i < n; i++) {
            adj[i].clear();
        }

        for(int i = 0; i < m; i++) {
            int v, u;
            cin >> v >> u;

            v--; u--;

            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        vector<int> color(n, -1);

        // pintamos el vertice 0 de color 0
        color[0] = 0;

        // hacemos un bfs para pintar el resto del grafo
        queue<int> q;

        q.push(0);

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int v : adj[u]) if(color[v] == -1) {
                // explicar esto ->
                color[v] = color[u] == 0 ? 1 : 0; 
                q.push(v);
            }
        }

        int n_ceros = 0;
        int n_unos = 0;
        for(int i = 0; i < n; i++) {
            if(color[i] == 0) n_ceros++;
            else n_unos++;
        }

        if(n_ceros < n_unos) {
            cout << n_ceros << endl;
            for(int i = 0; i < n; i++) if(color[i] == 0) {
                cout << i + 1 << " ";
            }
            cout << endl;
        } else {
            cout << n_unos << endl;
            for(int i = 0; i < n; i++) if(color[i] == 1) {
                cout << i + 1 << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
