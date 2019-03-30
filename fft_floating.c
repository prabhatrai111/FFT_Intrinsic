///   PRABHAT KUMAR RAI   ///
///     EE18MTECH01005    ///
///      FFT Floating     ///

#include <complex.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, g, c, e, i, f, h, j, k, l, n, m, num, rem, set, stage;
//printf("Enter # of FFT in 2's power : ");
//scanf("%d", &num);
    double complex input[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};//0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15
    num = 64;
    printf("%d point FFT floating point is done, but can be done for any point as per code\n", num);
    float var;
    double complex temp[num], BitRev[num];
    stage = log2(num);
    double PI = acos(-1);
    double complex z = I*(-2*PI/num);

    for ( i = 0; i < num; i++ )
         {         printf("input[%d]=%f\n", i, input[i]);    }


    /// Bit Reversal  ///
    for ( i = 0; i < num; i++ )
     {                   k = i;
                       set = 0;
                for ( n = 0; n <= ( stage - 1 ); n++ )
                 {     rem = k % 2;
                         k = k / 2;
                       set = rem * pow( 2, ( stage - 1 - n ) ) + set;
                 }
                 BitRev[i] = input[set];
     }

     ///    FFT addition    ///
      for( i = 1; i <= stage; i++)
     {
            int increment;
           increment = pow( 2, i );
     for( j = 0; j < num; j = j + increment )
       {
        int half = 1;
        for( k = j; k < ( j + increment ) ; k++ )
          {
          if( half <= increment/2 )
            {
             half++;
             temp[k] = BitRev[ ( increment/2 ) - 1 + half - 1 + j ] + BitRev[ k ];
            }
          else
            {
             temp[k] = BitRev[ k - half + 1 ] - BitRev[ k ];
            }
          }
        }
     ///   twiddle multiplication ///
      b = pow( 2, i-1);
      if ( i != stage )
            {           e = 2*increment;
                  for ( g = increment; g < num; g = g + e )
                   {    a = g;
                        l = 0;
                        n = a + increment;
                      for ( a = g; a < n; a++ )
                       {
                         temp[ a ] = temp[ a ] * cexp( z * l );
                         l = l + ( num / (b * 4));
                       }
                    }
            }
            else{ printf("fft is over");}
            for( m = 0; m < num; m++ )
               { BitRev[m] = temp[m];   }
     }
     printf("\n\n FFT content :\n");
     for(i = 0; i < num ; i++)
      { printf("fft[%d]=%f + %fi\n", i, creal(BitRev[i]), cimag(BitRev[i])); }
 return 0;
}
