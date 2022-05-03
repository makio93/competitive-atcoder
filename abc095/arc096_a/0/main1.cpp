// 学習0回目,解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int min = 1001001001;
    rep(k, 100101) {
        int total = 2 * c * k + a * max(x - k, 0) + b * max(y - k, 0);
        min = (total < min) ? total : min;
    }
    cout << min << endl;
    return 0;
}

