void selectionSort(int array[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int min = i;
        
        for(int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
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
    
    selectionSort(arr, sz);
    
    printf("\nOrdenada: ");
    printArray(arr, sz);

    return 0;
}
// "Tamanho da Lista	Vantagens do Selection Sort	                               Desvantagens do Selection Sort
// Pequena	            Simplicidade,implementação rápida	                    Desempenho aceitável, mas não ótimo
// Média	            Nenhuma            	                                 Começa a ser ineficiente, tempo de execução aumenta
// Grande	            Nenhuma	                                              Extremamente ineficiente, tempo de execução impraticável

