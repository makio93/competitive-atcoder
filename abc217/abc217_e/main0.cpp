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

// 本番AC

int main() {
	int q;
	cin >> q;
	deque<multiset<int>> a;
	rep(i, q) {
		int qi;
		cin >> qi;
		if (qi == 1) {
			int x;
			cin >> x;
			a.push_back(multiset<int>({x}));
		}
		else if (qi == 2) {
			cout << (*a.front().begin()) << endl;
			a.front().erase(a.front().begin());
			if (a.front().empty()) a.pop_front();
		}
		else {
			if (!a.empty()) {
				auto itr = next(a.begin());
				while (itr != a.end()) {
					for (auto xi : *itr) a.begin()->insert(xi);
					itr = a.erase(itr);
				}
			}
		}
	}
	return 0;
}
