/*******************************************************
 * --------------------------------------------------- *
 *  Project   : Binary_search                          *
 *  Author    : Ananthakrishnan K V                    *
 *  Version   : v1.0                                   *
 *  Language  : C                                      *
 *  Created   : 14-07-2025                             *
 *  Updated   : 14-07-2025                             *
 *  Purpose   : C code to binary search x in arr[].    *
 * --------------------------------------------------- *
 *            Let code flow like poetry! 🚀            *
 *******************************************************/


#include <stdio.h>

int binarySearch(int arr[], int size, int value)
{
    // Initialize search boundaries
    int low = 0, high = size - 1;
    
    while (low <= high)
    {
        // Calculate middle index
        int mid = low + (high - low) / 2;

        // Check if the middle element is our target
        if (arr[mid] == value)
        {
            return mid; // Found the value, return its index
        }

        // If middle element is smaller than target value
        // Search in the right half of the array
        if (arr[mid] < value)
        {
            low = mid + 1; // Eliminate left half including mid
        }
        else
        {
            // If middle element is greater than target value
            // Search in the left half of the array
            high = mid - 1; // Eliminate right half including mid
        }
    }

    // Value not found in the array
    return -1;
}

int main()
{
    int value;
    long int size = 100000000; // Large array size for demonstration
    int arr[size];

    // Initialize array with sorted values (0 to size-1)
    // This creates a perfect scenario for binary search testing
    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }
    
    // Get user input for the value to search
    printf("Enter the value to search (should be <size): ");
    scanf("%d", &value);

    // Perform binary search
    int result = binarySearch(arr, size, value);

    // Display the result using ternary operator
    (result == -1) ? printf("Value not Found!") : printf("Value found at index %d", result);
    
    return 0;
}