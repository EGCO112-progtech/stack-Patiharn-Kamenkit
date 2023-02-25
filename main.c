//#include "node.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  NodePtr top = NULL;
  int i, j, N = 0;
  Stack s;
  char x;
  s.top = NULL;
  s.size = 0;
  for (i = 1; i < argc; i++) {
    N=0;
    for (j = 0; j < strlen(argv[i]); j++) {

      switch (argv[i][j]) {
      case '{':
      case '[':
        push(&s, (argv[i][j]));
        break;
      case '}':
        x=pop(&s);
        if (x != '{') {
          if(x == '[')
          N = 1;
          else
          N=2;}

        break;
      case ']':
        x=pop(&s);
       if (x != '[') {
          if(x == '{')
          N = 1;
          else
          N=2;}
        else N=0;
        break;
      default:
        printf("Non of condition\n");
      }
      if (N == 1)
        break;
    }
   
    if (s.size > 0) {
      printf("argv %d: Incorrect too many open parathesis\n", i);
      pop_all(&s);
    } else if (N == 0)
      printf("argv %d: Correct\n", i);
    else if (N == 1)
      printf("argv %d: Incorrect mismatch \n", i);
    else
      printf("argv %d: Incorrect too many close parathesis\n", i);
      pop_all(&s);
  }

  // pop(&top);

  /*
  Stack s;
  printf("Checking the parentheses in argv arguments\n");
   for(i=1;i<argc;i++){
      for(j=0;j<strlen(argv[i]);j++){
         Use stack to help with the parentheses*/

  /*}
  }
  */

  return 0;
}