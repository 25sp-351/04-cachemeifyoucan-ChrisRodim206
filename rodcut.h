#ifndef RODCUT_H
#define RODCUT_H

#define Max_length 1000

void initialize_arrays(int rod_length, int dynamic[], int cut[]);
void max_value_calculation(int rod_length, int lengths[], int values[], int dynamic[], int number_of_pieces, int cut[]);
void print_results(int rod_length, int lengths[], int dynamic[], int values[], int cut[]);

#endif