// linear search
#include<stdio.h>

int main()
<<<<<<< HEAD
{   
=======
{  
>>>>>>> master
    int x;
    printf("Enter the size of array:");
    scanf("%d",&x);

    printf("Enter the elements of array:");
    int a[x];
    for (int i=0; i < x; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter element you want to search:");

    int key;
    scanf("%d",&key);

    int found=0;

    for (int i=0; i<x; i++)
    {
        if(a[i]==key)
        {
            printf("Elements %d found at index %d\n", key);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("element %d not found in array\n", key);
    }
    
    return 0;
}