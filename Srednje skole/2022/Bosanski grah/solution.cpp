#include<iostream>
#include<cmath>

using namespace std;

#define MAXN 10

int n, k[MAXN], g[MAXN], best = 1000000000;

void rek( int i, int kis, int gor ) {
   if( i == n ) {
      if( gor > 0 && abs(kis-gor) < best ) best = abs(kis-gor);
   } else {
      rek( i+1, kis, gor );
      rek( i+1, kis*k[i], gor+g[i] );
   }
}

int main(void) {
   cin>>n;
   for( int i = 0; i < n; ++i )
      cin>>k[i]>>g[i];

   rek( 0, 1, 0 );

   cout<<best<<endl;
   return 0;
}
