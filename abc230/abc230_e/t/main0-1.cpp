// 練習1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    ll n;
    cin >> n;
    ll rn = max(1LL, (ll)sqrt(n));
    ll lmx = n / rn;
    ll sum = 0;
    for (ll i=1; i<=lmx; ++i) sum += n / i;
    for (ll i=rn-1; i>=1; --i) {
        ll cnt = (n / i) - (n / (i+1));
        sum += i * cnt;
    }
    cout << sum << endl;
    return 0;
}
