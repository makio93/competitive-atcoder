// 本番WA

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

const ll LINF = (ll)(1e18);

ll calc(string xi, ll mi) {
    if (mi <= 0) return 0;
    int len = (int)(xi.length());
    if (len == 1) {
        if (stoll(xi) > mi) return 0;
        else return LINF;
    }
    if ((xi.front()-'0') == 0) return calc(xi.substr(1), mi);
    ll sval = (ll)(pow((double)mi/((int)(xi.front()-'0')), (double)1.0/(len-1)))+10;
    while (sval > 0) {
        ll res = calc(xi.substr(1), mi-(ll)(pow(sval,len-1))*(xi.front()-'0'));
        if (sval <= res) return sval;
        --sval;
    }
    return 0;
}

int main(){
    string x;
    ll m;
    cin >> x >> m;
    if ((int)(x.length()) == 1) {
        if ((ll)(x.front()-'0') <= m) cout << 1 << endl;
        else cout << 0 << endl;
    }
    else {
        ll res = calc(x, m);
        int mval = 0;
        rep(i, x.length()) mval = max(mval, (int)(x[i]-'0'));
        cout << max(0LL, res-mval) << endl;
    }
    return 0;
}
