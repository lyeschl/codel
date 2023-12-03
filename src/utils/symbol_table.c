// symbol_table.c
#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SymbolTable* createSymbolTable() {
    SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
    table->head = NULL;
    return table;
}

SymbolEntry* searchSymbol(SymbolTable* table, const char* identifier) {
    SymbolEntry* current = table->head;
    while (current != NULL) {
        if (strcmp(current->identifier, identifier) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void insertSymbol(SymbolTable* table, const char* identifier, const char* type, bool isConstant) {
    // Check if the symbol is already in the table
    if (searchSymbol(table, identifier) != NULL) {
        // Handle the case where the symbol is already present
        fprintf(stderr, "Symbol '%s' is already declared\n", identifier);
        // You may choose to handle this error in a way that suits your needs
        // For example, you could exit the program or take appropriate action.
        exit(EXIT_FAILURE);
    }

    SymbolEntry* newEntry = (SymbolEntry*)malloc(sizeof(SymbolEntry));
    newEntry->identifier = strdup(identifier);
    newEntry->type = strdup(type);
    newEntry->isConstant = isConstant;
    newEntry->next = table->head;
    table->head = newEntry;
}

void modifyEntry(SymbolTable* table, const char* identifier, const char* type, bool isConstant) {
    SymbolEntry* current = table->head;

    // Search for the symbol in the table
    while (current != NULL) {
        if (strcmp(current->identifier, identifier) == 0) {
            // Modify the type and isConstant fields
            free(current->type); // Free the existing type
            current->type = strdup(type); // Set the new type
            current->isConstant = isConstant; // Set the constant status

            // Break out of the loop once the symbol is found and modified
            break;
        }

        // Move to the next entry in the table
        current = current->next;
    }
}

void printSymbolTable(SymbolTable* table) {
    SymbolEntry* current = table->head;
    printf("Symbol Table:\n");
    while (current != NULL) {
        printf("%s\t%s\t%s\n", current->identifier, current->type, current->isConstant ? "CONSTANT" : "VARIABLE");
        current = current->next;
    }
}
// Function to free a single SymbolEntry
void freeSymbolEntry(SymbolEntry* entry) {
    free(entry->identifier);
    free(entry->type);
    free(entry);
}

// Function to free the entire SymbolTable
void freeSymbolTable(SymbolTable* table) {
    SymbolEntry* current = table->head;
    SymbolEntry* next;

    // Free each SymbolEntry in the table
    while (current != NULL) {
        next = current->next;
        freeSymbolEntry(current);
        current = next;
    }

    // Finally, free the SymbolTable itself
    free(table);
}
