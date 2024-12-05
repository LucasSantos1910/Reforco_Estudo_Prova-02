void merge(int array[], int left, int mid, int right)
{
    int i;
    int j;
    int k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int LEFT[n1];
    int RIGHT[n2];

    for (i = 0; i < n1; i++)
    {
        LEFT[i] = array[left + i];
    }
    
    for (j = 0; j < n2; j++)
    {
        RIGHT[j] = array[mid + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = left;
    
    while(i < n1 && j < n2)
    {
        if(LEFT[i] <= RIGHT[j])
        {
            array[k] = LEFT[i];
            i++;
        }

        array[k] = RIGHT[j];
        j++;
        k++;
    }

    while (i < n1)
    {
        array[k] = LEFT[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = RIGHT[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        merge(array, left, mid, right);
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
    
    mergeSort(arr, 0, sz - 1);
    
    printf("\nOrdenada: ");
    printArray(arr, sz);

    return 0;

    

}
//  "O conceito de "dividir para conquistar" é uma técnica fundamental em algoritmos que resolve problemas grandes e complexos ao dividi-los em partes menores e mais gerenciáveis.
