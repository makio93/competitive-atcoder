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

const int mval = 55555;

int main() {
    int n;
    cin >> n;
	vector<bool> sieve(mval+1);
    vector<int> res;
	for (int i=2; i<=mval; ++i) if (!sieve[i]) {
        if (i%5 == 1) res.push_back(i);
        if ((int)(res.size()) >= n) break;
		for (int j=i*2; j<=mval; j+=i) sieve[j] = true;
	}
    rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
    return 0;
}
