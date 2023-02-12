#include <stdio.h>

int push(int st[], int val){

    if(top == MAX-1){
        printf("Stack overflow");
    }else{
        top++;
        st[top] = val;
    }
}

int pop(int st[]){
    int val;
    if(top == -1){
        printf("stack overflow");
        return -1;
    }else{
        val = st[top];
        top--;
        return val;
    }
}
 
int peek(int st[]){
    if(top == -1){
        printf("stack overflow");
        return -1;
    }else{
        return st[top];
    }
}

int main(){



}