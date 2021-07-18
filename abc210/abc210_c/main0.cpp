#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> c(n);
	rep(i, n) cin >> c[i];
	map<int, int> ccnt;
	rep(i, k) ccnt[c[i]]++;
	int res = ccnt.size();
	rep3(i, k, n) {
		ccnt[c[i]]++;
		ccnt[c[i-k]]--;
		if (ccnt[c[i-k]] == 0) ccnt.erase(c[i-k]);
		res = max(res, (int)(ccnt.size()));
	}
	cout << res << endl;
	return 0;
}
