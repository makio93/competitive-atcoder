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
	vector<int> ng(3);
	rep(i, 3) cin >> ng[i];
	if (find(all(ng), n) != ng.end()) {
		cout << "NO" << endl;
		return 0;
	}
	int cnt = 0, val = n;
	while (val) {
		int sub = 3;
		while (sub>0 && (val-sub<0||find(all(ng),val-sub)!=ng.end())) --sub;
		if (sub == 0) break;
		val -= sub;
		++cnt;
	}
	if (val==0 && cnt<=100) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
