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

const int INF = (int)(1e9);

int main() {
	string s;
	cin >> s;
	int n = s.length();
	auto check = [&](int li, int ri) -> bool {
		while (li < ri) {
			if (s[li] != s[ri]) return false;
			++li; --ri;
		}
		return true;
	};
	if (check(0, n-1) && check(0, n/2-1)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
