#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

/**
 * infinite_while - an infinite while loop
 * Return: 0
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - launches five zombie processes
 * Return: EXIT_SUCCESS
 */
int main(void)
{
	pid_t pid;
	char i;

	i = 0;

	while (i < 5)
	{
		pid = fork();
		if (pid > 0)
		{
			printf("Zombie process created, PID: %d\n", pid);
			sleep(1);
			i++;
		}
		else
			exit(0);
	}
	infinite_while();
	return (EXIT_SUCCESS);
}
