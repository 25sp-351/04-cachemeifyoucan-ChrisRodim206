#include <stdio.h>
#include "rodcut.h"
#define Max_length 1000



int main() {
    int rod_length = 0;
    int lengths[Max_length];
    int values[Max_length];
    int number_of_pieces = 0;

    // Get the length of the rod from the user
    printf("Enter the length of the rod: ");
    scanf("%d", &rod_length);

    if (rod_length <= 0) {
        printf("Invalid rod length\n");
        return 0;
    } else if (rod_length > Max_length) {
        printf("Rod length exceeds max limit\n");
        return 0;
    }

    // Get the available pieces and their values
    printf("Enter rod length pieces and their corresponding values (e.g., 1 2 for length 1, value 2):\n");
    while (scanf("%d %d", &lengths[number_of_pieces], &values[number_of_pieces]) == 2) {
        if (lengths[number_of_pieces] <= 0 || values[number_of_pieces] <= 0) {
            printf("Invalid input\n");
            return 0;
        }

        number_of_pieces++;

        if (number_of_pieces >= Max_length) {
            printf("Maximum number of pieces exceeded\n");
            return 0;
        }
    }

    // Initialize dynamic programming arrays
    int dynamic[rod_length + 1];
    int cut[rod_length + 1];

    initialize_arrays(rod_length, dynamic, cut);
    max_value_calculation(rod_length, lengths, values, dynamic, number_of_pieces, cut);
    print_results(rod_length, lengths, dynamic, values, cut);

    return 0;
}
