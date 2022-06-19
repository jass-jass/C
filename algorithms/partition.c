#include <stdio.h>

int inputSize()
{
    int size;
    printf("Enter number of elements in the array\n");
    scanf("%d",&size);
    return size;
}

void inputArray(int size,int array[size])
{
    printf("Enter elements of the array\n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&array[i]);
    }
}

void partition(int size,int array[size])
{
    int i=1,key=array[0],k=size-1,temp;
    while(array[i]<key&&k>i)
    {
        ++i;
    }
    while(array[k]>key)
    {
        --k;
    }
    while(k>i)
    {
        temp=array[k];
        array[k]=array[i];
        array[i]=temp;
        k--;
        i++;
        while(array[i]<key)
        {
            ++i;
        }
        while(array[k]>key)
        {
            --k;
        }
    }
    array[0]=array[k];
    array[k]=key;
}

void output(int size,int array[size])
{
    printf("\n\n");
    for(int i=0;i<size;i++)
    {
        printf("\n%d",array[i]);
    }
    printf("\n\n");
}

int main(void)
{
    int size=inputSize();
    int array[size];
    inputArray(size,array);
    partition(size,array);
    output(size,array);
    return 0;
}
