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
	int n;
	cin >> n;
	set<vector<int>> ast;
	rep(i, n) {
		int li;
		cin >> li;
		vector<int> ai;
		rep(j, li) {
			int aj;
			cin >> aj;
			ai.push_back(aj);
		}
		ast.insert(ai);
	}
	cout << (int)(ast.size()) << endl;
	return 0;
}
