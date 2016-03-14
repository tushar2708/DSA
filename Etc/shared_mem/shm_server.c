#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
//#include <stdio.h>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>

#define SHMSZ     27

main()
{
		char c;
		int shmid;
		key_t key;
		char *shm, *s;

		/*
		 * We'll name our shared memory segment
		 * "5678".
		 */
		key = 5678;

		/*
		 * Create the segment.
		 */
		if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
				perror("shmget");
				exit(1);
		}

		/*
		 * Now we attach the segment to our data space.
		 */
		if ((shm = shmat(shmid, NULL, 0)) == (void *) -1) {
				perror("shmat");
				exit(1);
		}

		/*
		 * Now put some things into the memory for the
		 * other process to read.
		 */
		s = shm;

		for (c = 'a'; c <= 'z'; c++)
				*s++ = c;
		*s = NULL;

		/*
		 * Finally, we wait until the other process 
		 * changes the first character of our memory
		 * to '*', indicating that it has read what 
		 * we put there.
		 */
		while (*shm != '*')
				sleep(1);

		printf("SHM_SERVER : first character changed to * by chm_slient\n");

		/* detach from the segment: */
		if (shmdt(shm) == -1) {
				perror("shmdt");
				exit(1);
		}


		exit(0);
}
