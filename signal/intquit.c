#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

static void sigHandler(int sig) {
    static int count = 0;
    if(sig == SIGINT) {
        count++;
        printf("Caught SIGINT (%d)\n", count);
        return;
    }

    // SIGQUIT
    printf("Caught SIGQUIT - that's all folks!\n");
    exit(-1);
}

int main(int argc, char* argv[]) {
    if(signal(SIGINT, sigHandler) == SIG_ERR) {
        printf("install sig int handler err");
        exit(-1);
    }

     if(signal(SIGQUIT, sigHandler) == SIG_ERR) {
        printf("install sig quit handler err");
        exit(-1);
    }

    for (;;) {
        pause();
    }
}