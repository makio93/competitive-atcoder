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
	string s;
	cin >> n >> s;
	vector<int> bcnt(2);
	ll res = 0;
	rep(i, n) {
		vector<int> ncnt(2);
		if (s[i] == '0') {
			ncnt[1] += bcnt[0] + bcnt[1];
			ncnt[0]++;
		}
		else {
			ncnt[0] += bcnt[1];
			ncnt[1] += bcnt[0];
			ncnt[1]++;
		}
		swap(ncnt, bcnt);
		res += bcnt[1];
	}
	cout << res << endl;
	return 0;
}
