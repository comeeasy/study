#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct stack {
    char stack[MAX];
    int peek;
} Stack;

Stack* stack_init(Stack* s) {
        s = (Stack*)malloc(sizeof(Stack));
        s->peek = 0;

        return s;
    }
int stack_is_empty(Stack* s) {return (s->peek == -1);}
int stack_is_full(Stack* s) {return (s->peek == MAX-1);}
void push(Stack* s, char ch) {
    if(!stack_is_full(s)) {
        s->stack[++(s->peek)] = ch;
    }
    else {
        printf("stack is full!!\n\n");
    }
}
char pop(Stack* s) {
    if(!stack_is_empty(s)) {
        return s->stack[(s->peek)--];
    }
    else {
        printf("stack is empty!\n\n");
    }
}
char top(Stack* s) {
        if(!stack_is_empty(s))  return (s->stack[s->peek]);
        else return '\0';
    }
int compare_priority(char op1, char op2) {
    /*
        if op1's priority is higher than op2 
            then return 1
        else if (opposit case)
            then return 0
        else   (p1 == p2)
            then return 1
    */

    int p1, p2;
    if(op1 == '\0') return 0;

    if(op1 == '*' || op1 == '/') {p1 = 1;}
    else {p1 = 2;}
    if(op2 == '*' || op2 == '/') {p2 = 1;}
    else {p2 = 2;}

    if( p1 > p2 )       return 0;
    else if( p2 > p1 )  return 1;
    else                return 1; 
}

/*
int calculate(char post[]) {
    Stack* s;
    int answer;

    stack_init(s);
    if()    


    free(s);
    return answer;
}
*/

int main() {
    Stack* s;
    char exp[MAX], post[MAX], ch;
    int post_peek = 0;

    s = stack_init(s);
    printf("enter infix exp: ");
    scanf("%s", exp);

    for(int i=0; i<strlen(exp); ++i) {
        ch = exp[i];

        // operator 
        if(ch=='*' || ch=='+' || ch=='-' || ch=='/') {
            while(compare_priority(top(s), ch)) {
                printf("%c", top(s));
                post[post_peek++] = top(s);
                
                pop(s);
            }
            push(s, ch);
        } // operand
        else if(ch =='(') {
            push(s, ch);
        }
        else if(ch == ')') {
            while(top(s) != '(') {
                printf("%c", top(s));
                post[post_peek++] = top(s);

                pop(s);    
            }
        }
        else {
            printf("%c", ch);
            post[post_peek++] = top(s);

        }
    }
    while(!stack_is_empty(s)) {
        printf("%c", top(s));
        post[post_peek++] = top(s);
        pop(s);
    }

    printf("\n");

    free(s);
    return 0;
}


