#include <stdio.h>

#define SWAP(a,b)  {int t; t = a; a=b; b=t;}//a와 b를 교환


void SequenceSort(int *base, int n);
int main(void)
{
    int arr[10] = { 9,4,3,10,5,8,7,6,2,1 };
    SequenceSort(arr, 10);
    return 0;
}

//정렬 과정을 출력하기 위한 함수입니다.
void ViewArr(int *arr, int n);
void SequenceSort(int *base, int n)
{
    int i, j;
    ViewArr(base, n);//현재 상태 출력
    for (i = 0; i<n; i++)
    {
        for (j = i; j<n; j++)
        {
            if (base[i]>base[j])//앞쪽 원소가 더 크면
            {
                SWAP(base[i], base[j]);//교환
                ViewArr(base, n);//상태 출력
            }
        }
    }
}

void ViewArr(int *arr, int n)
{
    int i = 0;
    for (i = 0; i<n; i++)
    {
        printf("%2d ", arr[i]);
    }
    printf("\n");
}
