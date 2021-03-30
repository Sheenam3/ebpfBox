// Program to display Hi if its even else Hello

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

int goNum();
void sayHiorHello(int);

int goNum(){

    int number;
    number = rand()%10;
    sayHiorHello(number);
    return number;

}

void sayHiorHello(int number){

        if (number % 2 == 0) {
                printf("Hi");
        }

        else printf("Hello");
}

int main() {

    while( 1 ) {
        int i = goNum();
        sleep(1);
        printf("------------");
        printf("No is: %d \n", i);
    }
    return 0;
}
