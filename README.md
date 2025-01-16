# Animal Adoption Filter

This C program automates the process of filtering animal records from a shelter's database (`animals.txt`) based on species and gender. It outputs the details of matching animals to a file (`results.txt`) to assist in the adoption process.

## Features
- Reads animal records from a file (`animals.txt`), containing details such as name, species, gender, age, and weight.
- Filters animals based on user-specified species and gender.
- Outputs matching animals' name, age, and weight to a file (`results.txt`).
- Handles up to 200 animal records with error handling for file operations.

## File Structure
### Input File (`animals.txt`):
The input file should have animal details in the following format:

## How to Compile and Run
1. Save the program as `animal_adoption_filter.c`.
2. Compile the program:
   ```bash
   gcc animal_adoption_filter.c -o animal_adoption_filter
