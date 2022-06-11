#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
vector<int> adj[maxn];

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    a--; b--;

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        
        x--; y--;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // primero hacemos un BFS desde el nodo b
    // para sacar la distancia desde cualquier otro nodo
    // al nodo b
    vector<int> d(n, 999999);

    queue<int> q;

    d[b] = 0;
    q.push(b);

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(int y : adj[x]) if(d[y] == 999999) {
            d[y] = d[x] + 1;
            q.push(y);
        }
    }

    // ahora hacemos otro BFS desde el nodo a
    // para ir imprimiendo todas las aristas
    // que estén en un camino de longitud mínima
    vector<bool> visited(n, false);
    vector<pair<int,int> > aristas;

    visited[a] = true;
    q.push(a);

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(int y : adj[x]) if(d[y] == d[x] - 1) {
            aristas.push_back(make_pair(x, y));
            if(visited[y] == false) {
                visited[y] = true;
                q.push(y);
            }
        } 
    }

    cout << aristas.size() << endl;

    for(pair<int,int> arista : aristas) {
        cout << arista.first + 1 << " " << arista.second + 1 << endl;
    }

    return 0;
}
