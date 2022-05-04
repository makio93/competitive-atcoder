// 学習0回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int my_binary_search(vector<int>& pp, int v) {
    int l = 0, r = pp.size();
    while (r - l > 0) {
        int c = (r + l) / 2;
        if (pp[c] == v) return c;
        if (pp[c] < v) l = c + 1;
        else r = c;
    }
    return r - 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n+1);
    rep3(i, 1, n+1) cin >> p[i];
    vector<int> pp((n+1)*(n+1));
    rep(i, n+1) rep(j, n+1) pp[i*(n+1)+j] = p[i] + p[j];
    sort(all(pp));
    int mx = 0;
    rep(a, n+1) rep(b, n+1) {
        int s = m - p[a] - p[b];
        if (s < 0) continue;
        int d = my_binary_search(pp, s);
        mx = max(mx, p[a] + p[b] + pp[d]);
    }
    cout << mx << endl;
    return 0;
}
