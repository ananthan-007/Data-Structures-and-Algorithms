/*******************************************************
 * --------------------------------------------------- *
 *  Project   : Linear_search                          *
 *  Author    : Ananthakrishnan K V                    *
 *  Version   : 1.0                                   *
 *  Language  : C                                      *
 *  Created   : 13-07-2025                             *
 *  Updated   : 13-07-2025                             *
 *  Purpose   : C code to linearly search x in arr[].  *
 * --------------------------------------------------- *
 *            Let code flow like poetry! 🚀            *
 *******************************************************/


#include <stdio.h>

int search(int arr[], int numOfElements, int x)
{
    for (int i = 0; i < numOfElements; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Main function to test the search function
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int numOfElements = sizeof(arr) / sizeof(arr[0]);

    // Function call
    int result = search(arr, numOfElements, x);
    (result == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", result);
    return 0;
}
