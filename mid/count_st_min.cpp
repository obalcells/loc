#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
#define ll long long int
#define oo 1e18
pair<ll,int> t[4*MAXN];

#define num first
#define freq second

pair<ll, int> combinar(pair<ll, int> l, pair<ll, int> r) {
    if(l.num < r.num) return l;
    else if(l.num == r.num) return make_pair(l.num, l.freq + r.freq);
    else return r;
}

void build(vector<ll>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_pair(a[tl], 1);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = combinar(t[v * 2], t[v * 2 + 1]);
    }
}

pair<ll, int> minimo(int v, int tl, int tr, int l, int r) {
    if (l > tr || r < tl) {
        return make_pair(oo, 1); // devolvemos infinito
    }
    if (l <= tl && tr <= r) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return combinar(minimo(v * 2,         tl, tm, l, r),
                    minimo(v * 2 + 1, tm + 1, tr, l, r));
}

void update(int v, int tl, int tr, int pos, ll new_val) {
    if (tl == tr) {
        t[v] = make_pair(new_val, 1);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(v * 2,         tl, tm, pos, new_val);
        } else {
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        }
        t[v] = combinar(t[v * 2], t[v * 2 + 1]);
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<ll> a(n);

    // leemos la array
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    build(a, 1, 0, n - 1);

    // ahora ejecutamos las queries
    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if(t == 1) {
            int p;
            ll x;
            cin >> p >> x;
            p--;
            a[p] = x;
            update(1, 0, n - 1, p, x);
        } else if(t == 2) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            pair<ll, int> ans = minimo(1, 0, n - 1, l, r);
            cout << ans.num << " " << ans.freq << endl;
        }
    }
}

