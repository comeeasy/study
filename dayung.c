void match(char *expr)
{
  char ch, open_ch;  STACK s;
  int j,i=0;

  init_stack(&s);

  while(expr[i] !=0){
    ch=expr[i++];
    switch(ch){
    case'[':case'{':case'(':
      push_stack(&s, ch);
      break;
      j=0;

    case']':case'}':case')':
      if(empty_stack(&s))
        printf("FAIL at %d\n",i);
      else{
      open_ch = pop_stack(&s);
        if((open_ch == '[' && ch != ']') ||
           (open_ch == '{' && ch != '}') ||
           (open_ch == '(' && ch != ')')) {
          printf("FAIL at %d\n",i-1);
      }
        break;
        j=0;
      }
    }
  }
  if(!empty_stack(&s)){
    printf("FAIL at %d\n",i);
  }
  else j=1;
  if(j==1){
  printf("MATCH\n");
  }
}