// 自力TLE(ヒント有)

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using l3 = __int128_t;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const l3 LINF = (l3)(2e18);

int main() {
    int n;
    ll th;
    l3 h;
    cin >> n >> th;
    h = th;
    vector<int> t(n), d(n);
    rep(i, n) cin >> t[i] >> d[i];
    unordered_map<int, int> dtd;
    rep(i, n) dtd[t[i]] = max(dtd[t[i]], d[i]);
    vector<pair<int, int>> td;
    for (const auto& pi : dtd) td.emplace_back(pi.first, pi.second);
    sort(all(td));
    n = td.size();
    l3 lv = 0, rv = h + 1;
    while (rv-lv > 1) {
        l3 cv = rv - (rv - lv) / 2, val = 0;
        bool is_big = false;
        priority_queue<int> dpq;
        multiset<pair<l3, int>> tdst;
        int id = n - 1;
        while (id>=0 && td[id].first>=cv) {
            dpq.push(td[id].second);
            --id;
        }
        rep(i, id+1) tdst.emplace((l3)td[i].first*td[i].second, td[i].second);
        l3 sub = cv;
        repr(i, id+1) {
            if (!dpq.empty() && !tdst.empty() && (l3)dpq.top()*sub>tdst.rbegin()->first) {
                l3 cs = tdst.rbegin()->first / dpq.top();
                if (cs > td[i].first) {
                    l3 aval = (l3)(sub - cs) * (dpq.top() * sub + dpq.top() * (cs + 1)) / 2, bval = (l3)(cs - td[i].first) * tdst.rbegin()->first;
                    if (aval>=h || bval>=h || val+aval>=h || val+aval+bval>=h) {
                        is_big = true;
                        break;
                    }
                    val += aval + bval;
                }
                else {
                    l3 aval = (l3)(sub - td[i].first) * (dpq.top() * sub + dpq.top() * (td[i].first+1)) / 2;
                    if (aval>=h || val+aval>=h) {
                        is_big = true;
                        break;
                    }
                    val += aval;
                }
            }
            else if (!dpq.empty() && !tdst.empty()) {
                l3 aval = (l3)(sub - td[i].first) * (dpq.top() * sub + dpq.top() * (td[i].first + 1)) / 2, bval = (l3)(sub - td[i].first) * tdst.rbegin()->first;
                if (aval>=h || bval>=h || val+aval>=h || val+bval>=h) {
                    is_big = true;
                    break;
                }
                val += (aval >= bval) ? aval : bval;
            }
            else if (dpq.empty()) {
                l3 aval = (l3)(sub - td[i].first) * tdst.rbegin()->first;
                if (aval>=h || val+aval>=h) {
                    is_big = true;
                    break;
                }
                val += aval;
            }
            else {
                l3 aval = (l3)(sub - td[i].first) * (dpq.top() * sub + dpq.top() * (td[i].first + 1)) / 2;
                if (aval>=h || val+aval>=h) {
                    is_big = true;
                    break;
                }
                val += aval;
            }
            sub = td[i].first;
            tdst.erase(tdst.lower_bound({ (l3)td[i].first*td[i].second, td[i].second }));
            dpq.push(td[i].second);
            if (is_big || val >= h) break;
        }
        if (!is_big && val<h) {
            l3 aval = (l3)sub * (dpq.top() * sub + dpq.top()) / 2;
            if (aval>=h || val+aval>=h) {
                is_big = true;
            }
            else val += aval;
        }
        if (is_big || val >= h) rv = cv;
        else lv = cv;
    }
    cout << (ll)(rv) << endl;
    return 0;
}
