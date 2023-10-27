#include <stdio.h>

void spiral_matrix(int, int);

int main() {
	spiral_matrix(6, 5);
	return 0;
}

void spiral_matrix(int n, int k) {
	
	int arr[n][n];
  int size = n * n;
  int counter = 1, steps = 1;
  int i, y, x;

  y = n % 2 == 0 ? n / 2 - 1: n / 2; 
  x = n / 2;  
  
  arr[y][x] = k;
  
  while (counter < size) {
    
    arr[++y][x] = ++k;
    counter += 1;

    for (i = 0; i < steps; i += 1, counter += 1) {
      arr[y][--x] = ++k;  
    }

    for (i = 0; i < steps; i += 1, counter += 1) {
      arr[--y][x] = ++k;  
    }

    if (counter == size) break; 
    steps += 1;

    arr[--y][x] = ++k;
    counter += 1;

    for (i = 0; i < steps; i += 1, counter += 1) {
      arr[y][++x] = ++k; 
    }

    for (i = 0; i < steps; i += 1, counter += 1) {
      arr[++y][x] = ++k; 
    }

    if (counter == size) break; 
    steps += 1;
  
  }

  for(i = 0; i < n; i += 1) {
   	for(int j = 0; j < n; j += 1) {
    	printf("%3d", arr[i][j]);
 		}
		printf("\n");	   
	}
	return; 

}   