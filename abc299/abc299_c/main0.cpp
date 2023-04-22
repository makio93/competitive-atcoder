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
	int ocnt = count(all(s), 'o');
	if (ocnt==0 || ocnt==n) {
		cout << -1 << endl;
		return 0;
	}
	int res = 0, cnt = 0;
	rep(i, n) {
		if (s[i] == 'o') ++cnt;
		else cnt = 0;
		res = max(res, cnt);
	}
	cout << res << endl;
	return 0;
}
