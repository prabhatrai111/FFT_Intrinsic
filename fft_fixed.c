///   PRABHAT KUMAR RAI   ///
///     EE18MTECH01005    ///
///       FFT Fixed       ///

#include <complex.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, g, c, e, i, f, h, j, k, l, n, m, num, rem, set, stage;
    double complex input[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};//0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15
    num = 64;
    printf("%d point FFT floating point is done, but can be done for any point as per code\n", num);

    ///  Q(3,13)  ///

    float q_p = pow( 2, 13 ), q_p2 = pow(2,26);
    double complex temp[num], BitRev[num], q_input[num];
    stage = log2(num);
    double PI = acos(-1);
    double complex z = I*(-2*PI/num), var, vvar, vvarr;

    for ( i = 0; i < num; i++ )
         {    q_input[i] = round(q_p * input[i]);
          printf("q_input[%d]=%f\n", i, q_input[i]);    }


    /// Bit Reversal  ///
    for ( i = 0; i < num; i++ )
     {                   k = i;
                       set = 0;
                for ( n = 0; n <= ( stage - 1 ); n++ )
                 {     rem = k % 2;
                         k = k / 2;
                       set = rem * pow( 2, ( stage - 1 - n ) ) + set;
                 }
                 BitRev[i] = q_input[set];
     }

     ///    FFT Addition     ///
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
                       { vvar = cexp( z * l );
                         var = round( q_p * cexp( z * l)) + round(cimag(q_p * cexp( z * l)))*I;
                         temp[ a ] = temp[ a ] * vvar;
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
      { BitRev[i] = BitRev[i] / q_p;
        printf("fft[%d]=%f + %fi\n", i, creal(BitRev[i]), cimag(BitRev[i])); }
 return 0;
}

