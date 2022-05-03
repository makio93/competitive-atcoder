// 学習0回目,自力,WA

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
    int min_t = 1001001001;
    int common = min(x, y), extra = max(x, y) - common;
    int commonA = a * common, commonB = b * common, commonAB = commonA + commonB;
    int commonC = c * common * 2;
    int extraAB = extra * (x>y?a:b), extraC = extra * c * 2;
    int total = commonAB + extraAB;
    min_t = min(min_t, total);
    total = commonAB + extraC;
    min_t = min(min_t, total);
    total = commonC + extraAB;
    min_t = min(min_t, total);
    total = commonC + extraC;
    min_t = min(min_t, total);
    cout << total << endl;
    return 0;
}

