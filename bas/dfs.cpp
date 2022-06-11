#include <bits/stdc++.h>
using namespace std;
const int maxn = 107;
vector<int> adj[maxn];

int main() {
    int n, s, f;
    cin >> n >> s >> f;

    s--; f--;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if(x == 1) {
                adj[i].push_back(j);
            }
        }
    }

    queue<int> q;
    vector<int> d(n, -1);

    q.push(s);
    d[s] = 0;

    while(!q.empty()) {
        int a = q.front();
        q.pop();
        for(int b : adj[a]) if(d[b] == -1) {
            d[b] = d[a] + 1;
            q.push(b);
        } 
    }

    if(d[f] == -1) {
        cout << 0 << endl;
    } else {
        cout << d[f] << endl;        
    }
    
    return 0;
}
