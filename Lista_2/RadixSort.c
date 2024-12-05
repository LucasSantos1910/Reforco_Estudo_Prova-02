int getMax(int array[], int size) 
{  
    int max = INT_MIN;
    
    for(int i = 0; i < size; i++)
    {
        if(array[i] > max)
        max = array[i];
    }
    
    return max;
}

void countSort(int array[], int size, int exp)
{
    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++)
    {
        count[(array[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
}

void radixSort(int array[], int size)
{
    int m = getMax(array, size);

    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countSort(array, size, exp);
    }
}

void printArray(int array[], int size)
{
    for(int i = 0; i < size; i++)
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
    
    radixSort(arr, sz);
    
    printf("\nOrdenada: ");
    printArray(arr, sz);

    return 0;
}

// "Os números são divididos em dígitos de acordo com a base k.
// Começa pelo dígito menos significativo e avança para o mais significativo.
// Usar uma base maior reduz o número de passagens necessárias para completar a ordenação, pois cada passagem pode ordenar uma porção maior dos dados.
// Bases maiores reduzem o número de passagens necessárias, mas aumentam a complexidade de cada passagem.
