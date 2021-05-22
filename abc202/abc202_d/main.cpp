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

ll comb(int a, int b) {
	if (b > a) return 0;
	if (a-b < b) return comb(a, a-b);
	ll res = 1;
	rep(i, b) {
		res *= (a - i);
		res /= (i+1);
	}
	return res;
}

string calc(int ai, int bi, ll ki) {
	if (ki == 1) {
		string res = string(ai, 'a') + string(bi, 'b');
		return res;
	}
	else {
		int len = ai + bi, bi2 = bi - 1, ai2 = 0;
		while (bi+ai2 <= len) {
			ll bcnt = comb(bi2+ai2, ai2);
			if (ki <= bcnt) break;
			ki -= bcnt;
			++ai2;
		}
		string res2 = calc(ai2, bi2, ki);
		string res = string(ai-ai2, 'a') + 'b' + res2;
		return res;
	}
}

int main() {
	int a, b;
	ll k;
	cin >> a >> b >> k;
	string res = calc(a, b, k);
	cout << res << endl;
	return 0;
}
