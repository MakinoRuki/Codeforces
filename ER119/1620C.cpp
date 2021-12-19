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
#define N 3000
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q, p;
int l, r;
int t;
string s;
ll x;
ll tot[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%lld", &n, &k, &x);
    cin>>s;
    // s.clear();
    // for (int i = 0; i < n; ++i) {
    //   if (rand()%2) s.push_back('a');
    //   else s.push_back('*');
    // }
    // cout<<"s="<<s<<endl;
    vector<pair<char, int>> sg;
    sg.clear();
    int cnt=0;
    for (int i = 0; i < n; ++i) {
      if (i == 0 || s[i] == s[i-1]) {
        cnt++;
      } else {
        if (cnt > 0) {
          sg.push_back(make_pair(s[i-1], cnt));
        }
        cnt = 1;
      }
    }
    if (cnt > 0) {
      sg.push_back(make_pair(s.back(), cnt));
    }
    // for (int i = 0; i < sg.size(); ++i) {
    //   cout<<i<<" "<<sg[i].first<<" "<<sg[i].second<<endl;
    // }
    cnt=0;
    for (int i = 0; i < sg.size(); ++i) {
      if (sg[i].first == '*') {
        cnt++;
        tot[cnt] = sg[i].second;
      }
    }
    for (int i = cnt; i >= 1; --i) {
     // cout<<"i2="<<i<<" "<<tot[i]<<endl;
      if (i == cnt) tot[i] = tot[i] * (ll)k + 1;
      else {
        ll det = (tot[i] * (ll)k) + 1;
        if (tot[i+1] >= x || det >= (x+tot[i+1]-1) / tot[i+1]) {
          tot[i] = x;
        } else {
          tot[i] = det * tot[i+1];
        }
      }
     // cout<<tot[i]<<endl;
    }
    // cout<<"cnt="<<cnt<<endl;
    // for (int i = 1; i <= cnt; ++i) {
    //   cout<<i<<" "<<tot[i]<<endl;
    // }
    string ans = "";
    int cnt1=0;
    for (int i = 0; i < sg.size(); ++i) {
   //   cout<<sg[i].first<<" "<<sg[i].second<<endl;
      if (sg[i].first == 'a') {
        ans += string(sg[i].second, 'a');
      } else {
        cnt1++;
        if (cnt1 == cnt) {
          ans += (x - 1 > 0 ? string(x-1, 'b') : "");
        } else {
          int j = (x + tot[cnt1+1] - 1) / tot[cnt1+1] - 1;
          // for (j = 0; j <= sg[i].second; ++j) {
          //   if (tot[cnt1+1] >= (x +j)/ (ll)(j+1)) {
          //     break;
          //   }
          // }
       //   cout<<"j="<<cnt1<<" "<<tot[cnt1+1]<<" "<<j<<" "<<x<<endl;
          ans += (j > 0 ? string(j, 'b') : "");
          x -= (ll)j * tot[cnt1+1];
        //  cout<<"j="<<x<<endl;
        }
      }
    }
    printf("%s\n", ans.c_str());
  }
  return 0;
}
