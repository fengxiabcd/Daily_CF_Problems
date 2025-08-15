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
struct BIT{
    int n;
    vector<long long> t;
    BIT(int n):n(n),t(n+1,0){}
    void add(int i,long long v){
        for(;i<=n;i+=i&-i) t[i]+=v;
    }
    long long sum(int i){
        long long s=0;
        for(;i>0;i-=i&-i) s+=t[i];
        return s;
    }
    long long sum(int l,int r){
        return sum(r)-sum(l-1);
    }
};
void slove() {
    int n;
    cin>>n;
    vector<int>a(n),b(n+1),c(n+1),d(n+1);
    for(int i=0;i<n;i++)cin>>a[i];
    int sum=0;
    for(int i=0;i<n;i++){
        if(a[i]!=i+1){
            sum++;
            b[i+1]=sum;
            c[a[i]]=sum;
            d[a[i]]=i+1;
        }
    }
    vector<pii>p;
    BIT bit(n+1);
    vector<int>ans(n+1);
    for(int i=1;i<=n;i++){
        if(b[i]==0)continue;
        if(c[i]>b[i])p.pb({sum+b[i]-c[i],i+n});
        else p.pb({b[i]-c[i],i});
        ans[i]=p[sz(p)-1].f;
        p[sz(p)-1].f=d[i];
    }
    sort(all(p),[&](pii a,pii b){return a.s<b.s;});
    sum=0;
    priority_queue<pii,vector<pii>,greater<pii>>q;
    BIT bit2(2*n+1);
    for(auto [f,s]:p){
        //cout<<f<<" "<<s<<endl;
        while(!q.empty()&&q.top().f<s){
            //cout<<q.top().f<<" "<<q.top().s<<endl;
            bit2.add(q.top().s,-1);
            q.pop();
        }
        int g=s;
        if(g>n)g-=n;
        ans[g]+=bit.sum(f)-sum+bit2.sum(f,s);
        bit.add(f,1);
        sum++;
        q.push({s+n,f+n});
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) slove();
    return 0;
}
