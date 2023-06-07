// 学習1回目,解説AC

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
    int n, m;
    cin >> n >> m;
    vector<int> a(n*2);
    rep(i, n*2) cin >> a[i];
    unordered_map<int, int> acnt;
    rep(i, n*2) acnt[a[i]]++;
    bool even = true;
    for (const auto& pi : acnt) if (pi.second%2 != 0) even = false;
    if (even) cout << "Bob" << endl;
    else if (m%2 != 0) cout << "Alice" << endl;
    else {
        int bcnt = 0, ocnt = 0;
        for (const auto& pi : acnt) if (pi.second%2 != 0) {
            ++ocnt;
            if (pi.first+m/2 >= m) continue;
            if (acnt.find(pi.first+m/2) == acnt.end() || acnt[pi.first+m/2]%2 == 0) {
                cout << "Alice" << endl;
                return 0;
            }
            bcnt += 2;
        }
        if (ocnt == bcnt && bcnt/2%2 == 0) cout << "Bob" << endl;
        else cout << "Alice" << endl;
    }
    return 0;
}
