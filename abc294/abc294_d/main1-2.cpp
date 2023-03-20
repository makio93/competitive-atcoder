// 解説AC2

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
	vector<bool> finished(n);
	int nval = 0;
	rep(i, q) {
		int qi;
		cin >> qi;
		if (qi == 2) {
			int xi;
			cin >> xi;
			--xi;
			finished[xi] = true;
		}
		else if (qi == 3) {
			while (finished[nval]) ++nval;
			cout << (nval+1) << endl;
		}
	}
	return 0;
}
