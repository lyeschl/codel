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

void insertSymbol(SymbolTable* table, const char* identifier, const char* type,bool isConstant) {
    SymbolEntry* newEntry = (SymbolEntry*)malloc(sizeof(SymbolEntry));
    newEntry->identifier = strdup(identifier);
    newEntry->type = strdup(type);
    newEntry->next = table->head;
    table->head = newEntry;
}

void printSymbolTable(SymbolTable* table) {
    SymbolEntry* current = table->head;
    printf("Symbol Table:\n");
    while (current != NULL) {
        printf("%s\t%s\n", current->identifier, current->type);
        current = current->next;
    }
}
