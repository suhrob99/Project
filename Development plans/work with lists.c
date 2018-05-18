struct node *deletedlist(struct node *ptr)
{
    struct node* temp;
    while(ptr != NULL)
    {
        temp = ptr->next;
        free(ptr);
        ptr = temp;

    }
    return ptr; /*ptr == NULL*/
    
}