#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "node.h"
#include "stack.h"

//void push(NodePtr* top, int x);
//int pop (NodePtr* top);
void pop_all(StackPtr s);

int main(int argc, char **argv){
  
  int i,N,j;
  Stack s;
  s.top=NULL;
  s.size=0;
  
  for(i=1; i<argc; i++){
    N=0;
      for(j=0;j<strlen(argv[i]); j++)
        {
          switch(argv[i][j]){
            case '{' : push(&s,argv[i][j]); break;
            
            case '[' : push(&s,argv[i][j]); break;

            case '}' : if(pop(&s) != '{') {
                        if(pop(&s) == '[') N=1; 
              else N=2;} 
              else N=0; break;
                       
            case ']' : if(pop(&s) != '[') {
                        if(pop(&s) == '{') N=1; 
              else N=2;} 
              else N=0; break;
          }
        if(N==1) break;
        }
    if(s.size>0){
      printf("argv %d: incorrect: too many open parenthesis\n",i);
      pop_all(&s);
    }
    if(N==0) printf("argv %d: Correct\n",i);
    else if(N==2) printf("argv %d: incorrect: too many close parenthesis\n",i);
    else printf("argv %d: incorrect: mismatch\n",i);
    pop_all(&s);
    
  }
  return 0;
}
 /*
 Stack s;
 printf("Checking the parentheses in argv arguments\n");
  for(i=1;i<argc;i++){
   
     for(j=0;j<strlen(argv[i]);j++){
        Use stack to help with the parentheses


     }


  }




   return 0;
}*/
