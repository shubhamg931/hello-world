#include <bits/stdc++.h>
using namespace std;

void count_sort(int a[], int n, int d)
{
  int count[10], dup[n];
  memset(count,0,sizeof(count));
  int base = pow(10,d);
  for(int i=0;i<n;i++)
  {
    // finding the (d+1)th digit from right for each element 
    int digit = (a[i]/base)%10;
    count[digit]++;
  }
  for(int i=1;i<10;i++)
  {
    count[i] += count[i-1];
  }
  for(int i=n-1;i>=0;i--)
  {
    int digit = (a[i]/base)%10;
    dup[count[digit]-1] = a[i];
    count[digit]--;
  }
  for(int i=0;i<n;i++)
  {
    a[i] = dup[i];
  }
}

void radix_sort(int a[], int n)
{
  // max_digits stores the maximum number of digits in the largest number
  int max_digits = log10(a[0])+1;
  for(int i=0;i<n;i++)
  {
    max_digits = max(max_digits,int(log10(a[i])+1));
  }
  for(int i=0;i<max_digits;i++)
  {
    // calling count_sort as subroutine to sort the array considering 
    // (i+1)th digit from right as key
    // counting sort is stable sort
    count_sort(a,n,i);
  }
}

int main() {
  int n;
  // size of array
  cin>>n;
  int a[n];
  // array to be sorted
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  radix_sort(a,n);
  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
}
