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
#define N 300005
#define M 750
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
int a[N];
string s;
int cnt[30];
bool check(int l1, int r1, int l2, int r2) {
  for (int i = 0; i < 26; ++i) {
    cnt[i]=0;
  }
  for (int i = l1; i <= r1; ++i) {
  //  cout<<"ii="<<i-1<<" "<<s[i-1]-'a'<<endl;
    cnt[s[i-1]-'a']++;
  }
  for (int i = l2; i <= r2; ++i) {
    //cout<<"ii2="<<i-1<<" "<<s[i-1]-'a'<<endl;
    cnt[s[i-1]-'a']--;
  }
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] != 0) return false;
  }
  return true;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>s;
    n = (int)s.size();
    vector<int> v;
    v.clear();
    int ans=n;
    for (int i = 1; i <= n/2; ++i) {
      int j=n+1-i;
    //  cout<<"vv="<<i-1<<" "<<j-1<<endl;
      if (s[i-1] != s[j-1]) {
        v.push_back(j);
      }
    }
    if (v.empty()) {
      puts("0");
      continue;
    }
    sort(v.begin(), v.end());
  //  cout<<"vv="<<(int)v.size()<<" "<<v[0]<<" "<<v.back()<<endl;
    int l=v[0];
    int r=v.back();
   // cout<<"lr="<<l<<" "<<r<<endl;
    if (check(n+1-r, n+1-l, l, r)) {
     // cout<<"??"<<endl;
    //  cout<<"vv2="<<(int)v.size()<<" "<<v[0]<<" "<<v.back()<<endl;
      ans=min(ans, v.back()-v[0]+1);
    }
    v.clear();
    for (int i = n; i > n/2; --i) {
      int j = n+1-i;
    //  cout<<"vv3="<<i-1<<" "<<j-1<<endl;
      if (s[j-1] != s[i-1]) {
        v.push_back(j);
      }
    }
    if (v.empty()) {
      puts("0");
      continue;
    }
    sort(v.begin(), v.end());
 //   cout<<"vv4="<<(int)v.size()<<" "<<v[0]<<" "<<v.back()<<endl;
    l=v[0],r=v.back();
    if (check(l,r,n+1-r,n+1-l)) {
      ans=min(ans,r-l+1);
    }
    l=1,r=n;
    while((l<=r) && (s[l-1]==s[r-1])) {
      l++,r--;
    }
 //   cout<<"lr="<<l<<" "<<r<<endl;
    if (l>r) {
      puts("0");
      continue;
    }
   // cout<<"ans="<<ans<<endl;
    for (int i = 0; i < 26; ++i) {
      cnt[i]=0;
    }
    for (int i=l;i<=r;++i) {
     // cout<<"i="<<i-1<<" "<<s[i-1]-'a'<<endl;
      cnt[s[i-1]-'a']++;
    }
    bool found=false;
    for (int i = r; i > n/2+1; --i) {
      int c=s[i-1]-'a';
   //   cout<<"i2="<<i-1<<" "<<c<<endl;
      if (cnt[c]>0) {
        cnt[c] -= 2;
        continue;
      }
      ans = min(ans, i-l+1);
      found=true;
      break;
      // cnt[s[i-1]-'a']--;
      // if (cnt[c] > 0) {
      //   cnt[c]--;
      //   int j;
      //   for (j=0;j<26; ++j) {
      //     if (cnt[j]&1) break;
      //   }
      //   if (j>=26) {
      //     continue;
      //   } else {
      //     ans=min(ans, i-l+1);
      //     found=true;
      //     break;
      //   }
      // }
    }
    if (!found) {
      ans=min(ans, n/2-l+2);
    }
  //  cout<<"ans2="<<ans<<endl;
    for (int i = 0; i < 26; ++i) {
      cnt[i]=0;
    }
    for (int i=l;i<=r; ++i) {
   //   cout<<"i="<<i-1<<" "<<s[i-1]-'a'<<endl;
      cnt[s[i-1]-'a']++;
    }
    found=false;
    for (int i = l; i < n/2; ++i) {
      int c=s[i-1]-'a';
    //  cout<<"i2="<<i-1<<" "<<c<<endl;
      if (cnt[c]>0) {
        cnt[c] -= 2;
        continue;
      }
      ans = min(ans, r-i+1);
      found=true;
      break;
      // cnt[c]--;
      // if (cnt[c]>0) {
      //   cnt[c]--;
      //   int j;
      //   for (j=0;j<26; ++j) {
      //     if (cnt[j]&1) break;
      //   }
      //   if (j>=26) {
      //     continue;
      //   } else {
      //     ans = min(ans, r-i+1);
      //     found=true;
      //     break;
      //   }
      // }
    }
    if (!found) {
      ans=min(ans, r-n/2+1);
    }
    printf("%d\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
