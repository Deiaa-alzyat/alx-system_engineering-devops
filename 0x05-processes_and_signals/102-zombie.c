#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*Function declaration*/
int infinite_while(void);

/**
 * main - Creates five zombie processes.
 * Return: Always 0.
 */
int main(void)
{
	pid_t pid;
	char count = 0;

	while (count < 5)
	{
		pid = fork();
		if (pid > 0)
		{
			printf("Zombie process created, PID: %d\n", pid);
			count++;
		}
		else if (pid == 0)
		{
			/*Child process*/
			sleep(1);
			exit(0);
		}
		else
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
	}

	infinite_while();

	return (EXIT_SUCCESS);
}

/**
 * infinite_while - Run an infinite while loop.
 * Return: This function never returns.
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}
