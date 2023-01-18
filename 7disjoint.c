#include<stdio.h>
#include<stdlib.h>
typedef struct
{                       //structure to represent an object of set in linked representation
int value;
struct rep *repptr;  //pointer to header node of the list
struct node *next;
}node;

typedef struct
{
node *head;   //structure to represent header node of linked representation of set
node *tail;
}rep; 

typedef struct
{
int key;  //structure to store key and object node pointer 
node *obj_node_ptr;
struct nodaddr *next;
}nodaddr;
nodaddr *ndr=0;  //list to store keys and object node pointer

void makeset(int a)  //create a object node pointer
{
nodaddr *t=(nodaddr*)malloc(sizeof(nodaddr));  //create a new set
rep *newset=(rep*)malloc(sizeof(node));
node *n=(node *)malloc(sizeof(node));

n->value=a;  //fill values
n->repptr=newset;
n->next=0;
newset->head=newset->tail=n;

t->obj_node_ptr=n;  //to store object node pointer and key
t->key=a;
t->next=ndr;
ndr=t;
}

rep *find(int x)
{
nodaddr *t=ndr;
while(t->key!=x && t!=0)
t=t->next;
return t->obj_node_ptr->repptr;
}

void unionset(int key1,int key2)  //to find union of two sets corresponding to objects given
{
rep *set1, *set2;
node *t1;
set1=find(key1);
set2=find(key2);
if(set1==set2)
printf("\n %d and %d belongs to same set \n",key1,key2);
else
{
t1=set2->head;  //changing the header pointer of objects of set2 to that of set1
while(t1!=0)
{
t1->repptr=set1;
t1=t1->next;
}

set1->tail->next=set2->head;  
set1->tail=set2->tail;     //set the tail of set1 to tail of set2
t1=set1->head;
/*while(t1!=0)
{
printf("%d,",t1->value);
t1=t1->next;
}*/
free(set2);
}
}

void display_set(int a)
{
int i=0;
rep *r;
node *t;
r=find(a);
t=r->head;
printf("set members containing %d:",a);
while(t!=0)
{
printf("%d,",t->value);
t=t->next;
}
}
void main()
{
int opt,data,data1,data2;
do
{
printf("\n 1.makeset\n");
printf("\n 2.findset\n");
printf("\n 3.unionset\n");
printf("\n 4.display set\n");
printf("\n 5.exit\n");
printf("enter your option:");
scanf("%d",&opt);
switch(opt)
{
case 1:
printf("enter the data:");
scanf("%d",&data);
makeset(data);
break;
case 2:
printf("enter set value:");
scanf("%d",&data);
printf("reference of set containing %d is %x",data,find(data));
break;
case 3:
printf("enter the data:");
scanf("%d%d",&data1,&data2);
unionset(data1,data2);
break;
case 4:
printf("enter the data:");
scanf("%d",&data);
display_set(data);
break;
case 5:
exit(0);
}
}
while(1);
}

