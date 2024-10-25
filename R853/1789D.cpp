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
#define N 500005
#define M 110
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
vector<int> ans;
string sa,sb;
bool check1() {
  string s1 = sa;
  string s2 = sb;
  int l=-1,r=-1;
  for (int i = 0; i < n; ++i) {
    if (s1[i] == '1') {
      l = i;
      break;
    }
  }
  for (int i = l+1; i < n; ++i) {
    if (s1[i] != s2[i]) {
      ans.push_back(-abs(l-i));
      int dt = abs(l-i);
      for (int j = n-1; j >=0; --j) {
        int res = s1[j]-'0';
        if (j - dt >= 0) {
          res ^= (s1[j-dt]-'0');
        }
        s1[j] = res+'0';
      }
    }
    //cout<<"i="<<i<<" "<<s1<<endl;
  }
  for (int i = n-1; i > l; --i) {
    if (s1[i] == '1') {
      r = i;
      break;
    }
  }
  for (int i = l; i >= 0; --i) {
    if (s1[i] != s2[i]) {
      if (r < 0) {
        ans.clear();
        return false;
      }
      ans.push_back(abs(r-i));
      int dt = abs(r-i);
      for (int j = 0; j < n; ++j) {
        int res= s1[j]-'0';
        if (j + dt < n) {
          res ^= s1[j+dt]-'0';
        }
        s1[j] = res+'0';
      }
    }
  }
  return true;
}
bool check2() {
  string s1 = sa;
  string s2 = sb;
  int l=-1,r=-1;
  for (int i = n-1; i > 0; --i) {
    if (s1[i] == '1') {
      r = i;
      break;
    }
  }
  for (int i = r-1; i >= 0; --i) {
    if (s1[i] != s2[i]) {
      ans.push_back(abs(r-i));
      int dt = abs(r-i);
      for (int j = 0; j < n; ++j) {
        int res= s1[j]-'0';
        if (j + dt < n) {
          res ^= s1[j+dt]-'0';
        }
        s1[j] = res+'0';
      }
    }
    //cout<<"i="<<i<<" "<<s1<<endl;
  }
  for (int i = 0; i < n; ++i) {
    if (s1[i] == '1') {
      l = i;
      break;
    }
  }
  for (int i = r; i < n; ++i) {
    if (s1[i] != s2[i]) {
      if (l < 0) {
        ans.clear();
        return false;
      }
      ans.push_back(-abs(l-i));
      int dt = abs(l-i);
      for (int j = n-1; j >=0; --j) {
        int res = s1[j]-'0';
        if (j - dt >= 0) {
          res ^= (s1[j-dt]-'0');
        }
        s1[j] = res+'0';
      }
    }
  }
  return true;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    cin>>sa>>sb;
    bool z1 = true, z2 = true;
    for (int i = 0; i < n; ++i) {
      if (sa[i] == '1') z1 = false;
      if (sb[i] == '1') z2 = false;
    }
    if (z1 != z2) {
      puts("-1");
      continue;
    }
    ans.clear();
    bool ok1 = check1();
  //  cout<<"ok="<<ok1<<endl;
    if (ok1) {
      printf("%d\n", (int)ans.size());
      if (ans.size()>0) {
        for (int i = 0; i < ans.size(); ++i) {
          printf("%d ",ans[i]);
        }
        cout<<endl;
      }
    } else {
      check2();
      printf("%d\n", (int)ans.size());
      if (ans.size()>0) {
        for (int i = 0; i < ans.size(); ++i) {
          printf("%d ", ans[i]);
        }
        cout<<endl;
      }
    }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

