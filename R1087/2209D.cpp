
#include <iostream>
#include <sstream>
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
#define N 2000005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int p[N];
string calc(int r, int g, int b) {
  set<pair<int,char>> ss;
  ss.clear();
  ss.insert(make_pair(r, 'R'));
  ss.insert(make_pair(g, 'G'));
  ss.insert(make_pair(b, 'B'));
  int nrg=0,nrb=0,ngb=0;
  while(ss.size() > 1) {
    auto pr1 = *ss.rbegin();
    ss.erase(pr1);
    auto pr2 = *ss.rbegin();
    ss.erase(pr2);
    string tmp = "";
    tmp.push_back(pr1.second);
    tmp.push_back(pr2.second);
    if (tmp == "RG" || tmp == "GR") {
      nrg++;
    } else if (tmp == "RB" || tmp == "BR") {
      nrb++;
    } else {
      ngb++;
    }
    pr1.first--;
    if (pr1.first > 0) ss.insert(pr1);
    pr2.first--;
    if (pr2.first > 0) ss.insert(pr2);
  }
  string res="";
  if (ss.size() > 0 && (*ss.rbegin()).second == 'G') {
    res += "G";
    while(nrg) res += "RG", nrg--;
    bool f=false;
    while(ngb) {
      res += "BG", ngb--;
      f=true;
    }
    if (f) {
      while(nrb) res += "BR", nrb--;
    } else {
      while(nrb) res+= "RB", nrb--;
    }
  } else if (ss.size() > 0 && (*ss.rbegin()).second == 'R') {
    res += "R";
    while(nrg) res += "GR", nrg--;
    bool f=false;
    while(nrb > 0)
				res += "BR",nrb--,f = true;
			if(f){
				while(ngb > 0)
					res += "BG",ngb--;
			}
			else{
				while(ngb > 0)
					res += "GB",ngb--;
			}
  } else {
    if (ss.size() > 0 && (*ss.rbegin()).second == 'B') res += "B";
    while(ngb > 0)
				res += "GB",ngb--;
			bool f = false;
			while(nrb > 0)
				res += "RB", nrb--,f = true;
			if(f){
				while(nrg > 0)
					res += "RG",nrg--;
			}
			else{
				while(nrg > 0)
					res += "GR", nrg--;
			}
  }
  return res;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int h;
    int r,g,b;
    scanf("%d%d%d", &r, &g, &b);
    string ans="";
    if (r >= g && r >= b) {
      if (r >= g+b) {
        for (int i = 1; i <= r; ++i) {
          ans += "R";
          if (b) {
            ans +="B";
            b--;
          } else if (g) {
            ans += "G";
            g--;
          } else {
            break;
          }
        }
      } else {
        ans = calc(r, g, b);
      }
    } else if (g >= r && g >= b) {
      if (g >= r+b) {
        for (int i = 1; i <= g; ++i) {
          ans += "G";
          if (r) {
            ans +="R";
            r--;
          } else if (b) {
            ans += "B";
            b--;
          } else {
            break;
          }
        }
      } else {
        ans = calc(r, g, b);
      }
    } else {
      if (b >= r+g) {
        for (int i = 1; i <= b; ++i) {
          ans += "B";
          if (r) {
            ans +="R";
            r--;
          } else if (g) {
            ans += "G";
            g--;
          } else {
            break;
          }
        }
      } else {
        ans = calc(r, g, b);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}

