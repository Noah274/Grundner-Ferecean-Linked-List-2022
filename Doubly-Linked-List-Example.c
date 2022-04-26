```c
#include<stdio.h>
#include<stdlib.h>
struct Node;
typedef struct Node * PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
/*
 * A Struct witch has acsess od the next element and the pervious element
 */
struct Node
{
    int e;
    Position previous;
    Position next;
};
/*
 * Almost like the normal insert Method but with doubly linked list
 *
 * @param x position where the Element should insert
 * @param l the list with the elements
 * @param p pointer of a element
 * 
 * @returns nothing
 */
void Insert(int x, List l, Position p)
{
    Position TmpCell;
    TmpCell = (struct Node*) malloc(sizeof(struct Node));
    if(TmpCell == NULL)
        printf("Memory out of spacen");
    else
    {
        TmpCell->e = x;
        TmpCell->previous = p;
        TmpCell->next = p->next;
        p->next = TmpCell;
    }
}
  
 
/*
 * Deletes an Element at the exact position
 *
 * @params x position where the Element should be deleted
 * @params l list with the elements
 * 
 * @returns nothing
 */
void Delete(int x, List l)
{
    Position p, p1, p2;
    p = Find(x, l);
    if(p != NULL)
    {
        p1 = p -> previous;
        p2 = p -> next;
        p1 -> next = p -> next;
        if(p2 != NULL)                  // if the node is not the last node
            p2 -> previous = p -> previous;
    }
    else
        printf("Element does not exist!!!n");
}
  
  
/*
 * Prints the whole list 
 *
 * @param l list with the elements that is going to be printed out
 * 
 * @returns nothing
 */
void Display(List l)
{
    printf("The list element are :: ");
    Position p = l->next;
    while(p != NULL)
    {
        printf("%d -> ", p->e);
        p = p->next;
    }
}
  
int main()
{
    int x, pos, ch, i;
    List l, l1;
    l = (struct Node *) malloc(sizeof(struct Node));
    l->previous = NULL;
    l->next = NULL;
    List p = l;
    printf("DOUBLY LINKED LIST IMPLEMENTATION OF LIST ADTnn");
    do
    {
        printf("nn1. CREATEn 2. DELETEn  3. DISPLAYn 4. QUITnnEnter the choice :: ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            p = l;
            printf("Enter the element to be inserted :: ");
            scanf("%d",&x);
            printf("Enter the position of the element :: ");
            scanf("%d",&pos);
            for(i = 1; i < pos; i++) { p = p->next;
            }
            Insert(x,l,p);
            break;
  
        case 2:
            p = l;
            printf("Enter the element to be deleted :: ");
            scanf("%d",&x);
            Delete(x,p);
            break;
  
         
  
        case 3:
            Display(l);
            break;
        }
    }
    while(ch<4);
}```