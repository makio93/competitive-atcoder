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

// 解答を見てから実装、AC

int main() {
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
    rep(i, n) a[i] += i;
    rep(i, n) b[i] += i;
    auto a2 = a, b2 = b;
    sort(all(a2)); sort(all(b2));
    bool ok = true;
    rep(i, n) if (a2[i] != b2[i]) ok = false;
    if (!ok) {
        cout << -1 << endl;
        return 0;
    }
    map<ll, deque<int>> bcnt;
    rep(i, n) bcnt[b[i]].push_back(i);
    vector<int> s(n);
    rep(i, n) {
        s[i] = bcnt[a[i]].front();
        bcnt[a[i]].pop_front();
    }
    ll res = 0;
    deque<int> used;
    repr(i, n) {
        auto ditr = lower_bound(all(used), s[i]);
        res += ditr - used.begin();
        used.insert(ditr, s[i]);
    }
    cout << res << endl;
    return 0;
}
