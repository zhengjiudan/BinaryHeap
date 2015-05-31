#include <stdio.h>

void AdjustHeap(int *a, int start, int len)
{
   int tmp;
   while (true)
   {
   int swap = start;
   if (start*2+1 <= len-1)
   {
     swap = a[swap]<a[2*start+1] ? 2*start+1 : start;
   }
   if (start*2+2 <= len-1)
   {
     swap = a[swap]<a[2*start+2] ? 2*start+2 : swap;
   } 
   if (swap != start)
   {
     tmp = a[start];
     a[start] = a[swap];
     a[swap] = tmp;
     start = swap;
   }
   else
   {
     break;
   }
   }
}

void AdjustHeapAfterChange(int *a, int index, int len)
{
  int parent = (index-2)/2;
  int tmp;
  while (parent >= 0)
  {
    if (a[index] > a[parent])
    {
      tmp = a[index];
      a[index] = a[parent];
      a[parent] = tmp;
      index = parent;
      parent = (index-2)/2;
    }
    else
    {
      break;
    }
  }
  AdjustHeap(a, index, len);
}

void BuildHeap(int *a, int len)
{
  int start = (len-2)/2;
  int tmp;
  for (int i=start; i>=0; --i)
  {
    int swap = a[i]<a[2*i+1] ? 2*i+1 : i;
    if (2*i+2 <= len-1)
    {
      swap = a[swap]<a[2*i+2] ? 2*i+2 : swap;
    }
    if (swap != i)
    {
      tmp = a[i];
      a[i] = a[swap];
      a[swap] = tmp;
      AdjustHeap(a, swap, len);
    }   
  }
}

void HeapSort(int *a, int len)
{
    BuildHeap(a, len);

    int tmp = a[0];
    a[0] = a[len-1];
    a[len-1] = tmp;

    for (int index=len-1; index > 0; --index)
    {
        AdjustHeap(a, 0, index);

        tmp = a[0];
        a[0] = a[index-1];
        a[index-1] = tmp;
    }
}

int main()
{
  int a[] = {9, 2, 5, 6, 8, 1};
  int arr_len = sizeof(a)/sizeof(int);
  printf("Size of a is %d\n", arr_len);
  BuildHeap(a, arr_len);
  
  printf("The heap is built like below:\n");
  for (int i=0; i<arr_len; ++i)
  {
    printf("%d\n", a[i]);
  }
 
  a[1] = 10;

  AdjustHeapAfterChange(a, 1, arr_len);

  printf("The heap is built like below after changing one value:\n");
  for (int i=0; i<arr_len; ++i)
  {
    printf("%d\n", a[i]);
  }
  return 0;
}
