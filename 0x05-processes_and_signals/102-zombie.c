#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * infinite_while - Run an infinite while loop.
 *
 * Return: This function never returns.
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
}

/**
 * main - Creates five zombie processes.
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t pid;
	int cnt = 0;

	while (cnt < 5)
	{
		pid = fork();
		if (pid > 0)
		{
			printf("Parent: Zombie process created, PID: %d\n", pid);
			cnt++;
		}
		else if (pid == 0)
		{
			printf("Child: PID: %d\n", getpid());
			exit(0);
		}
		else
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
	}

	/* Parent process waits for all children to exit */
	while (wait(NULL) > 0)
		;

	/* Infinite loop to keep the process alive */
	infinite_while();

	return (EXIT_SUCCESS);
}
