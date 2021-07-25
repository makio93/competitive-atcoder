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

const vector<string> tar = { "H", "2B", "3B", "HR" };

int main() {
	vector<string> s(4);
	rep(i, 4) cin >> s[i];
	vector<int> cnt(4);
	rep(i, 4) rep(j, 4) if (s[i] == tar[j]) cnt[j]++;
	bool ok = true;
	rep(i, 4) if (cnt[i] != 1) ok = false;
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
