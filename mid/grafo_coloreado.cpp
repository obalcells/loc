#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
vector<pair<int, int> > adj[maxn];
bool visited[maxn][3];
pair<int,int> p[maxn][3]; // esta array la utilizamos para recuperar el camino

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b, color;
        cin >> a >> b >> color;

        // queremos que todos los índices empiecen en el 0
        a--; b--;
        color--;

        adj[a].push_back(make_pair(b, color));
        adj[b].push_back(make_pair(a, color));
    }

    for(int i = 0; i < n; i++) {
        visited[i][0] = false;
        visited[i][1] = false;
        visited[i][2] = false;
    }

    queue<pair<int,int> > q;

    visited[0][0] = true;
    visited[0][1] = true;
    visited[0][2] = true;

    q.push(make_pair(0, 0));
    q.push(make_pair(0, 1));
    q.push(make_pair(0, 2));

    bool found = false;

    while(!q.empty() && !found) {
        int a = q.front().first;
        int color = q.front().second;

        q.pop();

        for(pair<int, int> edge : adj[a]) {
            int b = edge.first;
            int color2 = edge.second;

            if(color != color2 && !visited[b][color2]) {
                p[b][color2] = make_pair(a, color);
                visited[b][color2] = true;
                q.push(make_pair(b, color2));

                if(b == (n - 1)) {
                    found = true;
                    break;
                }
            }
        }
    }

    if(!found) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

        // vamos a meter los nodos en path y luego lo vamos a reversear y a imprimir
        vector<int> path;

        // ahora toca imprimir el camino
        int a = n - 1;

        // cual es el color de la arista que hemos utilizado para llegar al último nodo?
        int color;

        if(visited[a][0] == true) color = 0;
        else if(visited[a][1] == true) color = 1;
        else if(visited[a][2] == true) color = 2;

        while(a != 0) {
            // siempre sumamos 1 antes de imprimir
            // porque le hemos restado 1 a todos los nodos antes
            path.push_back(a + 1);
            
            // cual es el nodo anterior en el camino?
            int b = p[a][color].first; 

            // cual es el color de la arista que hemos utilizado para llegar al nodo b?
            color = p[a][color].second;

            // damos un paso para atrás en el camino volviendo al nodo a
            a = b;

            // seguimos con el while loop... hasta llegar al nodo 0
        }

        path.push_back(a + 1);

        // invertimos el camino y lo imprimimos
        reverse(path.begin(), path.end());

        cout << path.size() << endl;

        for(int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Notas:
// 3 estados para visited
// la array p para poder recuperar el camino
// marcamos visited como true antes de ponerlo en la cola
//  - la otra alternativa es más lenta
//  necesitamos un par para poder recuperar el camino

