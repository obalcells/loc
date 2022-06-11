#include <bits/stdc++.h>
using namespace std;
const int maxn = 1007;
int t[maxn][maxn]; // t[i][j] = cuando se empieza a quemar el árbol en (i, j)
char s[maxn][maxn]; // s[i][j] = '.' or '#'
int n, m; // n y m son variables globales

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '.';
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        string fila;
        cin >> fila;
        for(int j = 0; j < m; j++) {
            s[i][j] = fila[j]; 
            t[i][j] = -1;
        }
    }
    
    int k;
    cin >> k;
    
    queue<pair<int,int> > q; 

    for(int i = 0; i < k; i++) {
        int x, y; 
        cin >> x >> y;
        x--; y--;
        q.push(make_pair(x, y));
        t[x][y] = 0; 
    }

    int max_t = 0;
    vector<pair<int,int> > movements = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(pair<int,int> m : movements) {
            int x2 = x + m.first;
            int y2 = y + m.second;
            if(!valid(x2, y2)) {
                continue;
            }
            if(t[x2][y2] == -1) {
                t[x2][y2] = t[x][y] + 1;
                max_t = max(max_t, t[x2][y2]);
                q.push(make_pair(x2, y2));
            }
        }
    }

    vector<pair<int, int> > ans;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(t[i][j] == max_t) {
                ans.push_back(make_pair(i, j)); 
            }
        }
    }

    cout << ans.size() << endl;

    for(pair<int,int> p : ans) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }

    return 0;
}
