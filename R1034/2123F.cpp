#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <ctime>
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 500005
#define M 1002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
bool vis[N];
int main() {
  cin>>t;
//   ps.clear();
//   memset(pr, false, sizeof(pr));
//   for (int i =2; i < N; ++i) {
//       if (!pr[i]) {
//           ps.push_back(i);
//           for (int j = i*2; j < N; j += i) {
//               pr[j] = true;
//           }
//       }
//   }
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        vis[i]=false;
        a[i] = i;
    }
    for (int i = n; i >= 2; --i) {
        if (!vis[i]) {
            for (int j = 2*i; j <= n; j += i) {
                if (!vis[j]) {
                    vis[j]=true;
                    swap(a[i], a[j]);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", a[i]);
    }
    cout<<endl;
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 

/*#include <bits/stdc++.h>
using namespace std;
 
vector<bool> comp(1e5+1);
vector<int> primes;
 
void sieve(){
    for(int i=2; i*i<=1e5; i++)
        if(!comp[i])
            for(int j=i*i; j<=1e5; j+=i)
                comp[j] = true;
    for(int i=2; i<=1e5; i++)
        if(!comp[i])
            primes.push_back(i);
}
 
void solve(){
    int n;
    cin >> n;
    vector<int> p(n+1);
    for(auto it = primes.rbegin(); it != primes.rend(); ++it){
        vector<int> cycle;
        for(int i=*it; i<=n; i+=*it)
            if(!p[i])
                cycle.push_back(i);
        for(int i=0; i<cycle.size(); i++)
            p[cycle[i]] = cycle[(i+1) % cycle.size()];
        if (!cycle.empty()) {
            cout<<"p="<<(*it)<<endl;
            for (int i = 2; i <= n; ++i) {
                cout<<p[i]<<" ";
            }
            cout<<endl;
        }
    }
    for(int i=1; i<=n; i++)
        if(!p[i])
            p[i] = i;
    for(int i=1; i<=n; i++)
        cout << p[i] << (i != n ? ' ' : '\n');
}
 
int main(){
    sieve();
    int t;
    cin >> t;
    while(t--) solve();
} */
