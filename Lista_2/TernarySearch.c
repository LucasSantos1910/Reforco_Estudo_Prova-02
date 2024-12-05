
int ternarySearch(int array[], int left, int right, int n)
{
    if(right >= left)
    {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if(array[mid1] == n)
        {
            return mid1;
        }
        
        if(array[mid2] == n)
        {
            return mid2;
        }

        if(n < array[mid1])
        {
            return ternarySearch(array, left, mid1 - 1, n);
        }
        else if(n > array[mid2])
        {
            return ternarySearch(array, mid2 + 1, right, n);
        }
        else
        {
            return ternarySearch(array, mid1 + 1, mid2 - 1, n);
        }
    }

    return -1;
}

int main(void)
{
    int arr[] = {24, 69, 121, 157, 420, 666, 1533};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int n = 69;
    int i = ternarySearch(arr, 0, size - 1, n);
    
    if (i == -1)
    {
        printf("Elemento não encontrado!");
    }
    else
    {
        printf("Elemento no índice %d.", i);
    }
}
// "Em conclusão, embora o Ternary Search seja teoricamente um pouco mais eficiente na base dos logaritmos, o Binary Search tende a ser mais prático e eficiente na maioria das aplicações devido ao menor número de comparações necessárias em cada iteração.
