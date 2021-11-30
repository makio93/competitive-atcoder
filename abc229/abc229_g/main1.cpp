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

// 解説AC

const ll INF = (ll)(1e18);

int main() {
	string s;
	ll k;
	cin >> s >> k;
	int n = s.length();
	vector<int> b;
	rep(i, n) if (s[i] == 'Y') b.push_back(i-(int)(b.size()));
	int m = b.size();
	vector<ll> sum(m+1);
	rep(i, m) sum[i+1] = sum[i] + b[i];
	int l = 0, r = m;
	while (r-l > 0) {
		int c = l + (r-l+1)/2;
		ll kval = INF;
		rep(j, m-c+1) {
			kval = min(kval, abs((ll)b[j+c/2]*(c/2+1)-(sum[j+c/2+1]-sum[j]))+abs((ll)b[j+c/2]*(c-c/2-1)-(sum[j+c]-sum[j+c/2+1])));
		}
		if (kval <= k) l = c;
		else r = max(c-1, l);
	}
	cout << l << endl;
	return 0;
}
