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
#define N 2000
#define M 22
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
void remove0(string& s) {
  reverse(s.begin(), s.end());
  while(s.size() > 1 && s.back() == '0') {
    s.pop_back();
  }
  reverse(s.begin(), s.end());
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    string x="";
    string y="";
    int s1=0,s2=0;
    n = (int)s.size();
    for (int i = 0; i < n; ++i) {
      int d = s[i]-'0';
      if (d % 2 == 0) {
        d/=2;
          x.push_back('0'+d);
          y.push_back('0'+d);
      } else {
        d/=2;
        if (s1 > s2) {
          x.push_back('0'+d);
          y.push_back('0'+d+1);
          s1+=d;
          s2+=d+1;
        } else {
          y.push_back('0'+d);
          x.push_back('0'+d+1);
          s1+=d+1;
          s2+=d;
        }
      }
    }
    remove0(x);
    remove0(y);
    cout<<x<<" "<<y<<endl;
  }
  return 0;
}
