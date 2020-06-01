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
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int u[N];
int cnt[N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &u[i]);
  }
  map<int, int> mp;
  mp.clear();
  memset(cnt, 0, sizeof(cnt));
  int ans=1;
  for (int i = 1; i <= n; ++i) {
    if (mp.find(cnt[u[i]]) != mp.end() ) {
      mp[cnt[u[i]]]--;
      if (mp[cnt[u[i]]] == 0) mp.erase(cnt[u[i]]);
    }
    cnt[u[i]]++;
    mp[cnt[u[i]]]++;
    if (mp.size()==1) {
      auto itr = mp.begin();
      if (itr->first == 1) {
        ans = max(ans, i);
      } else {
        if (itr->second == 1) {
          ans = max(ans, i);
        }
      }
    } else if (mp.size() == 2) {
      if (mp.find(1) != mp.end() && mp[1] == 1) {
        ans=max(ans, i);
      } else {
        auto itr = mp.begin();
        int tot = (itr->first * itr->second);
        if (i > tot && (i-tot == (itr->first)+1) && mp.find(itr->first+1) != mp.end() && mp[itr->first+1]==1) {
          ans=max(ans, i);
        }
      }
    }
    // cout<<"i="<<i<<endl;
    // for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
    //   cout<<(itr->first)<<" "<<(itr->second)<<endl;
    // }
  }
  cout<<ans<<endl;
  return 0;
}
