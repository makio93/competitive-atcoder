// 復習1回目,自力AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int op(int a, int b) { return min(a, b); }
int e() { return INF; }

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<pair<int, int>> alst(n);
    rep(i, n) alst[i] = { a[i], i };
    sort(all(alst), greater<pair<int, int>>());
    ll sum = 0;
    rep(i, n/2) sum += alst[i].first;
    vector<int> acnt(n*2, 1), asum(n*2+1);
    rep(i, n/2) acnt[alst[i].second] = -1;
    rep(i, n) acnt[i+n] = acnt[i];
    rep(i, n*2) asum[i+1] = asum[i] + acnt[i];
    segtree<int, op, e> mst(n*2+1);
    rep(i, n*2+1) mst.set(i, asum[i]);
    int ki = -1;
    rep(i, n) {
        if (mst.prod(i+1,i+n+1)-asum[i] >= 0) {
            ki = i;
            break;
        }
    }
    cout << ki << ' ' << sum << endl;
    return 0;
}
