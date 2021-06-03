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

// 自力WA

int n;
vector<int> a, b;
string calc(string str, int d, int tar) {
	if (d == n) {
		if (tar == 0) return str;
		else return string("Impossible");
	}
	else {
		if (tar <= 0) return string("Impossible");
		else {
			string res = calc(str+'A', d+1, tar-a[d]);
			if (res != "Impossible") return res;
			else return calc(str+'B', d+1, tar-b[d]);
		}
	}
}

int main() {
	int s;
	cin >> n >> s;
	a = vector<int>(n);
	b = vector<int>(n);
	rep(i, n) cin >> a[i] >> b[i];
	cout << calc(string(""), 0, s) << endl;
	return 0;
}
