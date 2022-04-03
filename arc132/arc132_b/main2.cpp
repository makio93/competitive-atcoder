// 復習,解説2

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
    cin >> n;
    deque<int> p(n);
    rep(i, n) cin >> p[i];
    int res = INF;
    rep(i, 2) rep(j, 2) {
        auto tp = p;
        int cnt = 0;
        if (i) {
            reverse(all(tp));
            ++cnt;
        }
        while ((tp[0]!=1||tp[n-1]!=n) && (tp[0]!=n||tp[n-1]!=1)) {
            int tmp = tp[0];
            tp.pop_front();
            tp.push_back(tmp);
            ++cnt;
        }
        if (j) {
            reverse(all(tp));
            ++cnt;
        }
        if (tp[0]==1 && tp[n-1]==n) res = min(res, cnt);
    }
    cout << res << endl;
    return 0;
}
