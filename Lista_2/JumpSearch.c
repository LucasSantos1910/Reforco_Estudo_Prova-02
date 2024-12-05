double min(double a, double b)
{
    if(b > a)
    {
        return a;
    }
    
    return b;
}

double max(double a, double b)
{
    if(a > b)
    {
        return a;
    }
    
    return b;
}

int sroot(int n)
{
  double low = min(1, n);
  double high = max(1, n);
  double mid = 0.0;

  while(100 * low * low < n) 
  {
      low *= 10;
  }
  
  while(0.01 * high * high > n) 
  {
      high *= 0.1;
  }

  for(int i = 0 ; i < 100 ; i++)
  {
      mid = (low + high) / 2;
      
      if (mid * mid == n) 
      {
          return mid;
      }
      
      if (mid * mid > n)
      {
          high = mid;
      }
      else
      {
          low = mid;
      }
  }
  
  return (int) mid;
}

int jumpSearch(int array[], int x, int n)
{
    int step = sroot(n);
    int prev = 0;
    
    while (array[(int) min(step, n) - 1] < x)
    {
        prev = step;
        step += sroot(n);
        if (prev >= n)
            return -1;
    }

    while (array[prev] < x)
    {
        prev++;

        if (prev == min(step, n))
        {
            return -1;
        }
    }
    
    if (array[prev] == x)
    {
        return prev;
    }

    return -1;
}

int main(void)
{
    int arr[] = {24, 69, 121, 157, 420, 666, 1533};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int n = 69;
    int i = jumpSearch(arr, n, size);
    
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
//   "O tamanho ideal do salto é geralmente determinado pela fórmula sqrt(n), onde é o tamanho da lista.
// Binary Search tende a ser mais eficiente em termos de tempo de execução para a maioria dos tamanhos de lista devido à sua complexidade O(logn). Jump Search pode ser útil em contextos específicos, mas geralmente é menos eficiente em comparação com o Binary Search, especialmente para listas muito grandes.
