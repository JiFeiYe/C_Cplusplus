#include<stdio.h>
#include<stdlib.h>

struct Listnode
{
    int data;
    struct Listnode *next;
};

int main()
{
    struct Listnode *head = (struct Listnode*)malloc(sizeof(struct Listnode));
    head->next = NULL;
    struct Listnode *p;
    p = head;
    int n = 0;
    printf("请输入链表长度：\n");
    scanf("%d", &n);
    printf("请输入数据：\n");
    for(int i = 0; i < n; i++)
    {
        struct Listnode *s = (struct Listnode*)malloc(sizeof(struct Listnode));
        scanf("%d", &s->data);
        //头插法核心代码
        s->next = head->next;
        head->next = s;
    }//链表创建完成

    p = head;
    while(p->next != NULL)
    {
        printf("%-5d", p->next->data);
        p = p->next;
    }
    printf("\n");
    //链表输出完成

    p = head;
    while(p->next != NULL)
    {
        struct Listnode *temp = p;
        free(p);
        p = temp->next;
    }//链表释放完成

    return 0;
}