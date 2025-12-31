
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
#define M 50
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int b[N];
bool check1(string& s) {
  bool found=false;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '1') found=true;
    else {
      if (found) return false;
    }
  }
  return true;
}
bool check2(string& s) {
  int l=0,r=(int)s.size()-1;
  while(l < r) {
    if (s[l] != s[r]) return false;
    l++;
    r--;
  }
  return true;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    int ans=-1;
    for (int i = 0; i < (1<<n)-1; ++i) {
      string t1="";
      string t2="";
      for (int j= 0; j < n; ++j) {
        if ((1<<j) & i) t1.push_back(s[j]);
        else t2.push_back(s[j]);
      }
      if (check1(t1) && check2(t2)) {
        ans = i;
        break;
      }
    }
    if (ans < 0) puts("-1");
    else {
      int cnt=0;
      for (int i = 0; i < n; ++i) {
        if ((1<<i) & ans) {
          cnt++;
        }
      }
      printf("%d\n", cnt);
      for (int i = 0; i < n; ++i) {
        if ((1<<i) & ans) {
          printf("%d ", i + 1);
        }
      }
      cout<<endl;
    }
  }
  return 0;
}
