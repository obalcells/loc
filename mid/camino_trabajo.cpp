#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
vector<int> adj[maxn];

void bfs(int a, vector<int>& d) {
    d.assign(maxn, 999999);

    queue<int> q;
    d[a] = 0;
    q.push(a);

    while(!q.empty()) {
        a = q.front();
        q.pop();

        for(int b : adj[a]) {
            if(d[b] != 999999) {
                continue;
            }
            d[b] = d[a] + 1;
            q.push(b);
        }
    }
}

int main() {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;

    a--; b--; c--;

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> d1(n), d2(n), d3(n);

    bfs(a, d1);
    bfs(b, d2);
    bfs(c, d3);

    int min_path_length = 999999;

    for(int i = 0; i < n; i++) {
        if(d1[i] + d2[i] + d3[i] < min_path_length) {
            min_path_length = d1[i] + d2[i] + d3[i];
        }
    }

    cout << min_path_length << endl;

    return 0;
}
