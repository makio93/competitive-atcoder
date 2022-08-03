// 解説AC

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
    int dcnt = 0;
    auto check = [&](int id) -> bool {
        if (((bx-ax)*(y[id]-ay)-(by-ay)*(x[id]-ax)>0)==((bx-ax)*(y[(id+1)%n]-ay)-(by-ay)*(x[(id+1)%n]-ax)>0)) return false;
        if (((x[(id+1)%n]-x[id])*(ay-y[id])-(ax-x[id])*(y[(id+1)%n]-y[id])>0)==((x[(id+1)%n]-x[id])*(by-y[id])-(bx-x[id])*(y[(id+1)%n]-y[id])>0)) return false;
        return true;
    };
    rep(i, n) if (check(i)) ++dcnt;
    int res = 1 + dcnt / 2;
    cout << res << endl;
    return 0;
}
