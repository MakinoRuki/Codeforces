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
#define N 300005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int par[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    map<int, int> cnt;
    cnt.clear();
    for (int i = 0; i < n; ++i) {
      cnt[s[i]-'a']++;
    }
    set<pair<int,int>> ss;
    ss.clear();
    for (auto itr : cnt) {
      ss.insert(make_pair(-itr.second, itr.first));
    }
    string ans="";
    while(!ss.empty()) {
      // if (ss.size() <= 2) {
      //   break;
      // }
      vector<pair<int,int>> v;
      v.clear();
      while(!ss.empty()) {
        auto itr = *ss.begin();
        ss.erase(itr);
        ans.push_back('a' + itr.second);
        itr.first++;
        if (itr.first != 0) {
          v.push_back(itr);
        }
      }
      for (auto pr : v) {
        ss.insert(pr);
      }
    }
    // while(!ss.empty()) {
    //   auto itr = *ss.begin();
    //   ss.erase(itr);
    //   for (int i = 1; i <= -itr.first; ++i) {
    //     ans.push_back('a'+ itr.second);
    //   }
    // }
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

