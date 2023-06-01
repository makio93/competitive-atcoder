// 自力AC

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
	int id = 1;
	while (1) {
		if (a.find(id) != a.end()) ++id;
		else if (dval >= 2) {
			dval -= 2;
			a.insert(id);
			++id;
		}
		else break;
	}
	auto ritr = prev(a.end());
	while (!a.empty() && *ritr>id) {
		ritr = a.erase(ritr);
		++dval;
		if (dval >= 2) {
			a.insert(id);
			++id;
			while (a.find(id) != a.end()) ++id;
			dval -= 2;
		}
		if (!a.empty()) --ritr;
	}
	cout << (id-1) << endl;
	return 0;
}
