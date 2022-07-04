#include <stdio.h>
#include <stdlib.h>
#define N 100
void selection_sort(float a[], int len);

int main()
{
    system("chcp 936&title 快排（最多支持100个数）&color e&cls");
    float a[N];
    int i = 0, len;
    printf("请输入第1个数（输入非数字字符退出）：");
    while (scanf_s("%f", &a[i]) == 1)
    {
        system("cls");
        printf("请输入第%d个数（输入非数字字符退出）：", i + 2);
        if (i < 99)
            i++;
        else
            break;
    }
    len = i;
    selection_sort(a, len);
    system("cls");
    printf("所输入的%d个数从小到大排序如下：\n", len + 1);
    for (i = 0; i < len; i++)
    {
        if (i == 0)
            printf("%f\t", a[i]);
        else
            printf("%f\t", a[i]);
    }
    printf("\n\n排序完成，请按任意键退出。\n");
    system("pause>nul&cls");
    return 0;
}

void selection_sort(float a[], int len)
{
    int i, j, k;
    for (i = j = 0; i < len; i++)
        if (a[i] > a[j])j = i;
    k = a[len - 1];
    a[len - 1] = a[j];
    a[j] = k;
    if (len > 1)selection_sort(a, len - 1);
}