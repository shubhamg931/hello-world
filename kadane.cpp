#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n,i,j;
  cin>>n;
  ll a[n+1],dp[n+1],ans;
  a[0] = dp[0] = 0;
  for(i=1;i<=n;i++)
  {
    cin>>a[i];
  }
  ans = a[1];
  for(i=1;i<=n;i++)
  {
    dp[i] = max(a[i],dp[i-1]+a[i]);
    ans = max(ans,dp[i]);
  }
  cout<<"Maximum sum: "<<ans;
  return 0;
}
