#include  <stdio.h>
#include "mymalloc.h"
#include <sys/time.h>
#include <stdlib.h>


int testC(){
    //Test0_a confirmed
    
    char *p;
    p = (char*)malloc(200);
    free(p+10);
    
    return 1;
}

int testD(){
    //Test0_b
    //confirmed
    //    printf("hey %s \n", ctime(&currentTime));
    int i =0;
    int *ptr;
    for( i = 0 ; i < 100;i++){
        ptr = malloc(sizeof(int));
        //  plist();
        free(ptr);
        //  plist();
    }
    
    return 1;
}

int testE(){
    //Test0_c //confirmed
    int *ptr = malloc(200);
    plist();
    free(ptr);
    plist();
    return 1;
}


int testF(){
    //Test0_d //confirmed
    
    int *ptra = malloc(10);
    int *ptrb = malloc(15);
    
    plist();
    free(ptra);
    plist();
    
    printf("%ls \n", ptrb);
    int *ptrc = malloc(20);
    plist();
    printf("\n");
    int *ptrd = malloc(25);
    plist();
    free(ptrc);
    plist();
    printf("\n");
    free(ptrd);
    plist();
    
    
    
    return 1;
}

int testG(){
    //Test0_e confirmed
    
    //char *array[] = malloc(5500);
    char *c = malloc(4999);
    plist();
    free(c);
    //  plist();
    
    
    // printf("%s \n", array[0]);
    //  printf("here:  %c \n", c[0]);
    return 1;
    
}
//Test0_f


int testH(){
    //Test 1 confirmed
    char *p;
    //int i = 0 ;
    p = malloc(1);
    plist();
    free(p);
    plist();
    return 1;
}

int testI(){
    //Test 1_a confirmed
    // (150 * 20 + 150 + (926+20))
    char *p;
    int i;
    for( i = 0 ; i < 150; i++){
        p = malloc(1);
        printf("%s \n", p);
        free(p);
    }
    plist();
    
    return 1;
}


int testJ(){
    //*********Test1_b confirmed
    char *p;
    p = malloc(20);
    char *b;
    b = malloc(50);
    plist();
    free(b);
    printf("%s %s \n", p,b );
    plist();
    return 1;
}

int testK(){
    
    ///*************Test 2 //confirmed
    //(100 * 17+ 100 ) + (2279+ 17)
    
    int *ptr[150];
    int i, j;
    for( i = 0 ; i< 150; i++){
        ptr[i] = malloc(1);
        printf("%ls \n", ptr[i]);
        if(i == 50){
            for( j= 0 ; j< 50; j++){
                free(ptr[j]);
            }
        }
        
        
    }
    
    plist();
    
    /*
     free(ptr[0]);
     free(ptr[1]);
     free(ptr[2]);
     free(ptr[3]);
     free(ptr[4]);
     free(ptr[5]);
     
     free(ptr[6]);
     free(ptr[7]);
     free(ptr[8]);
     free(ptr[9]);
     free(ptr[10]);
     //  free(ptr[11]);
     */
    return 1;
}
// plist();


int testL(){
    //******************Test 3
    
    char *p;
    p = (char *)malloc(100);
    
    plist();
    free(p);
    plist();
    free(p);
    return 1;
}


int testN(){
    //Test_c
    
    
    char *a;
    a = malloc(1);
    printf("%s \n", a);
    
    char*b;
    b = malloc(2);
    printf("%s \n", b);
    
    char *c;
    c = malloc(5);
    printf("%s \n",c);
    
    char *d;
    d = malloc(100);
    printf("%s \n", d);
    
    char *e;
    e = malloc(20);
    printf("%s \n", e);
    
    char* g;
    g = malloc(33);
    printf("%s \n", g);
    
    char* f;
    f = malloc(10000);
    printf("%s \n", f);
    
    plist();
    
    free(d);
    plist();
    free(b);
    plist();
    free(c);
    
    
    plist();
    free(c);
    
    free(d);
    plist();
    
    free(b);
    
    
    return 1;
}

///
int testO(){
    //***************test_lc1
    
    char *p;
    p = (char*)malloc(100);
    // plist();
    free(p);
    plist();
    
    p = (char*)malloc(100);
    free(p);
    
    
    return 1;
}

