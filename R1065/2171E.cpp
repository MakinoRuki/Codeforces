
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
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int b[N];
int p[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    // int id0=-1,id1=-1;
    // for (int i =1; i <= n; ++i) {
    //   scanf("%d", &a[i]);
    // }
    vector<int> ans;
    ans.clear();
   // ans.push_back(1);
    for (int i = 2; i <= n; ++i) {
      p[i]=-1;
    }
    vector<int> tmp;
    tmp.clear();
    tmp.push_back(1);
    for (int i = 2; i <= n; ++i) {
      if (p[i] < 0) {
        int cnt=0;
        for (int j = 2*i; j <= n; j += i) {
          if (p[j]<0) {
            cnt++;
            p[j]=i;
          }
        }
        if (cnt==0) {
          tmp.push_back(i);
        }
      }
    }
    for (int i = 2; i <= n; ++i) {
      p[i]=-1;
    }
    int cur=0;
    int num=1;
    for (int i = 2; i <= n; ++i) {
      if (p[i] < 0) {
      //  cout<<"i="<<i<<endl;
        vector<int> v;
        v.clear();
        v.push_back(i);
        for (int j = i*2; j <= n; j += i) {
          if (p[j] <0) {
            v.push_back(j);
            p[j]=i;
          }
        }
        if (v.size()>1) {
          for (int j = 0; j < v.size(); ++j) {
            ans.push_back(v[j]);
          //  cout<<"j="<<j<<" "<<v[j]<<" "<<cur<<" "<<tmp[cur]<<endl;
            // 隔两个就插进去最优
            if (cur<tmp.size() && !num) {
              ans.push_back(tmp[cur]);
              cur++;
            }
            num = !num;
          }
        }
      }
    }
    while(cur < tmp.size()) {
      ans.push_back(tmp[cur++]);
    }
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d ", ans[i]);
    }
    cout<<endl;
  }
  return 0;
}
