#include "monty.h"

/**
 * err - Prints appropiate error messages determined by error code.
 * @error_code: The error codes are the following:
 * (1) ~> The user does not give any file or more than one file to the program.
 * (2) ~> The file provided is not a file that can be opened or read.
 * (3) ~> The file provided contains an invalid instruction.
 * (4) ~> When the program is unable to malloc more memory.
 * (5) ~> When the param passed to the instruction `push` is not int.
 * (6) ~> When the stack is empty for pint.
 * (7) ~> When the stack is empty for pop.
 * (8) ~> When stack is too short for op.
 */

void err(int error_code, ...)
{
va_list ag;
char *op;
int l_num;

va_start(ag, error_code);
 
switch (error_code)
{
case 1:
printf("Usage: monty <file>\n");
break;
case 2:
printf("Error: Cannot open file %s\n",
va_arg(ag, char *));
break;
case 3:
l_num = va_arg(ag, int);
op = va_arg(ag, char *);
printf("L%d: unknown instruction %s\n", l_num, op);
break;
case 4:
printf("Error: malloc failed\n");
break;
case 5:
printf("L%d: usage: push integer\n", va_arg(ag, int));
break;
default:
break;
}
free_nodes();
exit(EXIT_FAILURE);
}

/**
 * more_err - handles errors.
 * @error_code: The error codes are the following:
 * (6) ~> When the stack is empty for pint.
 * (7) ~> When the stack is empty for pop.
 * (8) ~> When stack is too short for operation.
 * (9) ~> Division by zero.
 */
void more_err(int error_code, ...)
{
va_list ag;
char *op;
int l_num;

va_start(ag, error_code);

switch (error_code)
{
case 6:
printf("L%d: can't pint, stack empty\n",
va_arg(ag, int));
break;
case 7:
printf("L%d: can't pop an empty stack\n",
va_arg(ag, int));
break;
case 8:
l_num = va_arg(ag, unsigned int);
op = va_arg(ag, char *);
printf("L%d: can't %s, stack too short\n", l_num, op);
break;
case 9:
printf("L%d: division by zero\n",
va_arg(ag, unsigned int));
break;
default:
break;
}

free_nodes();

exit(EXIT_FAILURE);
}

/**
 * string_err - handles errors.
 * @error_code: The error codes are the following:
 * (10) ~> The no. in a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */

void string_err(int error_code, ...)
{
va_list ag;
int l_num;

va_start(ag, error_code);
l_num = va_arg(ag, int);

switch (error_code)
{
case 10:
printf("L%d: cannot pchar; value out of range\n", l_num);
break;
case 11:
printf("L%d: cannot pchar; stack empty\n", l_num);
break;
default:
break;
}

free_nodes();

exit(EXIT_FAILURE);
}