#include <stdio.h>

void findPairWithSum(int arr[], int n, int target) {
    int low = 0;            
    int high = n - 1;        

    while (low < high) {
        int sum = arr[low] + arr[high];

        if (sum == target) {
            printf("Pair found: (%d, %d)\n", arr[low], arr[high]);
            return;         
        }
        if (sum < target) {
            low++;          
        } else {
            high--;         
        }
    }

    printf("No pair found with the given sum.\n");
}

int main() {
    int n,target;
    printf("enter the number of elements:\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter sorted elements\n");
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    printf("enter target value:\n");
    scanf("%d",&target);
   
    findPairWithSum(arr, n, target);

    return 0;
}
