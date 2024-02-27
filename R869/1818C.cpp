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
#define N 300005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int cnt[N];
int dp[N];
int main() {
  cin>>n>>q;
  cnt[0]=0;
  for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[i]=cnt[i-1];
      if (a[i] <= a[i-1]) {
          cnt[i]++;
      }
  }
  vector<pair<int,int>> v;
  v.clear();
  int st=-1;
  for (int i = 1; i <= n; ++i) {
      if (a[i] <= a[i-1]) {
          if (st < 0) st= i;
      } else {
          if (st > 0) {
              v.push_back(make_pair(st, i-1));
              st = -1;
          }
      }
  }
  if (st > 0) {
      v.push_back(make_pair(st, n));
  }
  while(q-->0) {
      int l, r;
      scanf("%d%d", &l, &r);
      if (l == r) {
          puts("1");
      } else {
          int ll,rr;
          int lb =0, rb = v.size();
         // cout<<lb<<" "<<rb<<endl;
          while(lb < rb) {
              int mid=(lb+rb)/2;
              if (l <= v[mid].second-1) {
                  rb = mid;
              } else {
                  lb = mid+1;
              }
          }
          ll = rb;
         // cout<<ll<<endl;
          lb = -1, rb = v.size()-1;
        //  cout<<lb<<" "<<rb<<endl;
          while(lb < rb) {
              int mid=(lb+rb+1)/2;
            //  cout<<"xxx="<<lb<<" "<<rb<<" "<<mid<<" "<<v[mid].first<<" "<<r<<endl;
              if (r >= v[mid].first) {
                  lb = mid;
              } else {
                  rb = mid-1;
              }
          }
          rr = rb;
         // cout<<rr<<endl;
          //cout<<ll<<" "<<rr<<endl;
          int tot=r-l+1-(cnt[r]-cnt[l]);
       //   cout<<"tot="<<tot<<endl;
         // cout<<"lr="<<ll<<" "<<rr<<endl;
          if (ll <= rr) {
              tot += rr-ll+1;
          }
          printf("%d\n", tot);
      }
  }
  return 0;
}
