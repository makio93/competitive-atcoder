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
	string s;
	cin >> s;
	vector<int> ccnt(26);
	for (char ci : s) ccnt[ci-'a']++;
	bool ok = false;
	char res = ' ';
	rep(i, 26) if (ccnt[i] == 1) {
		ok = true;
		res = (char)(i+'a');
		break;
	}
	if (ok) cout << res << endl;
	else cout << -1 << endl;
	return 0;
}
