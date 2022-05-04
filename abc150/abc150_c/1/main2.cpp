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

int fact(int n) {
    if (n == 0) return 0;
    int ans = 1;
    rep3r(i, 1, n+1) ans *= i;
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];
    int a = 0, b = 0;
    set<int> up, uq;
    rep(i, n) {
        int uNum = p[i] - 1;
        int uTmpNum = uNum;
        rep3(j, 1, uTmpNum+1) {
            if (up.find(j)!=up.end()) --uNum;
        }
        a += uNum * fact((n-1)-i);
        up.insert(p[i]);
    }
    rep(i, n) {
        int uNum = q[i] - 1;
        int uTmpNum = uNum;
        rep3(j, 1, uTmpNum+1) {
            if (uq.find(j)!=uq.end()) --uNum;
        }
        b += uNum * fact((n-1)-i);
        uq.insert(q[i]);
    }
    cout << abs(a-b) << endl;
    return 0;
}
