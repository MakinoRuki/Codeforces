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
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m;
int k;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    n = (int)s.size();
    int n2=0,n3=0;
    int tot=0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '2') n2++;
        else if (s[i] == '3') n3++;
        else {
            tot = (tot + (s[i]-'0'))%9;
        }
    }
    bool found=false;
    for (int i = 0; i <= n2; ++i) {
        int dt = ((2*i)+4*(n2-i))%9;
        dt = (tot + dt)%9;
       // cout<<"i="<<i<<" "<<dt<<" "<<n3<<endl;
        if (dt == 0) {
            found=true;
            break;
        } else if (dt == 3) {
            if (n3>=2) {
                found=true;
                break;
            }
        } else if (dt==6) {
            if (n3>=1) {
                found=true;
                break;
            }
        }
    }
    if (found) puts("YES");
    else puts("NO");
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

