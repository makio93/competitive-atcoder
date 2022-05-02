// 復習0,解説,AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main(){
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s;
    map<char, int> cnt;
    rep(i, n) cnt[s[i]]++;
    rep(i, n) {
        for (char c='a'; c<='z'; ++c) {
            if (cnt[c]==0) continue;
            string u = t + c;
            map<char, int> cnt2 = cnt;
            cnt2[c]--;
            int score = 0;
            rep(j, (int)(u.length())) {
                if (u[j] != s[j]) ++score;
            }
            for (int j=(int)(u.length()); j<n; ++j) {
                if (cnt2[s[j]]==0) ++score;
                else cnt2[s[j]]--;
            }
            if (score <= k) {
                t += c;
                cnt[c]--;
                break;
            }
        }
    } 
    cout << t << endl;
    return 0;
}
