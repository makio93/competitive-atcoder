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

// 解説AC

int main() {
	string x;
	cin >> x;
	int n = x.length();
	int s = 0, c = 0;
	rep(i, n) s += x[i] - '0';
	int id = n-1;
	c += s;
	string res;
	while (id>=0 || c>0) {
		res += (char)(c%10+'0');
		if (id >= 0) s -= x[id] - '0';
		c /= 10;
		c += s;
		--id;
	}
	reverse(all(res));
	cout << res << endl;
	return 0;
}
