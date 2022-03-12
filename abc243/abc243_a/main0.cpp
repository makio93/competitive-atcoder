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

int main() {
	int v;
	vector<int> vals(3);
	cin >> v;
	rep(i, 3) cin >> vals[i];
	int sum = 0;
	rep(i, 3) sum += vals[i];
	v %= sum;
	const string tar = "FMT";
	rep(i, 3) {
		if (v < vals[i]) {
			cout << tar[i] << endl;
			return 0;
		}
		v -= vals[i];
	}
	return 0;
}
