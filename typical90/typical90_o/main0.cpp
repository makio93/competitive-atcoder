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

// 自力で解答、わからない

using mint = modint1000000007;

int main() {
	int n;
	cin >> n;
	mint aval = mint(2).pow(n) - 1;
	rep(i, n) {
		if (i == 0) cout << aval.val() << endl;
		else {
			mint sub = (mint(2).pow(n-i)-1) * mint(2).pow(i-1);
			cout << (aval-sub).val() << endl;
		}
	}
	return 0;
}
