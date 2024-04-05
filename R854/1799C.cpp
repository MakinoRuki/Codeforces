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
int cnt[30];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    for (int i = 0; i < 26; ++i) {
      cnt[i] = 0;
    }
    n = (int)s.size();
    for (int i = 0; i < n; ++i) {
      cnt[s[i]-'a']++;
    }
    string ans(n, ' ');
    int l = 0, r = n-1;
    while(l < r) {
      int pc=-1;
      bool found=false;
      for (int i = 0; i < 26; ++i) {
        if (cnt[i] == 1) {
          if (pc >= 0) {
            ans[l++] = 'a'+i;
            ans[r--] = 'a'+pc;
            cnt[i]--;
            cnt[pc]--;
            found=true;
            break;
          } else {
            pc = i;
          }
        } else if (cnt[i] >= 2) {
          if (pc >= 0) {
            if (n+l-r+cnt[i] < n) {
              ans[l++] = 'a'+i;
              ans[r--] = 'a'+pc;
              cnt[i]--;
              cnt[pc]--;
              found=true;
              break;
            } else {
              ans[l++] = 'a'+i;
              ans[r--] = 'a'+i;
              cnt[i] -= 2;
              break;
            }
          } else {
            ans[l++] = 'a'+i;
            ans[r--] = 'a'+i;
            cnt[i] -= 2;
            break;
          }
        }
        // if (cnt[i] >= 2) {
        //   ans[l++] = 'a'+i;
        //   ans[r--] = 'a'+i;
        //   cnt[i] -= 2;
        //   break;
        // } else {
        //   if (pc < 0) {
        //     pc = i;
        //     continue;
        //   } else {
        //     ans[l++] = i+'a';
        //     ans[r--] = pc+'a';
        //     cnt[pc]--;
        //     cnt[i]--;
        //     found=true;
        //     break;
        //   }
        // }
      }
      if (found)break;
    }
    string ss="";
    for (int j = 0; j < 26; ++j) {
      for (int k = 1; k <= cnt[j]; ++k) {
        ss.push_back('a'+j);
      }
    }
    sort(ss.begin(), ss.end());
    for (int j = l; j <= r; ++j) {
      ans[j] = ss[j-l];
    }
    cout<<ans<<endl;
  }
  return 0;
}
