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
	string a, b;
	cin >> a >> b;
	reverse(all(a));
	reverse(all(b));
	int mlen = min(a.length(), b.length());
	bool ok = true;
	rep(i, mlen) if ((int)(a[i]-'0')+(int)(b[i]-'0') > 9) ok = false;
	if (ok) cout << "Easy" << endl;
	else cout << "Hard" << endl;
	return 0;
}
