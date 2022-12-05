    #include<stdio.h>
    #include<stdlib.h>
    struct node
    {
    int data;
    struct node *next;
    };
    struct node *sp=(struct node*)0;  //empty stack
    void push(int item)  //place an item in stack
    {
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=item;
    t->next=sp;
    sp=t;
    return;
    }
    int pop()  //delete an item from stack
    {
    struct node *t;
    int item;
     
    if(sp==(struct node *)0)
    printf("empty stack");
    else
    {
    item=sp->data;
    t=sp;
    sp=sp->next;
    free(t);
    return item;
    }
    }
    int search(int item)  //search an item in stack
    {
    int pos=0;
struct node *t=sp;
    while(t!=(struct node *)0)
    {
    ++pos;
if(t->data==item)
    return pos;  //item found
    t=t->next;
    }
    return 0;  //item not found
    }
    int main()
    {
    int item,opt,ans;
    do
     
    {
    printf("\n 1.push:\n");
    printf("\n 2.pop:\n");
    printf("\n 3.search:\n");
    printf("\n 4.exit:\n");
    printf("\n 5.option:\n");
    scanf("%d",&opt);
    switch(opt)
    {
    case 1:printf("data:");
    scanf("%d",&item);
    push(item);
    printf("inserted at %d",item);
    break;
    case 2:item=pop();
    printf("deleted=%d",item);
    break;
    case 3:printf("number to search:");
    scanf("%d",&item);
    ans=search(item);
    if(ans==0)
    printf("not found");
    else
     printf("found at %d node",ans);
    break;
    case 4:exit(0);
    }
    }
    while(1);
    }


