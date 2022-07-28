// 解説AC

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

int main() {
    int n;
    cin >> n;
    vector<int> pi(n), ii(n);
    rep(i, n) {
        cin >> pi[i];
        pi[i]--;
    }
    rep(i, n) {
        cin >> ii[i];
        ii[i]--;
    }
    vector<int> iids(n);
    rep(i, n) iids[ii[i]] = i;
    vector<pair<int, int>> res(n, { -1, -1 });
    auto calc = [&](auto calc, int pli, int ili, int len) -> int {
        if (len<0 || pli+len>n || ili+len>n) return -2;
        else if (len == 0) return -1;
        else if (len == 1) {
            if (pi[pli] != ii[ili]) return -2;
            res[pi[pli]].first = res[pi[pli]].second = -1;
            return pi[pli];
        }
        else {
            int rid = iids[pi[pli]];
            if (rid<ili || rid>=ili+len) return -2;
            int llen = rid-ili, rlen = len - llen - 1;
            res[pi[pli]].first = calc(calc, pli+1, ili, llen);
            if (res[pi[pli]].first == -2) return -2;
            res[pi[pli]].second = calc(calc, pli+llen+1, ili+llen+1, rlen);
            if (res[pi[pli]].second == -2) return -2;
            return pi[pli];
        }
    };
    if (calc(calc, 0, 0, n) != 0) cout << -1 << endl;
    else rep(i, n) cout << (res[i].first+1) << ' ' << (res[i].second+1) << endl;
    return 0;
}
