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

int fact(int n)
{
    int ans = 1;
    rep3r(i, 1, n+1) ans *= i;
    return ans;
}

int main(){
    int n, a = 0, b = 0;
    cin >> n;
    vector<int> p, q;
    rep(i, n) {
        int d, s;
        cin >> d;
        p.push_back(d);
        if (i == n-1) break;
        s = d - 1;
        rep(j, i) {
            if (p[j] < d) s--;
        }
        a += s * fact(n-1-i);
    }
    rep(i, n) {
        int d, s;
        cin >> d;
        q.push_back(d);
        if (i == n-1) break;
        s = d - 1;
        rep(j, i) {
            if (q[j] < d) s--;
        }
        b += s * fact(n-1-i);
    }
    cout << abs(a-b) << endl;
    return 0;
}

