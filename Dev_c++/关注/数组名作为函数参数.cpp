#include<stdio.h>
int sort(int* a)					//ָ��a���������ַ����ȥ���� 
{
    printf("%d\n",a[4]);
}
int sort1(int a[])					//�ɱ�������Ϊ�������� 
{
    printf("%d\n",a[4]);
}
int sort2(int a[],int n) 
{
    printf("%d\n",a[3]);
}
int main()
{
    int b[]={9,2,1,163,156,55};
    sort(b);
    sort1(b);
    sort2(b,1);
    return 0;
}
