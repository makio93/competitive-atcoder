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
	string n;
	cin >> n;
	int zcnt = 0;
	vector<char> dlst;
	for (char ni : n) {
		if (ni == '0') ++zcnt;
		else dlst.push_back(ni);
	}
	sort(dlst.rbegin(), dlst.rend());
	int len = dlst.size();
	vector<string> ds(2);
	rep(i, len/2*2) ds[i%2].push_back(dlst[i]);
	if (len%2 == 1) ds[1].push_back(dlst[len-1]);
	if (zcnt%2 == 0) rep(i, 2) ds[i] += string(zcnt/2, '0');
	else {
		if (len%2 == 1) {
			ds[0] += string(zcnt/2+1, '0');
			ds[1] += string(zcnt/2, '0');
		}
		else {
			ds[0] += string(zcnt/2, '0');
			ds[1] += string(zcnt/2+1, '0');
		}
	}
	ll res = stoll(ds[0]) * stoll(ds[1]);
	cout << res << endl;
	return 0;
}
