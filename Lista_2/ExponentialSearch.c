int min(int a, int b)
{
    if(b > a)
    {
        return a;
    }
    
    return b;
}

int binarySearch(int array[], int low, int high, int n)
{
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if(array[mid] == n)
        {
            return mid;
        }
        
        if(array[mid] < n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int exponentialSearch(int array[], int size, int n)
{
    if(array[0] == n)
    {
        return 0;
    }

    int i = 1;
    while(i < size && array[i] <= n)
    {
        i *= 2;
    }

    return binarySearch(array, i / 2, min(i, size - 1), n);
}

int main(void)
{
    int arr[] = {24, 69, 121, 157, 420, 666, 1533};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int n = 157;
    int i = exponentialSearch(arr, size, n);
    
    if (i == -1)
    {
        printf("Elemento não encontrado!");
    }
    else
    {
        printf("Elemento no índice %d.", i);
    }
    
    return 0;
}
    // "O Exponential Search é uma combinação eficaz de Jump Search e Binary Search, aproveitando os saltos rápidos para localizar o intervalo correto e a precisão da busca binária para encontrar o valor específico. Essa combinação permite que ele seja altamente eficiente em situações onde os dados são vastos e a posição do valor desejado é incerta."
