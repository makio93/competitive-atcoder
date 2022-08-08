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

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	p[0] = -1;
	rep3(i, 1, n) {
		cin >> p[i];
		p[i]--;
	}
	vector<int> dp(n);
	rep3(i, 1, n) dp[i] = dp[p[i]] + 1;
	cout << dp[n-1] << endl;
	return 0;
}
