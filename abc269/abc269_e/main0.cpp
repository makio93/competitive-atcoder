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
	int n;
	cin >> n;
	int a = 1, b = n, c = 1, d = n;
	while (b-a > 0) {
		int ab = a + (b-a) / 2;
		cout << "? " << a << ' ' << ab << ' ' << 1 << ' ' << n << endl;
		cout.flush();
		int ti;
		cin >> ti;
		if (ti == ab-a+1) a = ab + 1;
		else b = ab;
	}
	while (d-c > 0) {
		int cd = c + (d-c) / 2;
		cout << "? " << 1 << ' ' << n << ' ' << c << ' ' << cd << endl;
		cout.flush();
		int ti;
		cin >> ti;
		if (ti == cd-c+1) c = cd + 1;
		else d = cd;
	}
	cout << "! " << a << ' ' << c << endl;
	cout.flush();
	return 0;
}
