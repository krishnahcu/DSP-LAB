#include<stdio.h>
#include<stdlib.h>

struct node
{
    void *data;
    struct node *next;
};
struct list
{
    struct node *head;
    struct node *tail;
    int size;
};

struct list *createList();
void insertLast(struct list *, void *);
void *deleteFirst(struct list *);
int isEmpty(struct list *);
int digits(int );
int Maximum(int , int []);
void radixSort(int, int []);

int main()
{
    int num;
    scanf("%d", &num);
    if(num <= 0)
    {
        printf("INVALID INPUT");
        return 0;
    }
    int arr[num];
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i] < 0)
        {
            printf("INVALID INPUT");
            return 0;
        }
    }
    radixSort(num, arr);
    for(int i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }
}


struct list * createList()
{
    struct list *ptr = malloc(sizeof(struct list));
    ptr->head = NULL;
    ptr->tail = NULL;
    ptr->size = 0;
    return ptr;
}
void insertLast(struct list *ptr, void *data)
{
    if(ptr->tail == NULL)
    {
        struct node * temp = malloc(sizeof(struct node));
        temp->data = data;
        temp->next = NULL;
        ptr->head = temp;
        ptr->tail = temp;
        ptr->size = 1;
        return;
    }
    struct node * temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    ptr->tail->next = temp;
    ptr->tail = temp;
    ptr->size = ptr->size + 1;
    return;
}

void * deleteFirst(struct list *ptr)
{
    if(ptr->size == 1)
    {
        void *data = ptr->head->data;
        struct node *temp = ptr->head;
        ptr->head = NULL;
        ptr->tail = NULL;
        ptr->size = 0;
        free(temp);
        return data;
    }
    void *data = ptr->head->data;
    struct node *temp = ptr->head;
    ptr->head = ptr->head->next;
    ptr->size = ptr->size - 1;
    free(temp);
    return data;
}

int isEmpty(struct list *ptr)
{
    if(ptr->size == 0)
        return 1;
    return 0;
}

int digits(int num)
{
    int count = 0;
    while(num)
    {
        num = num / 10;
        count++;
    }
    return count;
}

int Maximum(int num, int arr[])
{
    int max = 0;
    for(int i = 0; i < num; i++)
    {
        int d = digits(arr[i]);
        if(d > max)
            max = d;
    }
    return max;
}

void radixSort(int num, int arr[])
{
    struct list *list[10];
    for(int i = 0; i < 10; i++)
        list[i] = createList();
    

    int max = Maximum(num, arr);
    int l = 1;
    for(int i = 0; i < max; i++)
    {
        for(int j = 0; j < num; j++)
        {
            int d = (arr[j] / l) % 10;
            int *num = malloc(sizeof(int));
            *num = arr[j];
            insertLast(list[d], num);
        }
        int k = 0;
        for(int j = 0; j < 10; j++)
        {
            while(!isEmpty(list[j]))
            {
                int *num = deleteFirst(list[j]);
                arr[k] = *num;
                k++;
                free(num);
            }
        }
        l = l * 10;
    }
    for(int i = 0; i < 10; i++)
    {
        free(list[i]);
    }
}
