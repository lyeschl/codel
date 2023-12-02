// symbol_table.h
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdbool.h>
typedef struct SymbolEntry {
    char* identifier;
    char* type;  // You can extend this structure to store more information
    bool isConstant;
    struct SymbolEntry* next;
} SymbolEntry;

typedef struct SymbolTable {
    SymbolEntry* head;
} SymbolTable;

// Function declarations
SymbolTable* createSymbolTable();
SymbolEntry* searchSymbol(SymbolTable* table, const char* identifier);
void insertSymbol(SymbolTable* table, const char* identifier, const char* type,bool isConstant);
void modifyEntry(SymbolTable* table, const char* identifier, const char* type, bool isConstant);
void printSymbolTable(SymbolTable* table);
void freeSymbolEntry(SymbolEntry* entry);
void freeSymbolTable(SymbolTable* table);

extern SymbolTable *symbolTable;
#endif  // SYMBOL_TABLE_H
