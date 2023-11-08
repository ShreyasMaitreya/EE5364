#include<stdio.h>
#include<pthread.h>
#include<time.h>
#define max_bound 1000000

void *even_1()
{
    long int a =0;
    while(a<=max_bound/4)
    {
        if (a%2 == 0)
        {
            ;
        }
        a++;

    }
}

void *even_2()
{
    long int a =1+(max_bound)/4;
    while(a>max_bound/4 && a<=max_bound/2)
    {
        if (a%2 == 0)
        {
            ;
        }


        a++;

    }
}

void *even_3()
{
    long int a =1+(max_bound)/2;
    while(a>max_bound/2 && a<=3*max_bound/4)
    {
        if (a%2 == 0)
        {
            ;
        }
        a++;
    }
}

void *even_4()
{
    long int a =1+(3*(max_bound))/4;
    while(a>3*max_bound/4 && a<=max_bound)
    {
        if (a%2 == 0)
        {
            ;
        }
        a++;
    }
}

int main()
{
    clock_t t;
    int cpus = 4;
    pthread_t thread[cpus];

    int j = 1;
    pthread_create(&thread[0], NULL, *even_1, &j);
    pthread_create(&thread[1], NULL, *even_2, &j);
    pthread_create(&thread[2], NULL, *even_3, &j);
    pthread_create(&thread[3], NULL, *even_4, &j);
    for(int i=0; i<cpus; i++)
    {
        pthread_join(thread[i], NULL);
    }
    t = (clock()-t)/(CLOCKS_PER_SEC*1e9);
    printf("Number of cycles for uniform load = %ld", t);
    return 0;
}