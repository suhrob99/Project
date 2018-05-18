struct node* buildlist(void)
{
    struct node* first = NULL, *last;
    int n;
    printf("Введите значение: ");
    scanf("%d", &n);
    if(n)
    {
        first = last = buildnode(n);
        printf("Введите значение: ");
        scanf("%d", &n);
        while(last != NULL && n != 0)
        {
            last->next = buildnode(n);
            last = last->next;
            printf("Введите значение:");
            scanf("%d",&n);
        }
        
    }
    return first;