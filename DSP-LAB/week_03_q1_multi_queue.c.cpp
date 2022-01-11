#include<stdio.h>
#define MAX 6
int front1=-1,front2=MAX;
int rear1=-1 ,rear2=MAX,arr[MAX];
void deque1();
void deque2();
void deque3();
void deque4();
void enque1();
void enque2();
void enque3();
void enque4();
int main()
{
enque1();
enque2();
enque3();
enque4();
deque1();
deque2();
deque3();
deque4();
return 0;
}
void enque1()
{
int item;
if(rear1<rear2-1)
{
printf("enter the item:");
scanf("%d",&item);
if(front1==-1)
front1=0;
rear1=rear1+1;
arr[rear1]=item;
}
else
printf("overflow 1st queue:");

}
void enque2()
{
int item;
if(rear1<rear2-1)
{
printf("enter the item:");
scanf("%d",&item);
if(front1==-1)
front1=0;
rear1=rear1+1;
arr[rear1]=item;
}
else
printf("overflow 2ndqueue:");

}
void enque3()
{
int item;
if(rear1<rear2-1)
{
printf("enter the item:");
scanf("%d",&item);
if(front1==-1)
front1=0;
rear1=rear1+1;
arr[rear1]=item;
}
else
printf("overflow 3rd queue:");

}
void enque4()
{
int item;
if(rear1<rear2-1)
{
printf("enter the item:");
scanf("%d",&item);
if(front1==-1)
front1=0;
rear1=rear1+1;
arr[rear1]=item;
}
else
printf("overflow 4th queue:");

}
void deque1()
{
int item;
if(front1<=rear1)
item=arr[front1];
front1=front1+1;
printf("%d",item);

}
void deque2()
{
int item;
if(front2>=rear2)
item=arr[front2];
front2=front2-1;
printf("%d",item);
}

void deque3()
{
int item;
if(front2>=rear2)
item=arr[front2];
front2=front2-1;
printf("%d",item);
}

void deque4()
{
int item;
if(front2>=rear2)
item=arr[front2];
front2=front2-1;
printf("%d",item);
}
