#include <stdio.h>
#include "rodcut.h"

void initialize_arrays(int rod_length, int dynamic[], int cut[]) {
    for (int i = 0; i <= rod_length; i++) {
        dynamic[i] = 0;    // Initialize dynamic array to 0
        cut[i] = -1;       // Initialize cut array to -1
    }
}

void max_value_calculation(int rod_length, int lengths[], int values[], int dynamic[], int number_of_pieces, int cut[]) {
    // Loop through each possible rod length from 1 to rod_length
    for (int i = 1; i <= rod_length; i++) {
        // Check each piece of rod
        for (int j = 0; j < number_of_pieces; j++) {
            // If the piece can be used (length <= i)
            if (lengths[j] <= i) {
                // Calculate the new value if this piece is included
                int new_value = values[j] + dynamic[i - lengths[j]];
                if (dynamic[i] < new_value) {
                    dynamic[i] = new_value;  // Update the max value for this length
                    cut[i] = j;              // Record which piece we used for this length
                }
            }
        }
    }
}

void print_results(int rod_length, int lengths[], int dynamic[], int values[], int cut[]) {
    int total_value = 0;
    printf("Results:\n");

    while (rod_length > 0 && cut[rod_length] != -1) {
        int cut_index = cut[rod_length];
        int cut_length = lengths[cut_index];
        int cut_value = values[cut_index];

        printf("Cut length: %d, value: %d\n", cut_length, cut_value);
        total_value += cut_value;
        rod_length -= cut_length;
    }

    printf("Total value: %d\n", total_value);

    if (rod_length > 0) {
        printf("Remaining rod length: %d\n", rod_length);
    } else if (total_value == 0) {
        printf("No cuts have been made\n");
    }
}