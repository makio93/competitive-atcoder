// 本番WA

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
	int n, q;
	string s;
	cin >> n >> q >> s;
	vector<int> sub(n), sum(n);
	rep3(i, 1, n) {
		if (s[i] == s[i-1]) {
			sub[i] = sub[i-1];
			sum[i] = sum[i-1];
		}
		else {
			int li = (s[i-1]-'A'), ri = (s[i]-'A');
			if (ri == (li+1)%3) sub[i] = sub[i-1] + 1;
			else sub[i] = sub[i-1] - 1;
			sum[i] = sum[i-1] + 1;
		}
	}
	rep(i, q) {
		int li, ri;
		cin >> li >> ri;
		--li; --ri;
		int val1 = abs(sub[ri]-sub[li]), val2 = sum[ri] - sum[li];
		int res = (val2-val1) / 2;
		if (val1 <= 1) res += val1;
		else res += 1 + (val1 / 2);
		res = min(res, 1+val1/2+((val2-val1)/2)/2*2);
		cout << res << endl;
	}
	return 0;
}
