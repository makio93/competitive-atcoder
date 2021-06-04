#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力AC

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> vcnt((int)(1e5), -1);
    int now = n;
    vcnt[n] = k;
    while (k) {
        int tmp = now;
        while (tmp > 0) {
            now += tmp % 10;
            tmp /= 10;
        }
        now = now % (int)(1e5);
        --k;
        if (vcnt[now] != -1LL) {
            ll roop = vcnt[now] - k;
            k %= roop;
            break;
        }
        else vcnt[now] = k;
    }
    while (k) {
        int tmp = now;
        while (tmp > 0) {
            now += tmp % 10;
            tmp /= 10;
        }
        now = now % (int)(1e5);
        --k;
    }
    cout << now << endl;
    return 0;
}
