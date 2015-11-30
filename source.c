#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 20
typedef struct stack
{
	int data[max];
	int top;
}stack;
void init(stack *s){
	s->top = -1;
}
void push(stack *s, int elem){
	s->top++;
	s->data[s->top] = elem;
}

int pop(stack *s){
	int x = s->data[s->top];
	s->top--;
	return x;
}

char top(stack *s){
	return(s->data[s->top]);
}

int is_full(stack *s){
	if(s->top == max - 1)
		return 1;
	else
		return 0;
}

int is_empty(stack *s){
	if(s->top==-1)
		return 1;
	else
		return 0;
}
int priority(char x){
	if(x == '*' || x == '/' || x == '%')
		return 2;
	else if(x == '+' || x == '-')
		return 1;
	else if(x == '(')
		return 0;
	else
		return 3;

}
int main(){
	stack s;
	int token;
	char x;
	init(&s);
	printf("\nType the infix expression, Enter 'n' to terminate: ");
	while((token=getchar())!='n'){
		if(isalnum(token)){
			printf("%c",token);
		}
		else{
			if(token == '(')
				push(&s,token);
			else{
				if(token == ')')
					while((x=pop(&s))!='(')
						printf("%c",x);
				else{
					while(priority(token)<priority(top(&s)) && !is_empty(&s))
					{
						x = pop(&s);
						printf("%c",x);
					}
					push(&s,token);
				}

			}
		}
	}

	while(!is_empty(&s)){
		x = pop(&s);
		printf("%c",x);
	}
	return 0;
}
