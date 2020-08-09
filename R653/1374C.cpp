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
#define N 400005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
string s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d",&n);
		cin>>s;
		int minv = 0;
		int sum=0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '(') sum++;
			else sum--;
			minv = min(minv, sum);
		}
		cout<<abs(minv)<<endl;
	}
	return 0;
}
