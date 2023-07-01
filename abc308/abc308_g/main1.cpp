// 解説AC

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
	int q;
	cin >> q;
	multiset<int> st, xst;
	rep(i, q) {
		int qi;
		cin >> qi;
		if (qi == 1) {
			int x;
			cin >> x;
			auto itr = st.lower_bound(x);
			if (itr!=st.begin() && itr!=st.end()) xst.erase(xst.find((*itr)^(*prev(itr))));
			if (itr != st.begin()) xst.insert(x^(*prev(itr)));
			if (itr != st.end()) xst.insert(x^(*itr));
			st.insert(x);
		}
		else if (qi == 2) {
			int x;
			cin >> x;
			auto itr = st.find(x);
			if (itr != st.begin()) xst.erase(xst.find((*itr)^(*prev(itr))));
			if (itr!=st.end() && next(itr)!=st.end()) xst.erase(xst.find((*next(itr))^(*itr)));
			if (itr!=st.begin() && itr!=st.end() && next(itr)!=st.end()) xst.insert((*prev(itr))^(*next(itr)));
			st.erase(st.find(x));
		}
		else cout << (*xst.begin()) << endl;
	}
	return 0;
}
