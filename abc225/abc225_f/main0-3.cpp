// 本番WA3

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
	int n, k;
	cin >> n >> k;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	sort(s.begin(), s.end(), [&](string a, string b){ return (a+b<b+a || (a+b==b+a&&a==b)); });
	string res;
	rep(i, k) res += s[i];
	cout << res << endl;
	return 0;
}
