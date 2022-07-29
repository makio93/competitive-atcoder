// 復習2回目,解説AC

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
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int mlen = max(x, y), res = INF;
    rep(i, mlen+1) res = min(res, c*2*i+a*max(0,x-i)+b*max(0,y-i));
    cout << res << endl;
    return 0;
}
