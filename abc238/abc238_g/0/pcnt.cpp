// 素数の個数カウント
// n==(1e6)でpi==(8e4)くらい
// だいたいO(n/log(n))個くらいにはなる感覚

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    int n = (int)(1e6);
    vector<bool> unprime(n+1);
    unprime[0] = unprime[1] = true;
    for (int i=2; i*i<=n; ++i) if (!unprime[i]) {
        for (int j=i*2; j<=n; j+=i) unprime[j] = true;
    }
    vector<int> plst;
    for (int i=2; i<=n; ++i) if (!unprime[i]) plst.push_back(i);
    int m = plst.size();
    cout << m << endl;
    return 0;
}
