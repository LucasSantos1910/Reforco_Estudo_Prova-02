
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
 
void bucketSort(int array[], int size)
{  
    int max = getMax(array, size);
    int bucket[max + 1];
 
    for(int i = 0; i <= max; i++)
    bucket[i] = 0;
 
    for(int i = 0; i < size; i++)
    bucket[array[i]]++;
 
    int j = 0;
    
    for(int i = 0; i <= max; i++)
    { 
        while(bucket[i] > 0)
        {  
            array[j++] = i;
            bucket[i]--;
        }  
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
    
    bucketSort(arr, sz);
    
    printf("\nOrdenada: ");
    printArray(arr, sz);

    return 0;
}
// "Define-se um intervalo de valores para cada bucket. Se estamos ordenando números entre 0 e 1, por exemplo, podemos dividir esse intervalo em vários subintervalos iguais.
// O número de buckets pode ser escolhido com base no número total de elementos n ou outro critério específico. Uma escolha comum é sqrt(n) buckets.
// Cada elemento da lista é colocado no bucket correspondente ao seu valor.
// A fórmula para determinar o bucket é geralmente uma função simples, como 
// índice do bucket = [valor x número de buckets] / intervalo
// Cada bucket é ordenado individualmente usando um algoritmo de ordenação eficiente, como Insertion Sort, Quick Sort, ou Merge Sort.
// Para listas pequenas dentro de um bucket, Insertion Sort é uma boa escolha devido à sua simplicidade e eficiência para pequenas quantidades de dados.
// Depois de ordenar todos os buckets individualmente, os elementos de todos os buckets são concatenados para formar a lista final ordenada.
// A ordem dos elementos nos buckets segue a ordem dos buckets, garantindo que a lista final esteja corretamente ordenada.
