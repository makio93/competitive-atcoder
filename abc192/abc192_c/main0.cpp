// 本番AC

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

int main(){
    ll n;
    int k;
    cin >> n >> k;
    ll ai = n;
    rep(i, k) {
        string si = to_string(ai);
        string g1 = si, g2 = si;
        sort(g1.rbegin(), g1.rend());
        sort(all(g2));
        ai = (ll)(stoll(g1) - stoll(g2));
    }
    cout << ai << endl;
    return 0;
}
