// 本番WA2

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
	int w;
	cin >> w;
	vector<int> res;
	res = { 1, 2, 4 };
	int val = 4;
	rep(i, 297) {
		val += 3;
		res.push_back(val);
	}
	int n = res.size();
	cout << n << endl;
	rep(i, n) printf("%d%c", res[i], (i<n-1?' ': '\n'));
	return 0;
}
