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
#define N 302
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int d[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    map<int, int> mp;
    mp.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &d[i]);
      int x=d[i];
      for (int j = 2; j*j<=x; ++j) {
        if (x%j == 0) {
          int cnt=0;
          while(x%j==0) {
            cnt++;
            x/=j;
          }
          mp[j] = max(mp[j], cnt);
        }
      }
      if (x>1) mp[x] = max(mp[x], 1);
    }
    if (mp.size()==1) {
      auto itr = mp.begin();
      if (itr->second != n) {
        cout<<-1<<endl;
      } else {
        ll ans=1LL;
        for (int i = 1; i <= (itr->second)+1; ++i) {
          ans *= itr->first;
        }
        cout<<ans<<endl;
      }
    } else {
      ll tot=0LL;
      for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
       // cout<<itr->first<<" "<<itr->second<<endl;
        tot = ((itr->second)+1)*tot+itr->second;
        if (tot > 310) break;
      }
     // cout<<tot<<endl;
      if (tot > 310 || tot-1 != n) {
        cout<<-1<<endl;
      } else {
        ll ans=1LL;
        for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
          for (int i = 1; i <= itr->second; ++i) {
            ans *= itr->first;
          }
        }
        int i;
        for (i = 1; i <= n; ++i) {
          if (d[i] == ans) break;
        }
        if (i <= n) cout<<-1<<endl;
        else cout<<ans<<endl;
      }
    }
  }
  return 0;
}
