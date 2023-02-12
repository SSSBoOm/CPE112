#include <stdio.h>

int main() {
    int sum;
    int sizematrix;
    int matrix[100][100];
    
    scanf("%d",&sizematrix);
    
     for(int i = 0 ; i < sizematrix; i++){
        for(int j = 0 ; j < sizematrix; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    
    for(int i = 0 ; i<sizematrix; i++){
      sum += matrix[i][i];
        
    }
    printf("%d" , sum);
    return 0;
}