int testP(){
    //test_lc2
    
    char *p;
    p = (char*)malloc(4096);
    //  p = (char*)malloc(4096 - sizeof(struct block));
    plist();
    char *q;
    q = (char*)malloc(1);
    printf("%s \n", p);
    printf("%s \n", q);
    
    
    plist();
    
    return 1;
}

int testQ(){
    //test_lc3
    
    char* p;
    p = (char*)malloc(200);
    free(p+10);
    
    return 1;
}


//test_lc5

int testS(){
    
    char* a;
    char* b;
    char* c;
    char* d;
    char* e;
    
    a = (char*)malloc(1024);
    b = (char*)malloc(1024);
    c = (char*)malloc(1024);
    
    
    printf("%s \n", a);
    printf("%s \n", b);
    printf("%s \n", c);
    
    plist();
    free(c);
    
    plist();
    printf("\n");
    d = (char*)malloc(1400);
    plist();
    printf("%s \n", d);
    
    
    e = (char*)malloc(580);
    plist();
    printf("%s \n", e);
    //    plist();
    
    return 1;
}



int testAA(){
    //   char *p;
    int i =0;
    
    
    double tt = 0;
    
    
    double total = 0;
    int counter = 0;
    
    while(counter < 100){
        
        //  clock_t start = clock(), diff;
        
        
        struct timeval start1, end1;
        gettimeofday(&start1, NULL);
        
        char *a[150];
        int i = 0;
        for ( i = 0 ; i < 150; i++){
            a[i] = (char*)malloc(1);
            free(a[i]);
        }
        
        
        
        gettimeofday(&end1, NULL);
        tt+=((end1.tv_sec * 1000000 + end1.tv_usec)
             - (start1.tv_sec * 1000000 + start1.tv_usec));
        //       printf("%ld\n", ((end1.tv_sec * 1000000 + end1.tv_usec)
        //                        - (start1.tv_sec * 1000000 + start1.tv_usec)));
        
        counter++;
        
        
        
    }
    printf("mean time %f microseconds \n", tt);
    return 1;
    
}


int testBB(){
    
    int i =0;
    
    double tt = 0;
    
    
    double total = 0;
    int counter = 0;
    
    while(counter < 100){
        
        
        
        struct timeval start1, end1;
        gettimeofday(&start1, NULL);
        int *ptr[150];
        int i, j;
        for( i = 0 ; i< 150; i++){
            ptr[i] = malloc(1);
            printf("%ls \n", ptr[i]);
            if(i == 49 || i == 99 || i == 149){
                for( j= (i-49) ; j< i+1; j++){
                    free(ptr[j]);
                }
            }
        }
        
        gettimeofday(&end1, NULL);
        tt+=((end1.tv_sec * 1000000 + end1.tv_usec)
             - (start1.tv_sec * 1000000 + start1.tv_usec));
        counter++;
        
    }
    
    printf("mean time %f microseconds \n", tt);
    // printf("mean time: %f seconds \n", total/100 );
}

int testCC(){
    
    int nummalloc = 0;
    int numfreed = 0 ;
    int i = 0, j = 0;
    char *p[5000];
    int temp;
    int counter = 0;
    
    double tt = 0;
    
    while(counter < 100){
        
        struct timeval start1, end1;
        gettimeofday(&start1, NULL);
        
        for( i = 0 ; i < 5000;i++){
            p[i] = NULL;
        }
        
        for(i = 0 ; i < 5000; i++){
            temp = rand();
            
            if(nummalloc == 50){
                
                for( j = 0 ; j < 5000;j++){
                    if(numfreed  == 50){
                        break;
                    }
                    else if(p[j] != NULL){
                        free(p[j]);
                        numfreed++;
                    }
                }
                break;
            }
            else if(temp % 2 == 0 ){
                p[i] = malloc(1);
                nummalloc++;
            }else{
                
                if(p[i] != NULL){
                    free(p[i]);
                }
                else{
                    continue;
                }
                
                
                
                
            }
        }
        
        gettimeofday(&end1, NULL);
        tt+=((end1.tv_sec * 1000000 + end1.tv_usec)
             - (start1.tv_sec * 1000000 + start1.tv_usec));
       
	counter++; 
    }
    
    printf("mean time %f microseconds \n", tt);
    return 1;
}



