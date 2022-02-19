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

bool isprime(int val) {
	if (val < 2) return false;
	for (int i=2; i*i<=val; ++i) if (val%i == 0) return false;
	return true;
}

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	bool win = false;
	for (int i=a; i<=b; ++i) {
		bool rev = false;
		for (int j=c; j<=d; ++j) {
			if (isprime(i+j)) rev = true;
		}
		if (!rev) {
			win = true;
			break;
		}
	}
	if (win) cout << "Takahashi" << endl;
	else cout << "Aoki" << endl;
	return 0;
}
