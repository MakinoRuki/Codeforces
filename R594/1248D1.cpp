#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
string s;
int getbt(string& x) {
	vector<int> pres(n+2);
	vector<int> prem(n+2);
	prem[0] = 0;
	pres[0] = 0;
	int sum=0;
	for (int i= 1; i <= n; ++i) {
		sum += (x[i-1] == '(' ? 1 : -1);
		pres[i] = sum;
		prem[i] = min(prem[i-1], sum);
	}
	sum = 0;
	int suf = 0;
	int tot=0;
	for (int i = n; i>=1; --i) {
		sum += (x[i-1] == '(' ? 1 : -1);
		suf = (x[i-1] == '(' ? suf + 1 : min(-1, suf-1));
		if (suf >= 0 && sum + prem[i-1] >= 0 && sum + pres[i-1] == 0) {
			tot++;
		}
	}
	return tot;
}
int main() {
	cin>>n>>s;
	int ans = getbt(s);
	int idx = -1;
	int idy = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			string t = s;
			swap(t[i], t[j]);
			int res=getbt(t);
			if (res > ans) {
				ans = res;
				idx = i+1;
				idy = j+1;
			}
		}
	}
	cout<<ans<<endl;
	if (idx >= 0) {
		cout<<idx<<" "<<idy<<endl;
	} else {
		cout<<1<<" "<<1<<endl;
	}
	return 0;
}
