A. 两指针扫，扫到某一段[i,j]满足条件就把(i-1)%k的部分和[i,j]中比s多的部分都删掉。

C. 直接dp。dp[i]的cost由dp[j](j<i)转移得到。

   但是我们要知道的是，以j为结尾的suffix有没有出现在以i结尾的prefix里，因此我们dp2[i,j]表示以i结尾的suffix和以j结尾的prefix最长common后缀。
