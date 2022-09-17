#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int csum, msum;
void *runner(void *param);

int main(int argc, char *argv[]) {
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, runner, argv[1]);
    
    pthread_join(tid,NULL);
    int upper = atoi(argv[1]);
    for(int i = 1; i <= upper; i++)
            msum += i;
        printf("msum = %d\n",msum);
     
    int dif = csum - msum;
    printf("dif = %d\n",dif);
}

void *runner(void *param) {
    int upper = atoi(param);
    int i;
    csum = 0;
    if(upper > 0){
        for(i = 1; i <= 2 * upper; i++)
            csum += i;
        printf("csum = %d\n",csum);
    }
    pthread_exit(0);
}