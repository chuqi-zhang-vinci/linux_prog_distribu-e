#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "utils_v1.h"

const char *const MESSAGE_VIVANT = "Mon fils est toujours en vie\n";
const char *const MESSAGE_DOWN = "Mon fils est down\n";


// on met ce fag a true qd on recoit le signal alrm
volatile sig_atomic_t sigusr_received = 0;


// on met ce signal a true ad on recoir le signal sigusr
volatile sig_atomic_t alarm_received = 0;

void sigusr1_handler (int sig) {
	sigusr_received = 1;
}


void alrm_handler() {
	alarm_received = 1;
}


int main(int argc, char const *argv[])
{
	pid_t childID = fork();
	// PERE
	if (childID > 0) {
		/* lancement d'un compte à rebours de 8 secondes */
		//TODO
		ssigaction(SIGUSR1,  sigusr1_handler);
		ssigaction(SIGALRM, alrm_handler);
		alarm(8);

		while (true) {
			if (sigusr_received) {
				alarm(8);
				sigusr_received = 0;
				printf("%s", MESSAGE_VIVANT);
			}

			if(alarm_received) {
				printf("%s", MESSAGE_DOWN);
				exit(5);
			}
		}
	}
	// FILS
	else {
		/* lancement d'un compte à rebours de 3 secondes */
		//TODO
		ssigaction(SIGALRM, alrm_handler);
		alarm(3);

		while (true) {
			if(alarm_received) {
				skill(getppid(), SIGUSR1);
				alarm(3);
				alarm_received = 0;
			}
		}
	}
	return 0;
}