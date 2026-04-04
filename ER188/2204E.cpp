
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
#define M 10002
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
// int a[N];
// int b[N];
// int c[N];
int cnt[M];
int cnt2[M];
vector<int> getv(int x) {
  vector<int> res;
  res.clear();
  if (!x) {
    res.push_back(0);
    return res;
  }
  while(x) {
  //  cout<<"x="<<x<<endl;
    vector<int> tmp;
    tmp.clear();
    int sum=0;
    while(x) {
      tmp.push_back(x%10);
      sum+=x%10;
      x/=10;
    }
    for (int i = tmp.size()-1; i >= 0; --i) {
      res.push_back(tmp[i]);
    }
    if (tmp.size()==1) break;
    x = sum;
  }
  return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
   // ll a,b,c,m;
    string s;
    cin>>s;
    m = (int)s.size();
    for (int i = 0; i <= 10; ++i) {
      cnt[i] = 0;
    }
    for (int i = 0; i < s.size(); ++i) {
      cnt[s[i]-'0']++;
    }
    if (m == 1) {
      cout<<s<<endl;
      continue;
    }
    string ans="";
    for (int i = 0; i <= 9*m; ++i) {
     // cout<<"i="<<i<<endl;
      vector<int> v = getv(i);
      for (int j = 0; j <= 10; ++j) {
        cnt2[j]=cnt[j];
      }
      vector<pair<int,int>> v2;
      v2.clear();
      bool ok=true;
      for (auto x : v) {
        cnt2[x]--;
        if (cnt2[x] < 0) {
          ok=false;
          break;
        }
      }
      if (!ok) continue;
      ll tot=0LL;
      for (int j = 0; j < 10; ++j) {
        if (cnt2[j]) {
          v2.push_back(make_pair(j, cnt2[j]));
          tot += j*cnt2[j];
        }
      }
      if (tot != i) continue;
      if (v2.empty()) continue;
      sort(v2.begin(), v2.end());
      if (v2.back().first > 0 || v2.back().second == 1) {
        for (int i = v2.size()-1; i >= 0; --i) {
          for (int j = 1; j <= v2[i].second; ++j) {
            ans.push_back('0'+v2[i].first);
          }
        }
        for (auto x : v) {
          ans.push_back('0'+x);
        }
        break;
      }
    }
    cout<<ans<<endl;
  }

  

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
