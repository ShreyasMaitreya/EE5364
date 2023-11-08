//calculating pi upto a specific number of digits can give an insight into both the clock rate and the floating point performance of the given CPU
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<pthread.h>

//calculating pi using lebniz expansion

int pi_calc()
{
    long int i, n;
    double sum=0.0, term, pi;

    printf("Enter number of terms: ");
    scanf("%ld", &n);

    /* Applying Leibniz Formula */
    for(i=0;i< n;i++)
    {
        term = pow(-1, i) / (2*i+1);
        sum += term;
    }
    pi = 4 * sum;

    printf("\nPI = %lf", pi);

    return 0;
}

int benchmark()

{
    clock_t t;
    float pi;
    t = clock();
    pi = pi_calc();
    printf("%f \n pi is calculated in ", pi);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    //number of clock cycles = clocks per second*execution time
    double cycles = time_taken*CLOCKS_PER_SEC/1000; //in windows, CLOCKS_PER_SEC returns time in milliseconds
    printf("%f seconds\n", time_taken);
    printf("%f cycles\n", cycles);

    return 0;
}

int main()
{
    benchmark();
    return 0;
}
