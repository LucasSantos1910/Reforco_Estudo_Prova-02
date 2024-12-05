void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j = low;

    while(j < high)
    {
        if(array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
        
        j++;
    }
    
    swap(&array[i + 1], &array[high]);  
    return i + 1;
}

void quickSort(int array[], int low, int high)
{
    if(low < high)
    {
        int pivot = partition(array, low, high);

        quickSort(array, low, pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

int main(void)
{
    int arr[] = {69, 24, 666, 420, 1533, 157, 121};
    int sz = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original: ");
    printArray(arr, sz);
    
    quickSort(arr, 0, sz - 1);
    
    printf("\nOrdenada: ");
    printArray(arr, sz);

    return 0;
}

// "Para Listas Quase Ordenadas O Quick Sort pode ser menos eficiente devido à maior probabilidade de escolher pivôs desfavoráveis, a menos que técnicas avançadas de escolha de pivô sejam usadas.
// Para Listas Completamente Desordenadas tende a performar mais consistentemente, beneficiando-se da distribuição aleatória dos elementos.
