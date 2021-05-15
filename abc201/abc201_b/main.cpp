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
	cin >> n;
	vector<string> s(n);
	vector<int> t(n);
	rep(i, n) cin >> s[i] >> t[i];
	map<int, string> scnt;
	rep(i, n) scnt[t[i]] = s[i];
	cout << (next(scnt.rbegin())->second) << endl;
	return 0;
}
