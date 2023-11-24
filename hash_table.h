#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

#pragma warning(disable: 4996 6011 6387 6001)

#define CAPACITY 100 // Size of the HashTable.
#define CAPACITY_COLLISION_LIST 10 // Collision list capacity
#define MAX_LINES_REFERENCE 20 // Array's size of reference lines for identifier

unsigned long memory_assign = 0;

unsigned long hash_function(const char* str)
{
    unsigned long i = 0;

    for (unsigned int j = 0; str[j]; j++)
        i += str[j];

    return i % CAPACITY;
}

enum Var_Types { BOOLEAN, INTEGER, FLOAT, STRING, VOID, CONST_ENTERO, CONST_REAL, CONST_CADENA };

struct data_value
{
    unsigned long memory_assign;
    Var_Types type;
    unsigned long bytes_size;
    unsigned long source_line_definition;
    char* source_lines_used;
    unsigned short scope;
};

// Defines the HashTable item.
struct Ht_item
{
    char* identifier_string;
    data_value value;
    
};

// Defines the HashTable.
struct HashTable
{
    // Contains an array of pointers to items.
    Ht_item* items[CAPACITY] = { NULL };
    Ht_item* collision_list[CAPACITY][CAPACITY_COLLISION_LIST] = { NULL };
    int size_of_collision_list[CAPACITY] = { -1 };
    unsigned int count = 0;
};

// Hash table functions
void collision_list_insert(HashTable& table, unsigned int position_item, Ht_item * item)
{
    // Inserts the item onto the LinkedList.
    unsigned int position = table.size_of_collision_list[position_item]++;
    table.collision_list[position_item][position] = item;
}

Ht_item* create_item(const char* value)
{
    // Creates a pointer to a new HashTable item.
    Ht_item* item = (Ht_item*)malloc(sizeof(Ht_item));
    item->identifier_string = (char*)malloc(strlen(value) + 1);
    strcpy(item->identifier_string, value);
    return item;
}

void create_table(HashTable & table)
{
    // Creates a new HashTable.
    table.count = 0;
    for (unsigned int i = 0; i < CAPACITY; i++)
    {
        table.items[i] = NULL;
        table.size_of_collision_list[i] = 0;
        for (unsigned int j = 0; j < CAPACITY_COLLISION_LIST; j++)
            table.collision_list[i][j] = NULL;
    }
}

void ht_insert(HashTable& table, const char* value, data_value data)
{
    // Creates the item.
    Ht_item* item = create_item(value);
    item->value.memory_assign = data.memory_assign;
    item->value.bytes_size = data.bytes_size;
    item->value.type = data.type;
    item->value.scope = data.scope;
    item->value.source_line_definition = data.source_line_definition;
    item->value.source_lines_used = data.source_lines_used;
    // Computes the index.
    unsigned int index = hash_function(value);
    if (table.items[index] == NULL)
        // Insert directly.
        table.items[index] = item;
    else
        //Handle the collision.
        collision_list_insert(table, index, item);
    table.count++;
}

bool ht_search(HashTable table, const char* key, unsigned long & index, long & collision_list_position)
{
    // Searches for the key in the HashTable.
    // Returns NULL if it doesn't exist.
    index = hash_function(key);
    Ht_item* item = table.items[index];
    
    // Provide only non-NULL values.
    if (item != NULL)
    {
        if (strcmp(item->identifier_string, key) == 0)
                return true;

        collision_list_position = -1;
        for (Ht_item* actual : table.collision_list[index])
        {
            collision_list_position++;
            if (strcmp(actual->identifier_string, key) == 0)
                return true;
        }
    }
    return false;
}

bool ht_is_scope_already_declared(HashTable table, const char* key, unsigned long index, unsigned short scope) {
    Ht_item* item = table.items[index];
    if (item != NULL)
    {
        if(strcmp(item->identifier_string, key) == 0 && item->value.scope == scope)
            return true;
        for(int i = 0; i < table.size_of_collision_list[index]; i++)
        {
            if(strcmp(table.collision_list[index][i]->identifier_string, key) == 0 && item->value.scope == scope)
                return true;
        }
    }
    return false;
}

bool ht_is_scope_less_than_defined(HashTable table, const char* key, unsigned long index, unsigned short scope) {
    Ht_item* item = table.items[index];
    if (item != NULL)
    {
        if(strcmp(item->identifier_string, key) == 0 && item->value.scope <= scope)
            return true;
        for(int i = 0; i < table.size_of_collision_list[index]; i++)
        {
            if(strcmp(table.collision_list[index][i]->identifier_string, key) == 0 && item->value.scope < scope)
                return true;
        }
    }
    return false;
}



