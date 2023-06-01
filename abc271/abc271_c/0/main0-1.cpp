// 本番WA

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
	set<int> a;
	int dval = 0;
	rep(i, n) {
		int ai;
		cin >> ai;
		if (a.find(ai) == a.end()) a.insert(ai);
		else ++dval;
	}
	int ri = 1;
	while (dval > 1) {
		while (a.find(ri) != a.end()) ++ri;
		a.insert(ri);
		dval -= 2;
		++ri;
	}
	while (a.find(ri) != a.end()) ++ri;
	auto itr = prev(a.end());
	if (dval==1 && *itr>ri) {
		--dval;
		itr = prev(a.erase(itr));
		--itr;
		a.insert(ri);
		++ri;
		while (a.find(ri) != a.end()) ++ri;
	}
	while (!a.empty() && itr!=a.begin() && *prev(itr)>ri) {
		rep(i, 2) itr = prev(a.erase(itr));
		a.insert(ri);
		while (a.find(ri) != a.end()) ++ri;
	}
	cout << (ri-1) << endl;
	return 0;
}
