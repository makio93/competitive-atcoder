#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番WA

int main(){
    int n, a;
    cin >> n >> a;
    string s;
    cin >> s;
    set<int> st;
    st.insert(0);
    st.insert(n+1);
    rep(i, n) if (s[i] == '#') st.insert(i+1);
    int ans = 0, p = a;
    bool right = true;
    while ((int)(st.size()) > 2) {
        int val = -1;
        if (p!=0 && p!=n+1) {
            auto pitr = st.upper_bound(p);
            if (!right) --pitr;
            val = *pitr;
            if (val!=0 && val!=n+1) st.erase(pitr);
        }
        else {
            auto pitr = st.find(p);
            if (right) ++pitr;
            else --pitr;
            val = *pitr;
            if (val!=0 && val!=n+1) st.erase(pitr);
        }
        //if (abs(val-p) < n+1) 
        ans += abs(val - p);
        p = val;
        right = !right;
    }
    cout << ans << endl;
    return 0;
}
