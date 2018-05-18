#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

struct node *buildnode(int );
struct node *buildlist(void);
void addnode(int, struct node * );
void printlist(struct node *);
struct node *deletedlist(struct node *);
int main(void)
{
    struct node *list = buildlist();
    printlist(list);
    putchar('\n');
    addnode(50,list);
    printlist(list);
    putchar('\n');
    list = deletedlist(list);

    return 0;
}