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
    int sum = 0, carry = 0;
    rep(i, n) sum += x[i] - '0';
    string res;
    repr(i, n) {
        carry += sum;
        res.push_back(carry%10+'0');
        sum -= x[i] - '0';
        carry /= 10;
    }
    while (carry > 0) {
        res.push_back(carry%10+'0');
        carry /= 10;
    }
    reverse(all(res));
    cout << res << endl;
    return 0;
}
