#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#pragma warning(disable: 4996 6011 6387 6001)

#define CAPACITY 3 // Size of the HashTable.
#define CAPACITY_COLLISION_LIST 10 // Collision list capacity
#define MAX_LINES_REFERENCE 20 // Array's size of reference lines for identifier

unsigned long hash_function(const char* str)
{
    unsigned long i = 0;

    for (unsigned int j = 0; str[j]; j++)
        i += str[j];

    return i % CAPACITY;
}

enum Var_Types { BOOLEAN, INTEGER, FLOAT, STRING };
enum Var_concept { VARIABLE, ARR, FUNC, PROC };

struct data_value
{
    unsigned long memory_assign;
    Var_Types type;
    unsigned long bytes_size;
    unsigned long source_line_definition;
    char source_lines_used[MAX_LINES_REFERENCE];
    unsigned int scope;
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

void free_item(Ht_item* item)
{
    // Frees an item
    free(item->identifier_string);
    free(item);
}

void free_table(HashTable & table)
{
    // Frees the table.
    for (unsigned int i = 0; i < CAPACITY; i++)
        if (table.items[i] != NULL)
        {
            free_item(table.items[i]);
            table.items[i] = NULL;
            table.size_of_collision_list[i] = -1;
            for (unsigned int j = 0; j < CAPACITY_COLLISION_LIST; j++)
                if (table.collision_list[i][j] != NULL)
                {
                    free(table.collision_list[i][j]);
                    table.collision_list[i][j] = NULL;
                }
        }
    table.count = 0;
}

void ht_insert(HashTable& table, const char* value, data_value data)
{
    // Creates the item.
    Ht_item* item = create_item(value);
    item->value.bytes_size = data.bytes_size;
    item->value.type = data.type;
    item->value.memory_assign = data.memory_assign;
    item->value.scope = data.scope;
    item->value.source_line_definition = data.source_line_definition;
    strcpy(item->value.source_lines_used, data.source_lines_used);
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

void ht_delete(HashTable & table, const char* key)
{
    // Deletes an item from the table.
    int index = hash_function(key);
    Ht_item* item = table.items[index];
    if (item == NULL)
        // Does not exist.
        return;
    else
    {
        if (strcmp(item->identifier_string, key) == 0 && table.size_of_collision_list[index] == -1)
        {
            // Collision list does not exist.
            // Remove the item.
            // Set table index to NULL.
            table.items[index] = NULL;
            free_item(item);
            table.count--;
            return;
        }
        else if (strcmp(item->identifier_string, key) == 0 && table.size_of_collision_list[index] != -1)
        {
            // Collision list exists.
            if (strcmp(item->identifier_string, key) == 0)
            {
                // Remove this item.
                // Set the head of the list as the new item.
                strcpy(table.items[index]->identifier_string, table.collision_list[index][0]->identifier_string);
                table.items[index]->value.bytes_size = table.collision_list[index][0]->value.bytes_size;
                table.items[index]->value.type = table.collision_list[index][0]->value.type;
                table.items[index]->value.memory_assign = table.collision_list[index][0]->value.memory_assign;
                table.items[index]->value.scope = table.collision_list[index][0]->value.scope;
                table.items[index]->value.source_line_definition = table.collision_list[index][0]->value.source_line_definition;
                strcpy(table.items[index]->value.source_lines_used, table.collision_list[index][0]->value.source_lines_used);
                for (int j = 0; j < table.size_of_collision_list[index] - 1; j++)
                {
                    strcpy(table.collision_list[index][j]->identifier_string, table.collision_list[index][j + 1]->identifier_string);
                    table.collision_list[index][j]->value.bytes_size = table.collision_list[index][j + 1]->value.bytes_size;
                    table.collision_list[index][j]->value.memory_assign = table.collision_list[index][j + 1]->value.memory_assign;
                    table.collision_list[index][j]->value.scope = table.collision_list[index][j + 1]->value.scope;
                    table.collision_list[index][j]->value.source_line_definition = table.collision_list[index][j + 1]->value.source_line_definition;
                    table.collision_list[index][j]->value.type = table.collision_list[index][j + 1]->value.type;
                    strcpy(table.collision_list[index][j]->value.source_lines_used, table.collision_list[index][j + 1]->value.source_lines_used);
                }
                free(table.collision_list[index][table.size_of_collision_list[index] - 1]->identifier_string);
                table.collision_list[index][table.size_of_collision_list[index] - 1] = NULL;
                table.size_of_collision_list[index]--;
                table.count--;
                return;
            }
        }
        // Find on collision list and delete.
        for (int it = 0; it < table.size_of_collision_list[index]; it++)
            if (strcmp(table.collision_list[index][it]->identifier_string, key) == 0)
            {
                for (int j = it; j < table.size_of_collision_list[index] - 1; j++)
                {
                    strcpy(table.collision_list[index][j]->identifier_string, table.collision_list[index][j + 1]->identifier_string);
                    table.collision_list[index][j]->value.bytes_size = table.collision_list[index][j + 1]->value.bytes_size;
                    table.collision_list[index][j]->value.memory_assign = table.collision_list[index][j + 1]->value.memory_assign;
                    table.collision_list[index][j]->value.scope = table.collision_list[index][j + 1]->value.scope;
                    table.collision_list[index][j]->value.source_line_definition = table.collision_list[index][j + 1]->value.source_line_definition;
                    table.collision_list[index][j]->value.type = table.collision_list[index][j + 1]->value.type;
                    strcpy(table.collision_list[index][j]->value.source_lines_used, table.collision_list[index][j + 1]->value.source_lines_used);
                }
                free(table.collision_list[index][table.size_of_collision_list[index] - 1]->identifier_string);
                table.collision_list[index][table.size_of_collision_list[index] - 1] = NULL;
                table.size_of_collision_list[index]--;
                table.count--;
                return;
            }
        
    }
}

void print_search(HashTable & table, const char* key)
{
    unsigned long pos = 0;
    long collision_pos_lis = -1;
    if (!ht_search(table, key, pos, collision_pos_lis))
    {
        printf("Key:%s does not exist\n", key);
        return;
    }
    else if (collision_pos_lis != -1)
            printf("Key:%s, Index:%d, Collision list position:%d\n", key, pos, collision_pos_lis);
         else
            printf("Key:%s, Index:%d\n", key, pos);
}

void print_table(HashTable table)
{
    printf("\nHash Table\n-------------------\n");

    for (int i = 0; i < CAPACITY; i++)
        if (table.items[i])
        {
            printf("Index:%d, Key:%s\n", i, table.items[i]->identifier_string);
            for (int it = 0; it < table.size_of_collision_list[i]; it++)
                printf("Index:%d, Collision list position:%d, Key:%s\n", i, it, table.collision_list[i][it]->identifier_string);
        }
    printf("-------------------\n\n");
}
