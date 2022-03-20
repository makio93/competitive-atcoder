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

int main() {
	int n;
	cin >> n;
	unordered_set<int> nums;
	rep3(i, 1, n*2+2) nums.insert(i);
	int ival = -1;
	while (ival != 0) {
		cout << (*nums.begin()) << endl;
		nums.erase(nums.begin());
		cin >> ival;
		if (ival != 0) nums.erase(ival);
	}
	return 0;
}
