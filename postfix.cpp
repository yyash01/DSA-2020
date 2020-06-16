/*Let the given expression be “2 3 1 * + 9 -“. We scan all elements one by one.
1) Scan ‘2’, it’s a number, so push it to stack.
Stack contains ‘2’
---------------------------------------------------
2) Scan ‘3’, again a number,
push it to stack, stack now contains ‘2 3’
(from bottom to top)
-------------------------------------------------------
3) Scan ‘1’, again a number, push it to stack,
stack now contains ‘2 3 1’
------------------------------------------------
4) Scan ‘*’, it’s an operator, pop two operands from stack,
apply the * operator on operands,
we get 3*1 which results in 3. We push the result ‘3’ to stack.
Stack now becomes ‘2 3’.
---------------------------------------
5) Scan ‘+’, it’s an operator, pop two operands from stack, apply the + operator on operands,
we get 3 + 2 which results in 5.
We push the result ‘5’ to stack. Stack now becomes ‘5’.
---------------------------------
6) Scan ‘9’, it’s a number,
we push it to the stack.
Stack now becomes ‘5 9’.
------------------------------------
7) Scan ‘-‘, it’s an operator,
pop two operands from stack, apply the – operator on operands,
we get 5 – 9 which results in -4. We push the result ‘-4’ to stack.
Stack now becomes ‘-4’.
------------------------------------
8) There are no more elements to scan,
we return the top element from stack
(which is the only element left in stack)*/

//postfix expression me koi brackets nhi hote

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct stack
{
	int info;
	struct stack *link;
};
typedef struct stack node;
node*top;

struct token
{
	char kind;
	int value;
};


#define LPAR '('
#define RPAR ')'
#define MINUS '-'
#define PLUS '+'
#define ADD '+'
#define SUBTRACT '-'
#define MULTIPLY '*'
#define DIVIDE '/'
#define MODULO '%'
#define FINISH '\0'
#define INT '0'

void skipspace();
void skipdigit();
struct token getnext_token();

void push (int);
int pop();
int isempty();
int isfull(node *);
int peek();
void initstack();


char expr[100];
int where = 0;

//function for skipping white_space
void skipspace()
{
	while (isspace(expr[where]))
		where++;
}

//function for skipping integer value
void skipdigit()
{
	while (isdigit(expr[where]))
		where++;
}

//function for getting next token
struct token getnext_token()
{
	struct token token;
	skipspace();
	if (isdigit(expr[where]))
	{
		sscanf(&expr[where], "%d", &token.value);
		token.kind = INT;
		skipdigit();
	}
	else
	{
		token.kind = expr[where];
		where++;
	}
	return token;
}

void push (int item)
{
	node *temp = (node*)malloc(sizeof(node));
	if (!isfull(temp))
	{
		temp->info = item;
		temp->link = top;
		top = temp;
	}
}

int pop()
{
	int item;
	if (!isempty())
	{
		node *temp;
		temp = top;
		item = temp->info;
		top = temp->link;
		free(temp);
		return item;
	}
	else
	{
		printf("WRONG POSTFIX ENTERED!!!\n");
		exit(0);
	}
}

int isempty()
{
	if (top == NULL)
		return 1;
	else
		return 0;
}

int isfull(node *temp)
{
	if (temp == NULL)
		return 1;
	else
		return 0;
}

void initstack()
{
	top = NULL;
}

int peek()
{
	return top->info;
}

void main()
{
	struct token token;
	int i, a, b;
	char ch;
	printf("Input Expression :");
	fgets(expr, 99, stdin);
	token = getnext_token();
	while (token.kind != FINISH)
	{
		if (token.kind == INT)
			push(token.value);
		else
		{
			a = pop();
			b = pop();
			switch (token.kind)
			{
			case '+':
				push(a + b);
				break;
			case '-':
				push(b - a);
				break;
			case '*':
				push(b * a);
				break;
			case '/':
				push(b / a);
				break;
			case '%':
				push(b % a);
				break;
			case '^':
				push(pow(b, a));
				break;
			default:
				printf("WRONG POSTFIX ENTERED!!!\n");
				exit(0);
			}
		}
		token = getnext_token();
	}
	int sol;
	sol = pop();
	if (!isempty())
	{
		printf("WRONG POSTFIX ENTERED!!!\n");
		exit(0);
	}
	else
		printf("Solution of Expression : %d\n", sol);
}