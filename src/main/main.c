#include "../../globals.h"
#define INPUT_END_MARKER "%%"
SymbolTable* symbolTable;
stack* parenth_stack;
stack* bracket_stack;

// Helper function to get the size of the array
extern int arr_size(char** arr) {
    int size = 0;
    while (arr[size] != NULL) {
        size++;
    }
    return size;
}

int main(int argc, char *argv[]) {

symbolTable = createSymbolTable();

parenth_stack = createStack();
bracket_stack = createStack();
init_stack(parenth_stack, 50);
init_stack(bracket_stack, 50);

    FILE *inputFile;

    if (argc == 1) {
        // No command-line arguments provided, read input from the user
        printf("Enter your program code (Type '%s' on a line by itself to end input):\n", INPUT_END_MARKER);

        char buffer[1024];
        char *inputLines = NULL;
        size_t inputSize = 0;

        while (1) {
            if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                break;  // EOF or error, exit the loop
            }

            if (strcmp(buffer, INPUT_END_MARKER "\n") == 0) {
                break;  // End marker encountered, exit the loop
            }

            size_t lineLength = strlen(buffer);

            // Resize the input buffer
            inputLines = realloc(inputLines, inputSize + lineLength + 1);

            // Copy the new line to the input buffer
            strcpy(inputLines + inputSize, buffer);

            // Update the total input size
            inputSize += lineLength;
        }

        // Process the entire input
        if (inputSize > 0) {
            yyin = fmemopen(inputLines, inputSize, "r");
            yyparse();
        }

        // Clean up
        free(inputLines);
    } else if (argc == 2) {
        // Command-line argument provided, open the specified file
        inputFile = fopen(argv[1], "r");

        if (inputFile == NULL) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }

        yyin = inputFile;
        yyparse();

        fclose(inputFile);
    } else {
        fprintf(stderr, "Usage: %s [inputfile.txt]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (!stackIsEmpty(parenth_stack)) {
        fprintf(stderr, "Error: Parentheses are not balanced\n");
        exit(EXIT_FAILURE);
    }

    if (!stackIsEmpty(bracket_stack)) {
        fprintf(stderr, "Error: Brackets are not balanced\n");
        exit(EXIT_FAILURE);
    }

    printf("Compilation completed, No Errors found\n");

    printSymbolTable(symbolTable);  // Print the symbol table at the end

    freeSymbolTable(symbolTable);
    return 0;

}

