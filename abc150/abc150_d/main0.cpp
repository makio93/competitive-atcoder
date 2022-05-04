// 

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

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) a[i] /= 2;
    ll s = a[0];
    rep3(i, 1, n) s = lcm(s, a[i]);
    bool ok = true;
    rep(i, n) if ((s/a[i])%2==0) ok = false;
    if (!ok) cout << 0 << endl;
    else {
        cout << (((m/s)+1)/2) << endl;
    }
    return 0;
}
