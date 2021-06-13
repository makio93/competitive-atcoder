#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

int main() {
    ll n;
    cin >> n;
    map<ll, int> fib;
    ll val = 1, pre = 0;
    int cnt = 0;
    while (val <= n) {
        fib[val] = cnt;
        ll tmp = val + pre;
        pre = val;
        val = tmp;
        ++cnt;
    }
    int mc = fib.rbegin()->second;
    n -= fib.rbegin()->first;
    vector<int> add;
    for (auto itr=fib.rbegin(); itr!=fib.rend(); ++itr) {
        if (itr->second == mc) continue;
        if (n == 0) break;
        if (n >= itr->first) {
            n -= itr->first;
            add.push_back(itr->second);
        }
    }
    vector<int> res;
    int bi = mc % 2, ai = 0, adlen = add.size();
    rep(i, mc+1) {
        if (i%2 == 0) {
            if (i == 0) res.push_back(bi+1);
            else res.push_back(bi+3);
        }
        else res.push_back(4-bi);
        if (ai<adlen && add[ai]==mc-i) {
            res.push_back(((i%2)+bi)%2+1);
            ++ai;
        }
    }
    int k = res.size();
    cout << k << endl;
    rep(i, k) cout << res[i] << endl;
    return 0;
}
