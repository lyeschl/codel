// symbol_table.h
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef struct SymbolEntry {
    char* identifier;
    char* type;  // You can extend this structure to store more information
    struct SymbolEntry* next;
} SymbolEntry;

typedef struct SymbolTable {
    SymbolEntry* head;
} SymbolTable;

// Function declarations
SymbolTable* createSymbolTable();
SymbolEntry* searchSymbol(SymbolTable* table, const char* identifier);
void insertSymbol(SymbolTable* table, const char* identifier, const char* type);
void printSymbolTable(SymbolTable* table);

#endif  // SYMBOL_TABLE_H
