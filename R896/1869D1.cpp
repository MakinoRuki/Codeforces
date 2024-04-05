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
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll tot=0LL;
    vector<ll> v0;
    vector<ll> v1;
    v0.clear();
    v1.clear();
    for (int i =1; i <= n; ++i) {
      scanf("%d", &a[i]);
      tot += a[i];
    }
    bool ok=true;
    for (int i = 1; i <= n; ++i) {
      ll dt = a[i]-tot/n;
      if (dt==0) continue;
      ll dt1=abs(dt);
      int b0=0,b1=0;
      while((dt1%2)==0) {
        b0++;
        dt1/=2;
      }
      b1=b0;
      while(dt1) {
        b1++;
        dt1/=2;
      }
    //  cout<<"i="<<i<<" "<<dt1<<" "<<b0<<" "<<b1<<endl;
      //cout<<(1LL<<b1)<<" "<<(1LL<<b0)<<" "<<dt1<<endl;
      if ((1LL<<b1) - (1LL<<b0) != abs(dt)) {
        ok=false;
        break;
      }
      if (dt > 0) {
        v1.push_back(b1);
        v0.push_back(b0);
      } else {
        v0.push_back(b1);
        v1.push_back(b0);
      }
    }
    if (!ok) {
    //  cout<<"1"<<endl;
      puts("No");
      continue;
    }
    sort(v0.begin(), v0.end());
    sort(v1.begin(), v1.end());
    if (v0.size() != v1.size()) {
     // cout<<"2"<<endl;
      puts("No");
      continue;
    }
    for (int i = 0; i < v0.size(); ++i) {
      //cout<<"i="<<i<<" "<<v0[i]<<" "<<v1[i]<<endl;
      if (v0[i] != v1[i]) {
        ok=false;
        break;
      }
    }
    if (ok) puts("Yes");
    else puts("No");
  }
  return 0;
}
