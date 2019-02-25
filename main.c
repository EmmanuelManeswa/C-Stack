#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 5
#define INVALID_VAL -256

typedef struct{
    int data[STACK_SIZE];
    int top;
}stack;

void initialize(stack *s){
    s->top = -1;
}

bool is_empty(stack *s){
    return s->top == -1 ? true : false;
}

bool is_full(stack *s){
    return s->top == STACK_SIZE-1 ? true : false;
}

void push(stack *s, int elem){
    if(is_full(s)){
        printf("Overflow: Stack is full!\n\n");
        return;
    }
    s->data[++(s->top)] = elem;
}

int pop(stack *s){
    if(is_empty(s)){
        printf("Underflow: Stack is empty!\n\n");
        return INVALID_VAL;
    }
    return s->data[s->top--];
}

int top_of_stack(stack *s){
    if(is_empty(s)){
        printf("Stack is empty.\n");
        return INVALID_VAL;
    }
    return s->data[s->top];
}

void display(stack *s){
    if(is_empty(s)){
        printf("Stack is empty.\n\n");
        return;
    }
    for(int i = s->top; i > -1; i--){
        printf("| %5d |\n", s->data[i]);
    }
}

int main(void){

    stack s;
    initialize(&s);

    bool loop = true;
    int choice, val, temp;
    while(loop){
        printf("\t1. Push\n");
        printf("\t2. Pop\n");
        printf("\t3. Top of Stack\n");
        printf("\t4. Display\n");
        printf("\t5. Exit\n");
        printf("Choice [1,2,3,4,5]: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                do{
                    printf("\nValue to push [-256 is invalid]: ");
                    scanf("%d", &val);
                }while(val == INVALID_VAL);
                push(&s, val);
                break;
            case 2:
                temp = pop(&s);
                temp == INVALID_VAL ? printf("Nothing removed.\n\n") : printf("%d is removed.\n\n", temp);
                break;
            case 3:
                temp = top_of_stack(&s);
                temp == INVALID_VAL ? printf("\n") : printf("%d is on top.\n", temp);
                break;
            case 4:
                display(&s);
                break;
            case 5:
                loop = false;
                break;
            default:
                printf("Invalid input\n");
        }

    }

    return 0;
}