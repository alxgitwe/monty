#ifndef MONTY_H
#define MONTY_H
#define  _POSIX_C_SOURCE 200809L


#include <unistd.h>
#include <stdio.h>
#include <ctype.h> 
#include <fcntl.h> 
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


typedef void (*open_function)(stack_t **, unsigned int);
extern stack_t *head;


/*file ops*/
void openf(char *fname);
int pl(char *buffer, int line_number, int frmt);
void rf(FILE *);
void ff(char *, char *, int, int);





/* */
stack_t *cr(int i);
void fn(void);
void ps(stack_t **, unsigned int);
void as(stack_t **, unsigned int);
void aq(stack_t **, unsigned int);
void cf(open_function, char *, char *, int, int);

void pt(stack_t **, unsigned int);
void ptp(stack_t **, unsigned int);
void np(stack_t **, unsigned int);
void swn(stack_t **, unsigned int);

/* */
void an(stack_t **, unsigned int);
void sno(stack_t **, unsigned int);
void dvn(stack_t **, unsigned int);
void mln(stack_t **, unsigned int);
void mon(stack_t **, unsigned int);

/* */
void prch(stack_t **, unsigned int);
void prst(stack_t **, unsigned int);
void rtl(stack_t **, unsigned int);

/* */
void errer(int errc, ...);
void merr(int errc, ...);
void sterr(int errc, ...);
void rtr(stack_t **, unsigned int);

#endif
