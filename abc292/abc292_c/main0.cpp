// 本番AC

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
	vector<int> ccnt(n+1);
	rep3(i, 1, n+1) for (int j=i; j<=n; j+=i) ccnt[j]++;
	ll res = 0;
	rep3(i, 1, n) res += (ll)ccnt[i] * ccnt[n-i];
	cout << res << endl;
	return 0;
}
