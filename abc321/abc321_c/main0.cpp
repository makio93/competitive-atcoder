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
	int k;
	cin >> k;
	++k;
	string s;
	function<bool(int, int)> dfs = [&](int di, int vi) {
		if (di == 1) {
			if (k > vi+1) {
				k -= vi + 1;
				return false;
			}
			else {
				s.push_back((char)(k-1+'0'));
				return true;
			}
		}
		else {
			rep3(i, 1, vi+1) {
				s.push_back((char)(i+'0'));
				if (dfs(di-1, i-1)) return true;
				s.pop_back();
			}
			return false;
		}
	};
	rep3(i, 1, 11) if (dfs(i, 9)) break;
	cout << s << endl;
	return 0;
}
