#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC(解答例を見てから作成)

unordered_map<ll, int> memo;
int f(ll n) {
    if (memo.find(n) != memo.end()) return memo[n];
    if (n == 0LL) return (memo[0] = 0);
    ll q = n / 10; int r = (int)(n % 10);
    int res = 5;
    rep3(i, 1, 5) {
        if (r>=i && r<=min(9,i*3) && f(q)<=i) res = i;
        else if (i*3>=10 && r>=0 && r<=i*3-10 && f(q-1)<=i) res = i;
        if (res != 5) break;
    }
    return (memo[n] = res);
}

int main() {
    int t;
    cin >> t;
    rep(i0, t) {
        ll n;
        cin >> n;
        cout << f(n) << endl;
    }
    return 0;
}
