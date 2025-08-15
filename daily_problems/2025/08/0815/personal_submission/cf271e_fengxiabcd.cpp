//#pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define i64 long long
#define double long double
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define ull unsigned long long
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define INF 1e18
#define exp 1e-12
vector<long long> fac(long long n) {
    vector<long long> v;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            v.push_back(i);
            if (i != n / i) v.push_back(n / i);
        }
    }
    sort(v.begin(), v.end());
    return v;
}

void slove() {
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int g=0;
    for(auto x:a)g=gcd(g,x-1);
    vector<int>b=fac(g);
    set<int>s;
    for(auto x:b){
        while(x<=m){
            s.insert(x);
            x*=2;
        }
    }
    int ans=0;
    for(auto x:s){
        ans+=(m-x);
    }
    cout<<ans<<endl;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) slove();
    return 0;
}
