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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s1, s2;
int cnt1[26], cnt2[26];
int main() {
  cin>>s1>>s2;
  memset(cnt1, 0, sizeof(cnt1));
  memset(cnt2, 0, sizeof(cnt2));
  // cin>>n;
  // for (int i = 0; i < n; ++i) {
  //   s1.push_back(rand()%26+'a');
  //   s2.push_back(rand()%26+'a');
  // }
  // cout<<s1<<endl<<s2<<endl;
  n = (int)s1.size();
  for (int i = 0; i < n; ++i) {
    cnt1[s1[i]-'a']++;
    cnt2[s2[i]-'a']++;
  }
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  string ans = string(n, ' ');
  int l = 0, r = n-1;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      int j1, j2;
      for (j1 = 0; j1 < 26; ++j1) {
        if (cnt1[j1]) break;
      }
      for (j2 = 25; j2 >= 0; --j2) {
        if (cnt2[j2]) break;
      }
      if (j1 >= j2) {
        int det = (n-i+1)/2;
        int tot=0;
        for (j1 = 0; j1 < 26; ++j1) {
          tot += cnt1[j1];
          if (tot >= det){
            break;
          }
        }
     //   cout<<"j1="<<r<<" "<<j1<<endl;
        ans[r--] = 'a' + j1;
        cnt1[j1]--;
      } else {
        ans[l++] = 'a' + j1;
        cnt1[j1]--;
      }
    } else {
      int j1, j2;
      for (j1 = 0; j1 < 26; ++j1) {
        if (cnt1[j1]) break;
      }
      for (j2 = 25; j2 >= 0; --j2) {
        if (cnt2[j2]) break;
      }
      if (j1 >= j2) {
        int det = (n-i+1)/2;
        if (det == 0) continue;
        int tot=0;
        for (j2 = 25; j2 >= 0; --j2) {
          tot += cnt2[j2];
          if (tot >= det){
            break;
          }
        }
     //   cout<<"j2="<<r<<" "<<j2<<endl;
        ans[r--] = 'a' + j2;
        cnt2[j2]--;
      } else {
        ans[l++] = 'a' + j2;
        cnt2[j2]--;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
