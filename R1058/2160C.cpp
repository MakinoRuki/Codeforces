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
#define N 1000005
#define M 5002
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
ll a[N];
ll b[N];
bool check(string& s1, string& s2) {
  int sz=(int)s1.size();
  if (sz % 2) {
    if (s1[sz/2] == '0' && s1 == s2) {
      return true;
    }
    return false;
  } else {
    return s2 == s1;
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    if (n==0) {
      puts("Yes");
      continue;
    }
    if (n==1) {
      puts("No");
      continue;
    }
    string s="";
    while(n) {
      s.push_back((n%2)+'0');
      n/=2;
    }
    int sz=(int)s.size();
    string s2=s;
    reverse(s2.begin(), s2.end());
    if (check(s, s2)) {
        puts("Yes");
        continue;
    }
    bool found=false;
    for (int i = (sz+1)/2; i < sz; ++i) {
      s += "0";
      string s2 = s;
      reverse(s2.begin(), s2.end());
      if (check(s, s2)) {
        found=true;
        break;
      }
      s += "0";
      s2 = s;
      reverse(s2.begin(), s2.end());
      if (check(s, s2)) {
        found=true;
        break;
      }
    }
    if (found) puts("Yes");
    else puts("No");
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
