void print_list(NODE * list)
{
  NODE *p;
  p=list;
  printf("(%d:", length_list(list) );
  if ( p == NULL){
    for (; p!=NULL ; p=p->link){
      printf("%d",p->data);
      if (p->link==NULL)
        printf(")\n");
      else
        printf(",");
    }
  }
  else
    printf(")\n");
}
int length_list(NODE * list)
{
  int l = 0;
  NODE *p;
  for (p=list; p!=NULL ; p=p->link)
    l++;
  return l;
}
NODE *nth_list(NODE * list, int item)
{
  return &p;
}
NODE *add_list(NODE * list, int item)
{
  NODE *node;
  node = (NODE *)malloc(sizeof(NODE));
  node->data = item;
  node->link = list;
  list->link = node;
  retrun list;
}
NODE *delete_list(NODE * list)
{
  NODE *removed;
  if (list==NULL) return NULL;
  removed=list;
  list = list->link;
  free(removed);
  return list;
}