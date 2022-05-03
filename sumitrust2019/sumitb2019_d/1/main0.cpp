// 学習1回目,自力AC

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
	int n;
	string s;
	cin >> n >> s;
	int res = 0;
	rep(i, 1000) {
		vector<char> tar;
		int tmp = i;
		rep(j, 3) {
			tar.push_back((char)(tmp%10+'0'));
			tmp /= 10;
		}
		int id = 0;
		rep(j, n) if (s[j] == tar[id]) {
			++id;
			if (id == 3) break;
		}
		if (id == 3) ++res;
	}
	cout << res << endl;
	return 0;
}
