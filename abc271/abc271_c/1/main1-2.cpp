// 学習1回目,解説AC2

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

const int INF = (int)(1.1e9);

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    unordered_map<int, int> acnt;
    rep(i, n) acnt[a[i]]++;
    int lv = 0, rv = n+1;
    while (rv-lv > 1) {
        int cv = lv + (rv-lv) / 2;
        int sub = cv, add = 0;
        for (const auto& pi : acnt) {
            if (pi.first <= cv) {
                --sub;
                add += pi.second - 1;
            }
            else add += pi.second;
        }
        if (sub <= add/2) lv = cv;
        else rv = cv;
    }
    cout << lv << endl;
    return 0;
}
