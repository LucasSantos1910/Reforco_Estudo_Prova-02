
int shellSort(int array[], int size)
{
    for(int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i += 1)
        {
            int temp = array[i];
            int j = 0;  
            
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
            {
                array[j] = array[j - gap];
            }
            
            array[j] = temp;
        }
    }
    return 0;
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

    shellSort(arr, sz);

    printf("\nOrdenada: ");
    printArray(arr, sz);

    return 0;
}

// "Shell Sequence: Adequada para listas pequenas, mas pode ser menos eficiente para listas maiores.
// Knuth Sequence: Oferece um bom equilíbrio entre simplicidade e eficiência, sendo geralmente a escolha preferida para listas grandes.
// Hibbard Sequence: Também eficiente, especialmente quando a lista tem um tamanho médio a grande, mas pode não ser tão robusta quanto a sequência de Knuth em todos os casos.

// A escolha da sequência de intervalos deve considerar o tamanho da lista e a necessidade de eficiência. Em prática, a sequência de Knuth é frequentemente preferida para otimização geral.

