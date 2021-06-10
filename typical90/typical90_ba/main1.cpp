#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

vector<int> fib(int n) {
    int v = 1, p = 0;
    vector<int> res;
    while (v <= n) {
        int t = v + p;
        res.push_back(t);
        p = v; v = t;
    }
    return res;
}

int query(vector<int>& val, int v) {
    if (val[v] != -1) return val[v];
    cout << "? " << v << endl;
    int res; cin >> res;
    if (res == -1) exit(0);
    return (val[v] = res);
}

int main() {
    int t;
    cin >> t;
    rep(i1, t) {
        int n;
        cin >> n;
        auto fl = fib(n);
        int m1 = fl.size(), m2 = fl.back();
        vector<int> val(m2+1, -1);
        val[0] = -2;
        rep3(i, n+1, m2+1) val[i] = -i;
        int res = 0;
        int l = 0, r = m2;
        for (int i=m1-1; i-2>=0; --i) {
            int len = fl[i-2];
            int cl = l + len, cr = r - len;
            int vl = query(val, cl), vr = query(val, cr);
            res = max({res, vl, vr});
            if (vl <= vr) l = cl;
            else r = cr;
        }
        rep3(i, l, r+1) res = max(res, query(val, i));
        cout << "! " << res << endl;
    }
    return 0;
}
