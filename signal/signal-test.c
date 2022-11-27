#include<signal.h>
#include<stdio.h>
#include<stdlib.h>

static void sigHandler(int sig) {
    printf("Ouch!\n");
}

int main(int argc, char* argv[]) {
    int j;
    if(signal(SIGINT, sigHandler) == SIG_ERR) {
        printf("signal install error");
        exit(-1);
    }

    for(j = 0; ; j++) {
        printf("%d\n", j);
        sleep(3);
    }
}