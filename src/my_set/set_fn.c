#include <main_header.h>

set_t* new_set()
{
    set_t* new = malloc(sizeof(set_t));
    new->hash_v = (hash_t){.data = {false}};
    new->hash_string = hash_string;
    new->clear_hash = clear_hash;
    return new;
}

bool include(set_t* set, char* str)
{
    // int hash = hash_string(str);
    int hash = set->hash_string(str);
    if (set->hash_v.data[hash] == true)
    {
        return true;
    }
    return false;
}

void add(set_t* set, char* str)
{
    // int hash = hash_string(str);
    int hash = set->hash_string(str);

    set->hash_v.data[hash] = true;
}

void remove_data(set_t* set, char* str)
{
    // int hash = hash_string(str);
    int hash = set->hash_string(str);

    set->hash_v.data[hash] = false;
}