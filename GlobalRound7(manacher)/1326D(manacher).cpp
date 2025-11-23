
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
#define N 2000005
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
int a[N];
int P[2*N];
int nxt[2*N];
//求字符串中最大回文子串。
void manacher(string& tmp) {
  int R = 0, C = 0;
  for (int i = 0; i < tmp.size(); ++i) {
    if (i < R) {
      //维护当前右端点最大的回文子串的右端点R和中心C
      //如果i在R和C中间，那么可以利用i关于C的对称点mirror=2C-i，用P[mirror]更新P[i]
      //然后再继续扩展
      int mirror = 2*C - i;
      P[i] = min(R-i, P[mirror]);
    } else {
      P[i] = 0;
    }
    while(i + P[i] + 1 < tmp.size() && i-P[i]-1>=0 && tmp[i+P[i]+1]==tmp[i-P[i]-1]) {
      P[i]++;
    }
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }
}
int calc(string tmp) {
 // cout<<"tmp="<<tmp<<endl;
  for (int i = 0; i < tmp.size(); ++i) {
    nxt[i]=-1;
  }
  for (int i = 1; i < tmp.size(); ++i) {
    int id = nxt[i-1];
    while(id >= 0 && tmp[id+1] != tmp[i]) {
      id = nxt[id];
    }
    if (tmp[id+1] == tmp[i]) {
    //  cout<<"i="<<i<<" "<<i<<" "<<id+1<<endl;
      nxt[i] = id+1;
    }
  }
  return nxt[tmp.size()-1]+1;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      string s;
      cin>>s;
      n = (int)s.size();
      string s2 = "0";
      for (int i = 0; i < s.size(); ++i) {
        s2.push_back(s[i]);
        if (i < s.size()-1) {
          s2 += "#";
        } else {
          s2 += "1";
        }
      }
      manacher(s2);
      int l=0,r=n-1;
      //一定是先找到左右最大match。
      //如果xxxAyyy...Axxx中不先match到A，而是选择从A开始的串Ayyy求kmp找回文子串。
      //那么假如找到更长的yyyyyy，那么yyyyyy要么全部字符相等，要么yyy是yyyyyy的循环节。
      //而这两种情况都可以先match到A，然后选择yyy开始的串求kmp找到。
      while(l < r) {
        if (s[l] == s[r]) {
          l++;
          r--;
        } else {
          break;
        }
      }
      if (l < r) {
      //  cout<<"lr="<<l<<" "<<r<<endl;
        string res=s.substr(0, l);
      //  cout<<"res="<<res<<endl;
        string st = s.substr(l, r-l+1);
        string st2 = st;
        reverse(st2.begin(), st2.end());
        int ans=2*(l+1);
        int l1 = calc(st + "#" + st2);
     //   cout<<"l1="<<l1<<endl;
        int l2 = calc(st2+ "#" + st);
     //   cout<<"l2="<<l2<<endl;
        if (l1 > l2) {
          res += st.substr(0, l1);
        } else {
          res += st2.substr(0, l2);
        }
     //   cout<<"res2="<<res<<endl;
        res += s.substr(r+1, l);
        cout<<res<<endl;
      } else {
        cout<<s<<endl;
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
