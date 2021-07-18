#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
	int n;
	string s;
	cin >> n >> s;
	int res = 0;
	rep(i, n) if (s[i] == '1') {
		res = i % 2;
		break;
	}
	if (res == 0) cout << "Takahashi" << endl;
	else cout << "Aoki" << endl;
	return 0;
}
