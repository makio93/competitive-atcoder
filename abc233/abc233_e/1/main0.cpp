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

int main() {
    string x;
    cin >> x;
    int n = x.length();
    vector<int> sum(n+1);
    rep(i, n) sum[i+1] = sum[i] + x[i] - '0';
    string res;
    rep3r(i, 1, n+1) {
        sum[i-1] += sum[i] / 10;
        sum[i] %= 10;
        res += (char)(sum[i] + '0');
    }
    if (sum[0] > 0) {
        string left = to_string(sum[0]);
        reverse(all(left));
        res += left;
    }
    reverse(all(res));
    cout << res << endl;
    return 0;
}
