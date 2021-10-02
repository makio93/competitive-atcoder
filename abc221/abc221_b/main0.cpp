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

// 本番AC

int main() {
	string s, t;
	cin >> s >> t;
	int n = s.length();
	vector<int> tid;
	bool res = false;
	if (s == t) res = true;
	else {
		rep(i, n) if (s[i] != t[i]) tid.push_back(i);
		if ((int)(tid.size())==2 && tid[0]+1==tid[1]) {
			swap(s[tid[0]], s[tid[1]]);
			if (s == t) res = true;
		}
	}
	if (res) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
