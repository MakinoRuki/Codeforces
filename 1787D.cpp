/*
先求出所有节点是否可以结束。
如果开始1不能到达一个结束节点，而是进入一个循环节点，那么就必须修改1出发路径上的任意一个循环节点，使它指向结束节点。
如果开始1可以到达结束节点，那么就修改1路径上任意一个节点u指向另一个结束节点v。但是不能指向可以到达从1到u路径上的节点的那些点。所以需要预处理出来某个结束节点v最终指向的1出发路径上的节点u是谁。
*/

#include <iostream>
#include <sstream>
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
#define N 2000005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int cc[N];
int pre[N];
int cnt[N];
int calc1(int x) {
  if (x-1>= -n) {
    return min(n,x-1)-(-n)+1;
  }
  return 0;
}
int calc2(int x) {
  if (x+1<=n) return n-max(-n, x+1)+1;
  return 0;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // ll ans=1LL;
  // for (int i =1; i <= 500; ++i) {
  //   ans=ans*5813LL%9422LL;
  // }
  // cout<<ans<<endl;
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cc[i]=-1;
      cnt[i]=0;
    }
    int id=-1;
    for (int i = 1; i <= n; ++i) {
      if (cc[i]<0) {
        set<int> ss;
        ss.clear();
        int cur=i;
        bool found=false;
        int gg=0;
        while(true) {
          if (cc[cur] >= 0) {
            if (!cc[cur]) {
              found=true;
            } else {
              gg=cc[cur];
            }
            break;
          }
          if (ss.find(cur) != ss.end()) {
            if (i == 1) id=cur;
            found=true;
            break;
          }
          ss.insert(cur);
          int nxt = cur + a[cur];
          if (nxt < 1 || nxt > n) {
            break;
          }
          pre[nxt] = cur;
          cur= nxt;
        }
        if (!found) {
          for (auto v : ss) {
          // cout<<"v="<<v<<endl;
            cc[v] = (gg>0?gg:v);
            if (gg>0) cnt[gg]++;
            else cnt[v]++;
          }
        } else {
          for (auto v : ss) {
            cc[v] =0;
          }
        }
        //cout<<"i="<<i<<" "<<cc[i]<<endl;
      }
    //  cout<<"i="<<i<<" "<<cc[i]<<endl;
    }
    int sum=0;
    for (int i = 1; i <= n; ++i) {
      if (cc[i] >0) sum++;
    }
    int cur=1;
    int num=0;
    ll ans=0LL;
    set<int> ss;
    ss.clear();
  //  cout<<"sum="<<sum<<endl;
    while(true) {
      if (cur < 1 || cur > n) break; 
      if (ss.find(cur) != ss.end()) break;
      ss.insert(cur);
      if (cc[cur]) sum-=cnt[cur];
      ans += sum;
   //   cout<<"ans="<<ans<<endl;
      ans += calc1(1-cur) + calc2(n-cur);
    //  cout<<"ans="<<ans<<endl;
      num++;
      cur = cur + a[cur];
    }
    if (id<0) {
      ans += (ll)(n-num)*(ll)(2*n+1);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
