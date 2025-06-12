#include <bits/stdc++.h>
using namespace std;
#define int long long

class SegmentTree {
private:
    struct Node {
        int l, r;
        int mn, mx, diff;
    };
    vector<Node> t;
    int n;

    void push_up(int p) {
        t[p].mn = min(t[p*2].mn, t[p*2+1].mn);
        t[p].mx = max(t[p*2].mx, t[p*2+1].mx);
        t[p].diff = max({t[p*2].diff, t[p*2+1].diff, t[p*2+1].mx - t[p*2].mn});
    }

    void build(int p, int l, int r, const vector<int>& a) {
        t[p].l = l; t[p].r = r;
        if (l == r) {
            t[p].mn = t[p].mx = a[l];
            t[p].diff = 0;
            return;
        }
        int m = (l + r) / 2;
        build(p*2, l, m, a);
        build(p*2+1, m+1, r, a);
        push_up(p);
    }

    void update(int p, int x, int v) {
        if (t[p].l == t[p].r) {
            t[p].mn = t[p].mx = v;
            t[p].diff = 0;
            return;
        }
        int m = (t[p].l + t[p].r) / 2;
        if (x <= m) update(p*2, x, v);
        else update(p*2+1, x, v);
        push_up(p);
    }

    Node query(int p, int l, int r) {
        if (l <= t[p].l && t[p].r <= r) return t[p];
        int m = (t[p].l + t[p].r) / 2;
        if (r <= m) return query(p*2, l, r);
        if (l > m) return query(p*2+1, l, r);
        Node L = query(p*2, l, r);
        Node R = query(p*2+1, l, r);
        Node res;
        res.mn = min(L.mn, R.mn);
        res.mx = max(L.mx, R.mx);
        res.diff = max({L.diff, R.diff, R.mx - L.mn});
        return res;
    }

public:
    SegmentTree(const vector<int>& a) {
        n = (int)a.size();
        t.resize(4 * n + 5);
        build(1, 0, n - 1, a);
    }

    void update(int x, int v) {
        update(1, x, v);
    }

    int query(int l, int r) {
        return query(1, l, r).diff;
    }
};

void solve() {
    int n,q; cin >> n>>q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(n);
    b=a;
    reverse(b.begin(),b.end());
    for(int i = 0; i < n; i++) {
        a[i]-=i;
    }
    for(int i = 0; i < n; i++) {
        b[i]-=i; 
    }
    SegmentTree tree(a);
    SegmentTree tree1(b);
    cout<<max(tree.query(0,n-1),tree1.query(0,n-1))<<endl;
    while(q--) {
       int x,y; cin>>x>>y;
       x--;
       int y1=y-(n-x-1);
       y-=x;
       tree.update(x,y);
       tree1.update(n-x-1,y1);
       cout<<max(tree.query(0,n-1),tree1.query(0,n-1))<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}
