// 学習0回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main(){
    int m;
    cin >> m;
    int c = 1000 - m;
    const vector<int> v = { 500, 100, 50, 10, 5, 1 };
    int ans = 0;
    for (int i : v) {
        int t = c / i;
        c -= t * i;
        ans += t;
    }
    cout << ans << endl;
    return 0;
}
