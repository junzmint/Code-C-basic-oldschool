#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef char elementtype;
#include"StackGen.h"
#include"StackGenFloat.h"
#define MAX 1000

int prior(char operator){
    if (operator == '*' || operator == '/') return 2;
    else if (operator == '+' || operator == '-')  return 1;
    else if (operator == '(' || operator == ')')   return 0;
}

int main(){
    Stacktype *top;
    StackType *ans;
    intialize(&top);
    Intialize(&ans);
    char input[MAX],output[MAX];
    char choose;
    int check = 0,check1 = 0;
    int i = 0;
    int count1 = 0, count2 = 0;
    int j = 0;
    int read = 0;
    char v, ele;
    float a,b,result;
    int caculate = 0, index = 0;
    char trunggian[MAX];
    printf("Welcome\n");
    while(1 == 1){
        printf("1. Enter arithmetic expressions in infix notation (Caution: You need a space between all characters) \n");
        printf("2. Change to postfix form\n");
        printf("3. Calculating value\n");
        printf("4. Exit\n");
        printf("Your option: ");
        scanf("%c",&choose);
        fflush(stdin);
        if(choose == '1'){
            i = 0;
            strcpy(input,"\0");
            strcpy(output,"\0");
            printf("Input your arithmetic expressions: ");
            gets(input);
            while(i < strlen(input)){
                if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '(' || input[i] == ')')
                {   
                    i++;
                    continue;
                }
                else if (input[i] == ' ' || input[i] == '.'){
                    i++;
                    continue;
                }
                else if (input[i] >= '0' && input[i] <= '9'){
                    i++;
                    continue;
                }
                else{
                    printf("\nYour input is invalid\nYou will be back to the Menu Screen\n\n");
                    i = 0;
                    break;
                }
            }
            for(int m = 0; m < strlen(input); m++){
                if(input[m] == '('){
                    count1++;
                }
                if (input[m] == ')'){
                    count2++;
                }
            }
            if(count1 != count2){
                printf("\nYour input is invalid, you are missing '(' or ')'\nYou will be back to the Menu Screen\n\n");
                count1 = 0;
                count2 = 0;
                continue;
            }
            if(i == strlen(input)){
                check = 1;
            }
            if(i == 0){
                check = 0;
            }
        }
        else if(choose == '2'){
            if(check == 0) printf("No input\n");
            if(check == 1){
                while(j < strlen(input)){
                    if(input[j] >= '0' && input[j] <= '9' || input[j] == '.'){
                        output[read] = input[j];
                        read ++;
                    }
                    else if(input[j] == ' '){
                        if(j == 0){
                            continue;
                        }
                        if(read > 0){
                            if(output[read - 1] != ' '){
                                output[read] = input[j];
                                read ++;
                            }
                        }
                        
                    }
                    else if(input[j] == '(' || input[j] == ')'){
                        if(input[j] == '(') Push(input[j], &top);
                        else{
                            while(!isEmpty(top)){
                                v = Pop(&top);
                                if (v == '(')  continue;
		                        output[read] = v;
                                read ++;
                                output[read] = ' ';
                                read ++;
                            }
                        }
                    }
                    else if (input[j] == '+' || input[j] == '-' || input[j] == '*' || input[j] == '/') {
                        while ((!isEmpty(top)) && (prior(input[j]) <= prior(Peek(&top)))) {
                            ele = Pop(&top);
		                    output[read] = ele;
                            read++;
                            output[read] = ' ';
                            read++;
                        }
                        Push(input[j], &top);
                    }
                    j++;
                }
                while (!isEmpty(top)) {output[read++] = ' '; output[read++]=Pop(&top);}
                output[read++]='\0';
                printf("\nThe Postfix Expression: %s\n",output);
                check1 = 1;
                read = 0;
                j = 0;
            }
        }
        else if(choose == '3'){
            if(check == 0) printf("No input\n");
            if(check1 == 0) printf("You haven't converted yet, press 2 to convert\n");
            if (check == 1 && check1 == 1){
                strcpy(trunggian, "\0");
                while(index < strlen(output)){
                    if(output[index] >= '0' && output[index] <= '9' || output[index] == '.' ){
                        trunggian[caculate] = output[index];
                        caculate++;
                    }
                    else if(output[index] == ' '){
                        if(strlen(trunggian) == 0){
                            index ++;
                            continue;
                        }
                        trunggian[caculate] = '\0';
                        push(atof(trunggian), &ans);
                        strcpy(trunggian, "\0");
                        caculate = 0;
                    }
                    else if(output[index] == '+' || output[index] == '-' || output[index] == '*' || output[index] == '/'){
                        b = pop(&ans);
                        a = pop(&ans);
                        if(output[index] == '+') push(a+b,&ans);
                        if(output[index] == '-') push(a-b,&ans);
                        if(output[index] == '*') push(a*b,&ans);
                        if(output[index] == '/') push(a/b,&ans);
                    }
                    index ++;
                }
                printf("The value is: ");
                result = pop(&ans);
                printf("%.3f",result);
                printf("\n");
                index = 0;
                caculate = 0;
            }
        }
        else if(choose == '4'){
            FreeStack(&top);
            printf("Goodbye\n");
            exit(0);
        }
        else{
            printf("\nInvalid syntax\n");
            printf("You will be back to the Menu Screen\n\n");
        }
    }
    return 0;
}