void ht_insert_lines_used(HashTable& table, const char* key, unsigned long index, unsigned long line, unsigned short scope){
    Ht_item* item = table.items[index];
    if (item != NULL)
    {
        if (strcmp(item->identifier_string, key) == 0)
        {
            if (item->value.scope == scope)
            {
                char* new_line = (char*)malloc(sizeof(char) * MAX_LINES_REFERENCE);
                sprintf(new_line, "%s %lu",item->value.source_lines_used, line);
                item->value.source_lines_used = new_line;
            }
            else {
                for (unsigned int i = 0; i < table.size_of_collision_list[index]; i++)
                {
                    if (strcmp(table.collision_list[index][i]->identifier_string, key) == 0 && table.collision_list[index][i]->value.scope == scope)
                    {
                        char* new_line = (char*)malloc(sizeof(char) * MAX_LINES_REFERENCE);
                        sprintf(new_line, "%s %lu",table.collision_list[index][i]->value.source_lines_used, line);
                        table.collision_list[index][i]->value.source_lines_used = new_line;
                        return;
                    }
                }                
                if (item->value.scope == 0)
                {
                    char* new_line = (char*)malloc(sizeof(char) * MAX_LINES_REFERENCE);
                    sprintf(new_line, "%s %lu",item->value.source_lines_used, line);
                    item->value.source_lines_used = new_line;
                }
                else {
                    for (unsigned int i = 0; i < table.size_of_collision_list[index]; i++)
                    {
                        if (strcmp(table.collision_list[index][i]->identifier_string, key) == 0 && table.collision_list[index][i]->value.scope == 0)
                        {
                            char* new_line = (char*)malloc(sizeof(char) * MAX_LINES_REFERENCE);
                            sprintf(new_line, "%s %lu",table.collision_list[index][i]->value.source_lines_used, line);
                            table.collision_list[index][i]->value.source_lines_used = new_line;
                            return;
                        }
                    }
                }
            }
        }
    }
}

bool ht_return_all_values_not_used(HashTable ht, std::string & vars_not_used) {
    bool is_not_used = false;
    std::string acum = "";
    for (unsigned int i = 0; i < CAPACITY; i++)
    {
        if (ht.items[i] != NULL)
        {
            std::string str(ht.items[i]->value.source_lines_used);
            if (str.length() < 1)
            {
                is_not_used = true;
                acum += ht.items[i]->identifier_string;
                acum +=  ", ";
            }
            for (unsigned int j = 0; j < ht.size_of_collision_list[i]; j++)
            {
                if (ht.collision_list[i][j] != NULL)
                {
                    std::string strcl = ht.collision_list[i][j]->value.source_lines_used;

                    if (strcl.length() < 0)
                    {
                        is_not_used = true;
                        acum += ht.collision_list[i][j]->identifier_string;
                        acum +=  ", ";
                    }
                }
            }
        }
    }
    vars_not_used = acum;
    return is_not_used;
}

void print_table(HashTable table)
{
    printf("\nHash Table\n-------------------\n");

    for (int i = 0; i < CAPACITY; i++)
        if (table.items[i])
        {
            printf("Index:%d, Key:%s, Mem_assign: %d, Type: %d, Byte_Size: %d, Line_def: %d, Scope: %d, Lines_used:%s\n", 
            i, 
            table.items[i]->identifier_string, 
            table.items[i]->value.memory_assign,
            table.items[i]->value.type,
            table.items[i]->value.bytes_size,
            table.items[i]->value.source_line_definition,
            table.items[i]->value.scope,
            table.items[i]->value.source_lines_used);
            for (int it = 0; it < table.size_of_collision_list[i]; it++)
                printf("Index:%d, Collision list position:%d, Key:%s, Mem_assign: %d, Type: %d, Byte_Size: %d, Line_def: %d, Scope: %d, Lines_used:%s\n", 
                i, 
                it, 
                table.collision_list[i][it]->identifier_string, 
                table.collision_list[i][it]->value.memory_assign,
                table.collision_list[i][it]->value.type,
                table.collision_list[i][it]->value.bytes_size,
                table.collision_list[i][it]->value.source_line_definition,
                table.collision_list[i][it]->value.scope,
                table.collision_list[i][it]->value.source_lines_used);
        }
    printf("-------------------\n\n");
}