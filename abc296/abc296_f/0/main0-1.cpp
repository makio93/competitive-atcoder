// 本番WA1

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
	vector<int> a(n), b(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	rep(i, n) {
		cin >> b[i];
		b[i]--;
	}
	vector<int> acnt(n), bcnt(n);
	rep(i, n) acnt[a[i]]++;
	rep(i, n) bcnt[b[i]]++;
	if (acnt != bcnt) {
		cout << "No" << endl;
		return 0;
	}
	unordered_set<int> dvals;
	rep(i, n) {
		if (acnt[i] >= 2) dvals.insert(i);
		if (bcnt[i] >= 2) dvals.insert(i);
	}
	vector<int> alst, blst;
	rep(i, n) if (a[i]!=b[i] && dvals.find(a[i])==dvals.end() && dvals.find(b[i])==dvals.end()) {
		alst.push_back(a[i]);
		blst.push_back(b[i]);
	}
	unordered_map<int, set<int>> aids;
	int m = alst.size();
	rep(i, m) aids[alst[i]].insert(i);
	int res = 0;
	while (!aids.empty()) {
		int val = 0;
		set<int> tmp;
		int id = aids.begin()->first;
		while (1) {
			++val;
			tmp.insert(id);
			int tid = *aids[id].begin();
			aids[id].erase(tid);
			if (aids[id].empty()) aids.erase(id);
			if (tmp.find(blst[tid]) != tmp.end()) break;
			tmp.insert(blst[tid]);
			id = blst[tid];
		}
		if (res == 0) res += val;
		else res += val - 1;
	}
	if (res==0 || res%2==1) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
