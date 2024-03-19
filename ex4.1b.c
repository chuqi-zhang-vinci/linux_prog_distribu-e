#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "utils_v1.h"

const char *const MESSAGE = "signal SIGUSR1 reçu !\n";

volatile sig_atomic_t end = 0;


void sigusr1_handler (int sig) {
    const size_t sz = strlen(MESSAGE);
    write(1, MESSAGE, sz);

    end = 1;
}


void childTask() {
    while(end == 0) {
        sleep(1);
    }
}



int main(int argc, char const *argv[])
{

    struct sigaction action = {0};
    action.sa_handler = sigusr1_handler;


    int ret = sigaction(SIGUSR1, &action, NULL);
    checkNeg(ret, "erreur sigaction 1");

    fork_and_run0(childTask);
    return 0;
}