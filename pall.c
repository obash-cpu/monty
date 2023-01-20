#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EXIT_FAILURE 1
/**
 * push - pushes an element onto the stack
 * @stack: pointer to the head of the stack
 * @data: integer data to be pushed onto the stack
 */
void push(struct stack **stack, int data)
{
	struct stack *new = malloc(sizeof(struct stack));

	new->data = data;
	new->next = *stack;
	*stack = new;
}
/**
 * pall - prints an element onto the stack
 * @stack: pointer to the head of the stack
 * @data: integer data to be pushed onto the stack
 */
void pall(struct stack *stack)
{
	struct stack *temp = stack;

	while (temp)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}
/**
 *  main - entry point of the program
 *  @argc: number of command line arguments
 *  @argv: array of command line arguments
 */
int main(int argc, char **argv)
{
	struct stack *stack = NULL;
	int i;

	for (i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "push") == 0)
		{
			i++;
			if (i >= argc)
			{
				printf("L%d: usage: push integer\n", i);
				return (EXIT_FAILURE);
			}
			int value = atoi(argv[i]);

			push(&stack, value);

		}
		else if (strcmp(argv[i], "pall") == 0)
		{
			pall(stack);
		}
	}
	return (0);
}
