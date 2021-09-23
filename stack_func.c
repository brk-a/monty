#include "monty.h"

/**
 * pop_top - Adds a node to the stack.
 * @stack: Ptr to ptr to top node of the stack.
 * @line_number: Int representing the line no. of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;

if (stack == NULL || *stack == NULL)
more_err(7, line_number);

tmp = *stack;
*stack = tmp->next;
if (*stack != NULL)
(*stack)->prev = NULL;
free(tmp);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Ptr to a ptr to top node of the stack.
 * @line_number: Int representing the line no. of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
if (stack == NULL || *stack == NULL)
more_err(6, line_number);
printf("%d\n", (*stack)->n);
}

/**
 * add_to_stack - Adds a node to the stack.
 * @new_node: Ptr to the new node.
 * @ln: Int representing the line no. of the opcode.
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
stack_t *tmp;

if (new_node == NULL || *new_node == NULL)
exit(EXIT_FAILURE);
if (head == NULL)
{
head = *new_node;
return;
}
tmp = head;
head = *new_node;
head->next = tmp;
tmp->prev = head;
}

/**
 * print_stack - Adds a node to the stack.
 * @stack: Ptr to a ptr to top node of the stack.
 * @line_number: Int representing the line no. of of the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;

(void) line_number;
if (stack == NULL)
exit(EXIT_FAILURE);
tmp = *stack;
while (tmp != NULL)
{
printf("%d\n", tmp->n);
tmp = tmp->next;
}
}


/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Ptr to the new node.
 * @ln: Int representing the line n0. of the opcode.
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
stack_t *tmp;

if (new_node == NULL || *new_node == NULL)
exit(EXIT_FAILURE);
if (head == NULL)
{
head = *new_node;
return;
}
tmp = head;
while (tmp->next != NULL)
tmp = tmp->next;

tmp->next = *new_node;
(*new_node)->prev = tmp;
}
