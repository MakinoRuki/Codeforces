F. 从低到高dp，dp[i][0]表示把第i为从低位全为0加1的步数，d[i][1]表示把第i位从l的低位开始变到给它+1的步数。

G. 假设第一种n个第二种m个那么列式子floor(x-n*a)/b*a+n*b<=y。因此n的极值就是(b*y-a*x)/(b^2-a^2)。

   因为涉及到取floor因此在极值附近枚举一些value，再加上端点{0,min(x/a,y/b)}。
