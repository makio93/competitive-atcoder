// 自力,WA2

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

int main() {
    int ax, ay, bx, by, n;
    cin >> ax >> ay >> bx >> by >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    int dx = ay - by, dy = bx - ax;
    int dcnt = 0;
    rep(i, n) if (((ll)dy*(y[i]-ay)+(ll)dx*(x[i]-ax)>0) != ((ll)dy*(y[(i+1)%n]-ay)+(ll)dx*(x[(i+1)%n]-ax)>0)) ++dcnt;
    int res = 1 + dcnt / 2;
    cout << res << endl;
    return 0;
}
