/*
Description:
This program reads an array of animals from {animals.txt}, which has information about each animal, including name, species, gender, age, and weight.
The program filters the animal records based on the user's specified species and gender. The name, age, and weight of the matched animal are then 
formatted and written to {result.txt} to facilitate the adoption process. By making it easier for shelter personnel to discover possible adopters, 
this automated technology helps animals find homes quickly and effectively.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Set maximum length constants to avoid buffer overflow.
#define MAX_NAME_LENGTH 100
#define MAX_ANIMALS 200

// Define an animal's structure to hold data regarding individual animals.
typedef struct {
    char name[MAX_NAME_LENGTH];
    char species[MAX_NAME_LENGTH];
    char gender[MAX_NAME_LENGTH];
    int age;
    double weight;
} Animal;

// Functions for reading and writing data about animals.
int loadAnimalsFromFile(const char *filename, Animal animals[]);
void saveMatchingAnimalsToFile(const char *filename, Animal animals[], int count, const char *species, const char *gender);

int main() {
    // Set up an array to hold the file's animal data.
    Animal animals[MAX_ANIMALS] = {0};  
    char species[MAX_NAME_LENGTH];
    char gender[MAX_NAME_LENGTH];

    // Read the gender and species using the standard input (stdin).
    if (scanf("%99s %99s", species, gender) != 2) {
        fprintf(stderr, "Error reading species and gender.\n");
        return 1; // If the input is invalid, exit with an error code.
    }

    // Open the file and import the animal data into the array.
    int count = loadAnimalsFromFile("animals.txt", animals);
    // Save the animals to 'result.txt' that meet the input criteria.
    saveMatchingAnimalsToFile("results.txt", animals, count, species, gender);

    return 0;  
}

// A function that loads animals into an array of Animal structures from a file.
int loadAnimalsFromFile(const char *filename, Animal animals[]) {
    // Try to read the file by opening it.
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file"); // Print an error message if the file cannot be opened.
        return 0; // Return 0 to indicate no animals were loaded.
    }

    // Read the animals in the file until you reach the allotted number or run out of animals to read.
    int count = 0;
    while (count < MAX_ANIMALS && fscanf(file, "%99s %99s %99s %d %lf", 
           animals[count].name, animals[count].species, animals[count].gender,
           &animals[count].age, &animals[count].weight) == 5) {
        count++;
    }

    fclose(file); 
    return count; // Here we return the no of animals loaded.
}

// The Function to save animals to a file that correspond to a given species and gender.
void saveMatchingAnimalsToFile(const char *filename, Animal animals[], int count, const char *species, const char *gender) {
    // Try to open the document for editing.
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Go through every loaded animal in a loop and look for matches.
    for (int i = 0; i < count; i++) {
        // Write the current animal to the file if it belongs to the designated species and gender.
        if (strcmp(animals[i].species, species) == 0 && strcmp(animals[i].gender, gender) == 0) {
            // Here we write the animal's name, age, and weight to the file.
            fprintf(file, "%s %d %.2f\n", animals[i].name, animals[i].age, animals[i].weight);
        }
    }

    fclose(file); // Here we close the file. 
}