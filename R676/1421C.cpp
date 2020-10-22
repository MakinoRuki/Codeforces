#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 20005
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
string s;
int main() {
	cin>>s;
	int n = s.size();
	cout<<3<<endl;
	cout<<"L"<<" "<<2<<endl;
	cout<<"R"<<" "<<2<<endl;
	cout<<"R"<<" "<<2*n-1<<endl;
	return 0;
}
