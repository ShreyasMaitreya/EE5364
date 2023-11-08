#include <stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define max_bound 1000000

void *prime_1()
{
    long int n = 2;
    for(long int i =1; i<=max_bound/4; i++)
    {
        long int count = 0;
        for(long int j = 1; j<=max_bound/8; j++)
        {
            if (i%j == 0)
            {
                count++;
                break;
            }
            if(count==0 && i!=1)
            {
                ;
            }
            count = 0;
        }
    }
}
void *prime_2()
{
    long int n = 2;
    for(long int i = 1+max_bound/4; i < max_bound/2; i++)
    {
        long int count = 0;
        for(long int j = 1; j<=max_bound/4; j++)
        {
            if (i%j == 0)
            {
                count++;
                break;
            }
            if(count==0 && i!=1)
            {
                ;
            }
            count = 0;
        }
    }
}

void *prime_3()
{
    long int n = 2;
    for(long int i = max_bound/2; i < 3*max_bound/4; i++)
    {
        long int count = 0;
        for(long int j = 1; j<=3*max_bound/8; j++)
        {
            if (i%j == 0)
            {
                count++;
                break;
            }
            if(count==0 && i!=1)
            {
                ;
            }
            count = 0;
        }
    }
}

void *prime_4()
{
    long int n = 2;
    for(long int i = 3*max_bound/4; i <= max_bound; i++)
    {
        long int count = 0;
        for(long int j = 1; j<=max_bound/2; j++)
        {
            if (i%j == 0)
            {
                count++;
                break;
            }
            if(count==0 && i!=1)
            {
                ;
            }
            count = 0;
        }
    }
}




int main()
{
    clock_t t;
    int cpus = 4;
    pthread_t thread[cpus];
    int j = 1;
    pthread_create(&thread[0], NULL, *prime_1, &j);
    pthread_create(&thread[1], NULL, *prime_2, &j);
    pthread_create(&thread[2], NULL, *prime_3, &j);
    pthread_create(&thread[3], NULL, *prime_4, &j);
    for(int i=0; i<cpus; i++)
    {
        pthread_join(thread[i], NULL);
    }
    t = (clock()-t)/CLOCKS_PER_SEC;
    printf("Number of cycles for uniform load = %ld", t);

    return 0;
}
