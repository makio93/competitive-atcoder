// 解説AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using l3 = __int128;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

l3 asum(l3 a, l3 d, l3 n) { return (a * 2 + (n-1) * d) * n / 2; }

const int INF = (int)(1e9);
ll search(ll tlv, ll trv, ll dv, ll hv) {
    ll tok = tlv, tng = trv;
    while (tng-tok > 1) {
        ll tcv = tok + (tng-tok) / 2;
        l3 tval = asum(tok*dv, dv, tcv-tok);
        if (tval < hv) {
            hv -= tval;
            tok = tcv;
        }
        else tng = tcv;
    }
    return tok;
};

int main() {
    int n;
    ll h;
    cin >> n >> h;
    vector<pair<int, int>> td(n);
    rep(i, n) cin >> td[i].first >> td[i].second;
    sort(all(td));
    multiset<int> dst;
    rep(i, n) dst.insert(td[i].second);
    dst.insert(0);
    ll l = 1, tdv = 0;
    rep(i, n+1) {
        ll r = i < n ? td[i].first : l+h+1;
        function<bool(ll,ll)> calc = [&](ll lv, ll rv) {
            ll dv = *dst.rbegin(), ok = lv-1, ng = rv;
            while (ng-ok > 1) {
                ll cv = ok + (ng-ok) / 2;
                if (tdv < dv*cv) ng = cv;
                else ok = cv;
            }
            l3 val1 = (l3)(ng-lv) * tdv;
            if (val1 >= h) {
                ll res = lv + (h - 1) / tdv;
                cout << res << endl;
                return true;
            }
            h -= val1;
            l3 val2 = asum(ng*dv, dv, rv-ng);
            if (val2 >= h) {
                ll res = search(ng, rv, dv, h);
                cout << res << endl;
                return true;
            }
            h -= val2;
            return false;
        };
        if (calc(l, r)) break;
        dst.erase(dst.find(td[i].second));
        tdv = max(tdv, (ll)td[i].first*td[i].second);
        l = r;
    }
    return 0;
}
