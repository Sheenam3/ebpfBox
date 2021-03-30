// Program to display Hi if its even else Hello

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
int number;
int getNum();
#define N 10

int getNum(){

       number = rand()%10;
       return number;

}

void *sayHiorHello(){

    while(1) {
        int number = getNum();
        if (number % 2 == 0) {
                printf("Hi,num is %d\n", number);

        }

        else {
                printf("Hello,num is %d\n", number);
        }

        sleep(1);
     }


}

int main() {
   //Creating threads
    pthread_t workers[N];
    int count;
    printf("Starting Threads:\n");

    for(count = 0; count < N; ++count){
            if(pthread_create(&workers[count], NULL, sayHiorHello, NULL) != 0)
            {
                    fprintf(stderr, "Can't create thread #%d\n", count);
                    break;
            }
    }
    //this blocks the calling thread until it terminates
    for(int counter = 0; counter < count; ++counter){

            if(pthread_join(workers[counter], NULL) != 0)
            {
                    fprintf(stderr, "Can't join thread #%d\n", counter);
                    break;
            }
    }
   return 0;
}

