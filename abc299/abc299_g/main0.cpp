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
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	vector<vector<int>> aids(m);
	rep(i, n) aids[a[i]].push_back(i);
	set<int> bst;
	int li = 0, ri = m-1;
	while (li <= ri) {
		if (bst.empty() || li==ri) {
			bst.insert(aids[li][0]);
			++li;
		}
		else {
			int tli = aids[li].size()-1, tlv = *bst.rbegin(), tri = 0, trv = *bst.begin();
			while (tli-1>=0 && aids[li][tli-1]>tlv) --tli;
			while (tri+1<(int)(aids[ri].size()) && aids[ri][tri+1]<trv) ++tri;
			if (tri >= (int)(aids[li].size()-1)-tli) {
				bst.insert(aids[ri][tri]);
				--ri;
			}
			else {
				bst.insert(aids[li][tli]);
				++li;
			}
		}
	}
	vector<int> res;
	for (const int& id : bst) res.push_back(a[id]+1);
	rep(i, m) cout << res[i] << (i<m-1?' ':'\n');
	return 0;
}
