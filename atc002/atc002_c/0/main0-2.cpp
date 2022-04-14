// 自力,ヒント有り,未完成

#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

using ll = long long;
using pii  = pair<int, int>;
using pll = pair<ll, ll>;
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; i++)
#define repr(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rep1r(i, n) for (int i = ((int)(n)); i >= 1; i--)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

class Heap {
public:
    struct Node {
        int val, s;
        Node *l, *r;
        Node(int val, Node* l=NULL, Node* r=NULL, int s=0) {
            this->val = val, this->l = l, this->r = r, this->s = s;
        }
        /*
        const bool operator<(const Node& rhs) const {
            if (val != rhs.val) return val < rhs.val
        }
        */
    };
private:
    Node* root;
public:
    Heap(Node* root=NULL) { this->root = root; }
private:
    Node *meld(Node* a, Node* b) {
        if (a == NULL) return b;
        if (b == NULL) return a;
        if (a->val >= b->val) swap(a, b);
        if (a->l == NULL) a->l = b;
        else {
            a->r = meld(a->r, b);
            if (a->l->s < a->r->s) swapChildren(a);
            a->s = a->r->s + 1;
        }
        return a;
    }
    void swapChildren(Node* hs) {
        Node* tmp = hs->l;
        hs->l = hs->r;
        hs->r = tmp;
    }
public:
    void meld(Heap &rhs) {
        if (this == &rhs) return;
        root = meld(root, rhs.root);
        rhs.root = NULL;
    }
    void push(int x) {
        root = meld(new Node(x), root);
    }
    int top() { return root->val; }
    void pop() {
        Node* oldroot = root;
        root = meld(root->l, root->r);
        if (oldroot != NULL) delete oldroot;
    }
    bool empty() { return (root == NULL); }
};

int hu_tucker(vi a) {
    int n = sz(a);
    vector<Heap> heap(n-1);
    vi ls(n), rs(n), cs(n-1);
    priority_queue<pii, vpii, greater<pii>> q;
    rep(i, n-1) {
        ls[i] = i - 1;
        rs[i] = i + 1;
        cs[i] = a[i] + a[i+1];
        q.emplace(cs[i], i);
    }
    int ret = 0;
    rep(k, n-1) {
        auto p = q.top(); q.pop();
        int c = p.first, i = p.second;
        bool ml = false, mr = false;
        if (!heap[i].empty() && a[i]+heap[i].top()) {
            heap[i].pop();
            ml = true;
        }
        else if (a[i] + a[rs[i]] == c) ml = mr = true;
        else {
            auto top = heap[i].top();
            heap[i].pop();
            if (!heap[i].empty() && heap[i].top()+top==c) heap[i].pop();
            else mr = true;
        }
        ret += c;
        heap[i].push(c);
        if (ml) a[i] = INF;
        if (mr) a[rs[i]] = INF;
        if (ml && i>0) {
            int j = ls[i];
            heap[j].meld(heap[i]);
            rs[j] = rs[i];
            rs[i] = -1;
            ls[rs[j]] = j;
            i = j;
        }
        if (mr && rs[i]+1<n) {
            int j = rs[i];
            heap[i].meld(heap[j]);
            rs[i] = rs[j];
            rs[j] = -1;
            ls[rs[i]] = i;
        }
        cs[i] = a[i] + a[rs[i]];
        if (!heap[i].empty()) {
            int top = heap[i].top(); heap[i].pop();
            cs[i] = min(cs[i], min(a[i], a[rs[i]]) + top);
            if (!heap[i].empty()) cs[i] = min(cs[i], top+heap[i].top());
            heap[i].push(top);
        }
        q.emplace(cs[i], i);
    }
    return ret;
}

int main(){
    int n;
    cin >> n;
    vi w(n);
    rep(i, n) cin >> w[i];
    cout << hu_tucker(w) << endl;
    return 0;
}
