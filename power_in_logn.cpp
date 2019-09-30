#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;

ll power(ll a,ll b)
{
  ll res = 1;
  while(b>0)
  {
    if(b&1)
    {
      res = (res*a)%mod;
    }
    a = (a*a)%mod;
  }
  return res;
}

int main()
{
  cout<<power(2,1000);
  return 0;
}
