#include <bits/stdc++.h>
using namespace std;
#define int long long

int s[500005],e[500005];
void add1(int x){
    int f=x+2e5;
    s[f]++;
}
void add2(int x){
    int f=x+2e5;
    e[f]++; 
}
bool query(int x){
    int f=x+2e5;
    if(abs(x)>2e5){
        return 0; 
    }
    return  s[f]>0;
}
bool query2(int x){
    int f=x+2e5;
    if(abs(x)>2e5){
        return 0;
    }
    return e[f]>0; 
}
vector<int> ifd(int x){
    vector<int>v;
    for(int i=1;i*i<=abs(x);i++){
        if(abs(x)%i==0){
            v.push_back(i);
            v.push_back(-i);
            if(i!=abs(x)/i){
                v.push_back(x/i); 
                v.push_back(-x/i);
            } 
        }
    }
    return v;
}
void solve() {
    int n,m,q;
    cin >> n >> m>>q;
    vector<int>v(n);
    vector<int>s(m);
    int sum1=0,sum2=0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        sum1+=v[i];
        add1(v[i]);
    }
    for(int i=0;i<m;i++){
        cin >> s[i];
        sum2+=s[i];
        add2(s[i]); 
    }
    while(q--){
        int x;
        cin >> x;
        vector<int>v=ifd(x);
        bool flag=0;
        for(auto i:v){
            //cout << i << endl;
            if(query(sum1-i)&&query2(sum2-x/i)){
                cout << "YES" << endl;
                flag=1;
                break;
            }
            if(query(sum1-x/i)&&query2(sum2-i)){
                cout << "YES" << endl;
                flag=1;
                break; 
            }
        }
        if(!flag){
            cout << "NO" << endl; 
        }
    }
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

int s[500005],e[500005];
void add1(int x){
    int f=x+2e5;
    s[f]++;
}
void add2(int x){
    int f=x+2e5;
    e[f]++; 
}
bool query(int x){
    int f=x+2e5;
    if(abs(x)>2e5){
        return 0; 
    }
    return  s[f]>0;
}
bool query2(int x){
    int f=x+2e5;
    if(abs(x)>2e5){
        return 0;
    }
    return e[f]>0; 
}
vector<int> ifd(int x){
    vector<int>v;
    for(int i=1;i*i<=abs(x);i++){
        if(abs(x)%i==0){
            v.push_back(i);
            v.push_back(-i);
            if(i!=abs(x)/i){
                v.push_back(x/i); 
                v.push_back(-x/i);
            } 
        }
    }
    return v;
}
void solve() {
    int n,m,q;
    cin >> n >> m>>q;
    vector<int>v(n);
    vector<int>s(m);
    int sum1=0,sum2=0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        sum1+=v[i];
        add1(v[i]);
    }
    for(int i=0;i<m;i++){
        cin >> s[i];
        sum2+=s[i];
        add2(s[i]); 
    }
    while(q--){
        int x;
        cin >> x;
        vector<int>v=ifd(x);
        bool flag=0;
        for(auto i:v){
            //cout << i << endl;
            if(query(sum1-i)&&query2(sum2-x/i)){
                cout << "YES" << endl;
                flag=1;
                break;
            }
            if(query(sum1-x/i)&&query2(sum2-i)){
                cout << "YES" << endl;
                flag=1;
                break; 
            }
        }
        if(!flag){
            cout << "NO" << endl; 
        }
    }
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}
