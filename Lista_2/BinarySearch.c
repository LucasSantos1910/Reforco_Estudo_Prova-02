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

int main(void)
{
    int arr[] = {24, 69, 121, 157, 420, 666, 1533};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int n = 69;
    int i = binarySearch(arr, 0, size - 1, n);
    
    if (i == -1)
    {
        printf("Elemento não encontrado!");
    }
    else{
        printf("Elemento no índice %d.", i);
    }
}

// "Binary Search funciona assumindo que a mediana do array ou subarrays seja o valor procurado. Se não estiver ordenado, essa suposição não faria sentido, já que a mediana pode estar em qualquer lugar e dividir o array pela metade pode significar que o número procurado foi eliminado da busca.
