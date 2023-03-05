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
	int n, q;
	cin >> n >> q;
	vector<int> ccnt(n);
	rep(i, q) {
		int ci, xi;
		cin >> ci >> xi;
		--xi;
		if (ci == 1) {
			ccnt[xi]++;
			if (ccnt[xi] >= 2) ccnt[xi] = -1;
		}
		else if (ci == 2) ccnt[xi] = -1;
		else {
			if (ccnt[xi] == -1) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}
