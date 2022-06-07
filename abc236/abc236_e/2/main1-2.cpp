// 解説AC2

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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int mval = 0;
    rep(i, n) mval = max(mval, a[i]);
    auto bf = [&]<typename T>(vector<T>& b) -> T {
        T p = 0, v = 0;
        rep(i, n) {
            T t = max(p, v) + b[i];
            p = v;
            v = t;
        }
        return max(p, v);
    };
    auto check1 = [&](double th) -> bool {
        vector<double> b(n);
        rep(i, n) b[i] = a[i] - th;
        return bf(b) >= 0.0;
    };
    auto check2 = [&](int th) -> bool {
        vector<int> b(n);
        rep(i, n) b[i] = (a[i] >= th) ? 1 : -1;
        return bf(b) > 0;
    };
    auto search1 = [&](double li, double hi) -> double {
        while ((hi-li)/hi > 1e-3) {
            double ci = sqrt(li*hi);
            if (check1(ci)) li = ci;
            else hi = ci;
        }
        return li;
    };
    auto search2 = [&](int li, int hi) -> int {
        while (hi-li > 1) {
            int ci = li + (hi-li) / 2;
            if (check2(ci)) li = ci;
            else hi = ci;
        }
        return li;
    };
    cout << fixed << setprecision(12) << search1(1.0, (double)mval+1) << endl;
    cout << search2(1, mval+1) << endl;
    return 0;
}
