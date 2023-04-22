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

int input(int i) {
	cout << "? " << i << endl;
	int si;
	cin >> si;
	return si;
}

void output(int p) {
	cout << "! " << p << endl;
	exit(0);
}

int main() {
	int n;
	cin >> n;
	int li = 1, ri = n;
	while (ri-li > 1) {
		int ci = (li+ri) / 2, si = input(ci);
		if (si == 0) li = ci;
		else ri = ci;
	}
	output(li);
	return 0;
}