int testDD(){
    
    int nummalloc = 0;
    int currentmallocsize =0 ;
    
    char *p[5000];
    int i,j;
    int temp;
    int indic;
    
    int counter = 0;
    
    double tt = 0;
    
    while(counter < 100){
        
        struct timeval start1, end1;
        gettimeofday(&start1, NULL);
        
        for( i = 0 ; i < 5000; i++){
            p[i] = NULL;
        }
        for ( i = 0 ; i < 5000; i++){
            temp = rand() % 65;
            indic = rand();
            
            if(currentmallocsize > 4085){
                printf("exceeded total memory size\n");
                break;
            }
            
            else if(nummalloc == 50){
                for( i = 0 ; i < 5000; i++){
                    if(p[i] == NULL){
                        continue;
                    }else{
                        free(p[i]);
                    }
                }
                break;
            }
            
            else if(indic % 2 ==0){

		if(temp<=0){
		temp = rand()%65;
}
                p[i] = malloc(temp);
                nummalloc++;
                currentmallocsize += temp;
            
}
            
            
        }
        
        gettimeofday(&end1, NULL);
        tt+=((end1.tv_sec * 1000000 + end1.tv_usec)
             - (start1.tv_sec * 1000000 + start1.tv_usec));
       counter++; 
        
    }
    
    printf("mean time %f microseconds \n", tt);
    //printf("mean time %f \n", total/100);
    return 1;
    
}


int testEE(){
    
    
    char *p[150];
    int i;
    double total;
    int counter = 0;
    
    double tt = 0;
  //  printf("true\n");
    
    while(counter < 100){
        //  printf("true\n");
        clock_t start = clock();
        
        struct timeval start1, end1;
        gettimeofday(&start1, NULL);
        
        
        //  int temp;
        for( i=  0 ; i < 150; i++){
            p[i] = NULL;
        }
        //printf("true\n");
        
        for( i = 0 ; i < 150; i++){
            p[i] = malloc(1);
            free(p[i]);
            p[i] = malloc(2);
            
        }
        
        for( i = 0;  i < 150; i++){
            if(p[i] != NULL){
                free(p[i]);
            }
        }
        
        gettimeofday(&end1, NULL);
        tt+=((end1.tv_sec * 1000000 + end1.tv_usec)
             - (start1.tv_sec * 1000000 + start1.tv_usec));
        
        counter++;
    }
    printf("mean time %f microseconds \n", tt);
    //  printf("mean time %f \n", total/100);
    return 1;
}


int testFF(){
    
    
    double tt = 0;
    
    char *p[150];
    int i;
    int counter = 0 ;
    
    while(counter < 100){
        
        struct timeval start1, end1;
        gettimeofday(&start1, NULL);
        
        clock_t start = clock();
        
        
        for( i=  0 ; i < 150; i++){
            p[i] = NULL;
        }
        
        for( i = 0 ; i < 150;i++){
            p[i+1] = malloc(1);
        }
        
        for(i = 0 ; i <150 ;i++){
            if(p[i] != NULL){
                free(p[i]);
            }
        }

        gettimeofday(&end1, NULL);
        tt+=((end1.tv_sec * 1000000 + end1.tv_usec)
             - (start1.tv_sec * 1000000 + start1.tv_usec));
       
	counter++; 
        
    }
    printf("mean time %f microseconds \n", tt);
    return 1;
    
    
}

int main(int argc, char **argv)
{
    
    
    
    
    // testC();
    //testD();
    //testE();
    //testF();
    //testG();
    //testH();
    //testI();
    //testJ();
    // testK();
    //testL();
    
    //testN();
    //testO();
    //testP();
    //testQ();
    // testS();
    
    testAA(); //pdf A
    testBB(); //pdf B
    testCC(); // pdf C
    testDD(); //pdf D
    testEE(); //pdf E
    testFF(); //pdf F
    
    
    
    
    
    
    return 1;
    
    
    
}


