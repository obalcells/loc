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
            p[b] = a;
            q.push(b);
        } 
    }

    if(d[f] == -1) {
        cout << 0 << endl;
    } else {
        cout << d[f] << endl;        
    }

    p[s] = -1;

    a = f;

    while(a != -1) {
        a = p[a];
    }

    // 2 -> 7 -> 6 -> 3
    //
    // p[3] = 6
    // p[6] = 7
    // p[7] = 2
    // p[2] = -1
    
    return 0;
}
