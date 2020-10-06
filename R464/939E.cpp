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
#include <queue>
#include <cmath>
#define N 100005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int q;
vector<int> nums;
int main() {
	cin>>q;
	nums.clear();
	int j =-1;
	double sum=0.0;
	double cnt=0.0;
	for (int i = 1; i <= q; ++i) {
		int tp;
		scanf("%d", &tp);
		if (tp==1) {
			int x;
			scanf("%d", &x);
			nums.push_back(x);
		} else {
			double res;
			if (nums.size()==1) {
				res=0.0;
			} else if (nums.size()==2) {
				res=(double)nums.back()-(nums[0]+nums[1])*0.5;
			} else {
				if (j<0) {
					j=0;
					sum=nums[0];
					cnt++;
				}
				while(j+1<nums.size()-1) {
					if (sum+nums.back()>(cnt+1)*nums[j+1]) {
						sum += nums[j+1];
						cnt++;
						j++;
					} else {
						break;
					}
				}
				res=(double)nums.back()-(double)(sum+nums.back())/(double)(cnt+1);
			}
			printf("%.10lf\n", res);
		}
	}
	return 0;
}
