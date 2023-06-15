// 学習2回目,自力WA2

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

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    if (count(all(s), '1') != count(all(t), '1')) {
        cout << -1 << endl;
        return 0;
    }
    int res = INF;
    {
        auto ts = s;
        set<int> zrs;
        rep(i, n) if (ts[i] == '0') zrs.insert(i);
        int val = 0;
        rep(i, n) if (ts[i] != t[i]) {
            if (ts[i] == '1') {
                int ri = *zrs.upper_bound(i);
                swap(ts[i], ts[ri]);
                zrs.insert(i);
                zrs.erase(ri);
                ++val;
            }
            else {
                auto ritr = zrs.upper_bound(i);
                int ri = ritr == zrs.end() ? n-1 : *ritr - 1;
                swap(ts[i], ts[ri]);
                zrs.insert(ri);
                zrs.erase(i);
                ++val;
            }
        }
        res = val;
    }
    {
        auto ts = s;
        reverse(all(ts));
        reverse(all(t));
        set<int> zrs;
        rep(i, n) if (ts[i] == '0') zrs.insert(i);
        int val = 0;
        rep(i, n) if (ts[i] != t[i]) {
            if (ts[i] == '1') {
                int ri = *zrs.upper_bound(i);
                swap(ts[i], ts[ri]);
                zrs.insert(i);
                zrs.erase(ri);
                ++val;
            }
            else {
                auto ritr = zrs.upper_bound(i);
                int ri = ritr == zrs.end() ? n-1 : *ritr - 1;
                swap(ts[i], ts[ri]);
                zrs.insert(ri);
                zrs.erase(i);
                ++val;
            }
        }
        res = min(res, val);
    }
    cout << res << endl;
    return 0;
}
