
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
#define M 8002
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    int ns=0;
    int id=-1;
    for (int i = 0;i < s.size(); ++i) {
      if (s[i] == '*') {
        id = i;
        ns++;
      }
    }
    if (ns >= 2) {
      puts("-1");
    } else {
      if (ns == 1) {
        int ls=0,rs=0;
        for (int j = id-1; j >= 0; --j) {
          if (s[j] != '<') ls++;
        }
        for (int j = id+1; j < s.size(); ++j) {
          if (s[j] != '>') rs++;
        }
        if (!ls && !rs) {
          int mx=max(id,(int)s.size()-1-id)+1;
          printf("%d\n", mx);
        } else {
          puts("-1");
        }
      } else {
        int n0=0,n1=0;
        int ans=-1;
        int i;
        for (i = 0; i < s.size(); ++i) {
          if (i+1<s.size() && s[i] == '>' && s[i+1] == '<') {
            break;
          }
          if (s[i] == '<') n0++;
          else n1++;
        }
        if (i < s.size()) puts("-1");
        else printf("%d\n", max(n0, n1));
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
