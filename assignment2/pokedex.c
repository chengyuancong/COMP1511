// Assignment 2 19T2 CP1511: Pokedex
// pokedex.c
//
// This program was written by Yuancoong Cheng (z5285978)
// on 8 Apr 2020
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: Minor clarifications about `struct pokenode`.
// Version 1.1.0: Moved destroy_pokedex function to correct location.
// Version 1.1.1: Renamed "pokemon_id" to "id" in change_current_pokemon.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Add any extra #includes your code needs here.
//
// But note you are not permitted to use functions from string.h
// so do not #include <string.h>

#include "pokedex.h"

// Add your own defines here.
#define TRUE 1
#define FALSE 0

// Note you are not permitted to use arrays in struct pokedex,
// you must use a linked list.
//
// You are also not permitted to use arrays in any of the functions
// below.
//
// The only exception is that char arrays are permitted for
// search_pokemon and functions it may call, as well as the string
// returned by pokemon_name (from pokemon.h).
//
// You will need to add fields to struct pokedex.
// You may change or delete the head field.

struct pokedex {
    struct pokenode *head;    // Always points to the head of pokedex.
    struct pokenode *select;  // Points to selected pokenode.
    struct pokenode *curr;    // Points to current pokenode when traversing.
    struct pokenode *temp;    // To temporarily save an address for other fields.
};                            


// You don't have to use the provided struct pokenode, you are free to
// make your own struct instead.
// If you use the provided struct pokenode, you will need to add fields
// to it to store other information.

struct pokenode {
    struct pokenode *next;    // Points to next node.  
    struct pokenode *evolve;  // Points to next evolution pokenode.
    Pokemon         pokemon;  // Points to corresponding pokemon.
    int found;                // An indicator for 'found' or not.
};

// Add any other structs you define here.


// Add prototypes for any extra functions you create here.
static struct pokenode *create_node(Pokemon pokemon, struct pokenode *next);
static struct pokenode *last(Pokedex pokedex);
static int check(Pokedex pokedex,Pokemon pokemon);
static void name_asterisk(char *name);
static void destroy_node(struct pokenode *node);
static void print_evolve(struct pokenode *node);
static int contain(char *text, char *name);
static void find_all(Pokedex pokedex);
static char *lowercase(char *string, int length);


// You need to implement the following 20 functions.
// You can find descriptions of what each function should do in pokedex.h

Pokedex new_pokedex(void) {
    Pokedex new_pokedex = malloc(sizeof (struct pokedex));
    assert(new_pokedex != NULL);
    new_pokedex->head = NULL;       // All fields are set to NULL 
    new_pokedex->select = NULL;     // after a new pokedex is created.
    new_pokedex->curr = NULL;
    new_pokedex->temp = NULL;    
    return new_pokedex;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

// Check if the pokemon has been added before creating a new pokenode.
// 
// Use creat_node to create a new pokenode contains this pokemon 
// and its next field is NULL as it is last pokenode. Then the make the 
// previous last pokenode points to this new one.
// 
// After first pokenode is created, head points to new one.
// 
// Current and selected points to head.
void add_pokemon(Pokedex pokedex, Pokemon pokemon) {
    if (check(pokedex, pokemon) == TRUE) {
        struct pokenode *new = create_node(pokemon, NULL);
        if (pokedex->head == NULL) {
            pokedex->head = new;
            pokedex->select = pokedex->head; 
            pokedex->curr = pokedex->head;
        } else {
            last(pokedex)->next = new;
        }
    } else {
        fprintf(stderr, "Exiting because this pokemon has been added.\n");
        exit(1);
    }
}

// Print the detail of pokemon in selected pokenode.
// Hide information if it is not 'found'.
void detail_pokemon(Pokedex pokedex) {
    if (pokedex->select != NULL) {
        pokemon_type first = pokemon_first_type(pokedex->select->pokemon);
        pokemon_type second = pokemon_second_type(pokedex->select->pokemon);
        printf("Id: %03d\n", pokemon_id(pokedex->select->pokemon));
        if (pokedex->select->found == TRUE) {
            printf("Name: %s\n", pokemon_name(pokedex->select->pokemon));
            printf("Height: %.1lfm\n", pokemon_height(pokedex->select->pokemon));
            printf("Weight: %.1lfkg\n", pokemon_weight(pokedex->select->pokemon));
            if (second == NONE_TYPE) {
                printf("Type: %s\n", pokemon_type_to_string(first));
            } else {
                printf("Type: %s %s\n", pokemon_type_to_string(first), 
                                        pokemon_type_to_string(second));
            }  
        } else {
            printf("Name: ");
            name_asterisk(pokemon_name(pokedex->select->pokemon));
            printf("Height: --\n");
            printf("Weight: --\n");
            printf("Type: --\n");
        }
    } 
}

// Return the currently selected Pokemon.
// 
// If the Pokedex is empty, an appropriate error message
// has been written in main.c so just return NULL.
Pokemon get_current_pokemon(Pokedex pokedex) {
    if (pokedex->select == NULL) {
        return NULL;
    } else {
        return pokedex->select->pokemon;
    }
}

// Set the currently selected Pokemon to be 'found'.
// If there are no Pokemon in the Pokedex, this function does nothing.
void find_current_pokemon(Pokedex pokedex) {
    if (pokedex->select != NULL) {
        pokedex->select->found = TRUE;
    }
}

// Use curr to traverse pokedex and print pokemon's id and name.
// Print and arrow if it is selected.
// Hide name if it is not 'found'.
void print_pokemon(Pokedex pokedex) {
    pokedex->curr = pokedex->head;
    while (pokedex->curr != NULL) {
        if (pokedex->curr == pokedex->select) {
            printf("--> #%03d: ", pokemon_id(pokedex->curr->pokemon));
        } else {
            printf("    #%03d: ", pokemon_id(pokedex->curr->pokemon));
        }
        if (pokedex->curr->found == TRUE) {
            printf("%s\n", pokemon_name(pokedex->curr->pokemon));
        } else {
            name_asterisk(pokemon_name(pokedex->curr->pokemon));
        }
        pokedex->curr = pokedex->curr->next;
    }
}


////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

// Change the selected Pokemon to be the Pokemon after the selected one.
// If there is no next Pokemon, the current Pokemon is unchanged.
// If there are no Pokemon in the Pokedex, this function does nothing.
void next_pokemon(Pokedex pokedex) {
    if (pokedex->select != NULL && pokedex->select->next != NULL) {
        pokedex->select = pokedex->select->next;
    }
}

// The pokedex has at least one pokenode if select is not NULL.
// 
// If select is also not head, this pokedex has at least two pokenode and select 
// must not be the head, which means select can be changed to previous one.
// 
// Use curr to traverse and find the one before the select and change select to it.
// 
// Otherwise, there is no previous pokemon, current is unchanged
// or this pokedex is empty, this function does nothing.
void prev_pokemon(Pokedex pokedex) {
    pokedex->curr = pokedex->head;
    if (pokedex->select != NULL && pokedex->select != pokedex->head) {
        while (pokedex->curr->next != pokedex->select) {
            pokedex->curr = pokedex->curr->next;
        }
        pokedex->select = pokedex->curr;
    }
}

// Change the currently selected Pokemon to be the Pokemon with the ID `id`.
// Use pokemon_id to check if there is a pokemon with this id.
// If there is no Pokemon with the ID `id`, this function does nothing.
void change_current_pokemon(Pokedex pokedex, int id) {
    pokedex->curr = pokedex->head;
    while (pokedex->curr != NULL && pokemon_id(pokedex->curr->pokemon) != id) {
        pokedex->curr = pokedex->curr->next;
    }
    pokedex->select = pokedex->curr;
}

// Remove the currently selected Pokemon from the Pokedex.
// Count length of this pokedex before removing a pokenode.
// 
// Use temp to save the select one and move select to next or previous
// use next_pokemon and prev_pokemon then remove temp by destroy_node.
void remove_pokemon(Pokedex pokedex) {
    int length = count_total_pokemon(pokedex);
    // If length is zero, there is no selected and pokedex is empty.
    // If length is one, remove head and change all fields to NULL.
    if (length == 1) {    
        destroy_node(pokedex->select);
        pokedex->select = NULL;
        pokedex->curr = NULL;
        pokedex->head = NULL;
        // If length is larger than two, check if select is head or last.
    } else if (length >= 2) {
        // Head is selected.
        if (pokedex->select == pokedex->head) {
            // Save select pokenode.
            pokedex->temp = pokedex->select;
            // Move select to next one.
            next_pokemon(pokedex);
            // Destroy temp pokenode.
            destroy_node(pokedex->temp);
            // Move head to new head.
            pokedex->head = pokedex->select;
            // Last pokenode is selected.
        } else if (pokedex->select->next == NULL) {
            // Save select pokenode.
            pokedex->temp = pokedex->select;
            // Move select to previous one.
            prev_pokemon(pokedex);
            // Destroy temp pokenode.
            destroy_node(pokedex->temp);
            // Set next field of last to NULL.              
            pokedex->select->next = NULL;
            // If length is larger than two and select is neither head nor last,
            // select must between head and last.
        } else {
            // Save select pokenode.
            pokedex->temp = pokedex->select;
            // Move select to previous one.
            prev_pokemon(pokedex);
            // Reconnect the select one and the one after the next one.
            pokedex->select->next = pokedex->select->next->next;
            // Remove the one used to be selected.
            destroy_node(pokedex->temp);
            // The one after the next one now becomes the next.
            // Change select to this one then this remove complete.
            next_pokemon(pokedex);
        }
    } 
}   

// Destroy a given Pokedex from head using temp.
// After all pokenodes are freed by destroy_node, free this pokedex.
void destroy_pokedex(Pokedex pokedex) {
    while (pokedex->head != NULL) {
        pokedex->temp = pokedex->head;
        pokedex->head = pokedex->head->next;
        destroy_node(pokedex->temp);
    }
    free(pokedex);
}

// Return the number of Pokemon in the Pokedex that have been found.
// Use curr to traverse and check if it is 'found'.
int count_found_pokemon(Pokedex pokedex) {
    int counter = 0;
    pokedex->curr = pokedex->head;
    while (pokedex->curr != NULL) {
        if (pokedex->curr->found == TRUE) {
            counter++;
        }
        pokedex->curr = pokedex->curr->next;
    }
    return counter;
}

// Return the total number of Pokemon in the Pokedex.
// Use curr to traverse.
int count_total_pokemon(Pokedex pokedex) {
    int counter = 0;
    pokedex->curr = pokedex->head;
    while (pokedex->curr != NULL) {
        counter++;
        pokedex->curr = pokedex->curr->next;
    }
    return counter;
}


////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add the information that the Pokemon with the ID `from_id` can
// evolve into the Pokemon with the ID `to_id`.
// 
// Use curr and temp to traverse two times to find the from_id and to_id.
// 
// If from_id and to_id both exist and not equal, change current pokenode's
// evolve to temp pokenode. 
// 
// Print error and exit otherwise.
void add_pokemon_evolution(Pokedex pokedex, int from_id, int to_id) {
    pokedex->curr = pokedex->head;
    pokedex->temp = pokedex->head;
    while (pokedex->curr != NULL && pokemon_id(pokedex->curr->pokemon) != from_id) {
        pokedex->curr = pokedex->curr->next;
    }
    while (pokedex->temp != NULL && pokemon_id(pokedex->temp->pokemon) != to_id) {
        pokedex->temp = pokedex->temp->next;
    }
    if (pokedex->curr == NULL || pokedex->temp == NULL || from_id == to_id) {
        fprintf(stderr, "Exiting because wrong IDs.\n");
        exit(1);
    } else {
        pokedex->curr->evolve = pokedex->temp;
    }
}

// Show the evolutions of the currently selected Pokemon.
// 
// Use temp to save select pokenode and traverse through
// 'evolve' and use print_evolve to print information of 
// every pokemon in evolution process.
void show_evolutions(Pokedex pokedex) {
    pokedex->temp = pokedex->select;
    while (pokedex->temp != NULL) {
        print_evolve(pokedex->temp);
        pokedex->temp = pokedex->temp->evolve;
        if (pokedex->temp != NULL) {
            printf(" --> ");
        }
    }
    printf("\n");
}

// Return the pokemon_id of the Pokemon that the currently selected
// Pokemon evolves into.
// 
// If the currently selected Pokemon does not evolve, this function
// return DOES_NOT_EVOLVE.
// 
// If the Pokedex is empty, this function print an appropriate
// error message and exit the program.
int get_next_evolution(Pokedex pokedex) {
    if (pokedex->select != NULL) {
        if (pokedex->select->evolve == NULL) {
            return DOES_NOT_EVOLVE;
        } else {
            return pokemon_id(pokedex->select->evolve->pokemon);
        }
    } else {
        fprintf(stderr, "Exiting because the pokedex is empty.\n");
        exit(1);
    }   
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

// Create a new Pokedex which contains only the Pokemon of a specified
// type from the original Pokedex.
// 
// If the specified type is NONE_TYPE, INVALID_TYPE, or MAX_TYPE, an 
// appropriate error message has been written in main.c so just return NULL.
// 
// If there are no matching Pokemon, this function return an
// empty Pokedex.
Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    if (type == NONE_TYPE || type == INVALID_TYPE || type == MAX_TYPE) {
        return NULL;
    } else {
        // Use new_pokedex to create a new pokedex.
        Pokedex newdex = new_pokedex();
        // Use curr to traverse original pokedex.
        pokedex->curr = pokedex->head;
        while (pokedex->curr != NULL) {
            // If the type of pokemon in original pokedex has the 
            // same type with provided type and it is also 'found',
            if ((pokemon_first_type(pokedex->curr->pokemon) == type 
                || pokemon_second_type(pokedex->curr->pokemon) == type) 
                && pokedex->curr->found == TRUE) {
                // use add_pokemon to creat a new pokenode which contains
                // a clone of original pokemon and place this pokenode at 
                // the end of the new pokedex.
                add_pokemon(newdex , clone_pokemon(pokedex->curr->pokemon));
            }
            pokedex->curr = pokedex->curr->next;
        }
        // Set select to head of new pokedex.
        newdex->select = newdex->head;
        // Set all pokemon in new pokedex to 'found'.
        find_all(newdex);
        return newdex;
    }
}

// Create a new Pokedex which contains only the Pokemon that have
// previously been 'found' from the original Pokedex.
// 
// If there are no matching Pokemon, this function return an
// empty Pokedex.
Pokedex get_found_pokemon(Pokedex pokedex) {
    // Use new_pokedex to create a new pokedex 
    // which will contains pokemon that has been found.
    Pokedex found = new_pokedex();
    // Use curr to traverse original pokedex.
    pokedex->curr = pokedex->head;
    while (pokedex->curr != NULL) {
        // If the pokemon in original pokedex is found,
        if (pokedex->curr->found == TRUE) {
            // use add_pokemon to creat a new pokenode which contains
            // a clone of original pokemon and place this pokenode at 
            // the end of the 'found' pokedex.
            add_pokemon(found, clone_pokemon(pokedex->curr->pokemon));
        }
        pokedex->curr = pokedex->curr->next;
    }
    // Use a method similar with selection sort to sort the pokenode in 
    // 'found' and add them one by one to anther new pokedex 'found_ordered'.
    // Firstly, use curr of 'found' to traverse 'found' to get
    // a minimum and a maximun of pokemon_id in 'found'.
    found->curr = found->head;
    int max = pokemon_id(found->curr->pokemon);
    int min = pokemon_id(found->curr->pokemon);
    found->curr = found->curr->next;
    while (found->curr != NULL) {
        if (min > pokemon_id(found->curr->pokemon)) {
            min = pokemon_id(found->curr->pokemon);
        }
        if (max < pokemon_id(found->curr->pokemon)) {
            max = pokemon_id(found->curr->pokemon);
        }
        found->curr = found->curr->next;
    }
    // Use new_pokedex to create another new pokedex 
    // which will store the sorted pokenodes in 'found'.
    Pokedex found_ordered = new_pokedex();
    while (min <= max) {
        // use curr of 'found' to traverse 'found' again and again.
        found->curr = found->head;
        while (found->curr != NULL) {
            // If the id of pokemon in 'found' matchs
            // the increasing min in this loop,
            if (pokemon_id(found->curr->pokemon) == min) {
                // use add_pokemon to creat a new pokenode which contains
                // a clone of pokemon in 'found' and place this pokenode at 
                // the end of the 'found_order'.
                add_pokemon(found_ordered, clone_pokemon(found->curr->pokemon));
            }
            found->curr = found->curr->next;
        }
        min++;
    }
    // Set select to head of 'found_ordered'.
    found_ordered->select = found_ordered->head;
    // 'Found' should be destroy as it is created using malloc but
    // destroy_pokedex will only destroy 'found_orderd' after this
    // function ends.
    destroy_pokedex(found);
    // Set all pokemon in new pokedex to 'found'.
    find_all(found_ordered);
    return found_ordered;
}    

// Create a new Pokedex containing only the Pokemon from the original
// pokedex which have the given string appearing in its name.
// 
// If there are no matching Pokemon, this function return an
// empty Pokedex.
Pokedex search_pokemon(Pokedex pokedex, char *text) {
    // Use new_pokedex to create a new pokedex.
    Pokedex newdex = new_pokedex();
    // Use curr to traverse original pokedex.
    pokedex->curr = pokedex->head;
    while (pokedex->curr != NULL) {
        // If the name of pokemon in original pokedex contains provided
        // text and it is also 'found',
        if (pokedex->curr->found == TRUE 
            && contain(text, pokemon_name(pokedex->curr->pokemon)) == TRUE) {
            // use add_pokemon to creat a new pokenode which contains
            // a clone of original pokemon and place this pokenode at 
            // the end of the new pokedex.
            add_pokemon(newdex , clone_pokemon(pokedex->curr->pokemon));
        }
        pokedex->curr = pokedex->curr->next;
    }
    // Set select to head of new pokedex.
    newdex->select = newdex->head;
    // Set all pokemon in new pokedex to 'found'.
    find_all(newdex);
    return newdex;
}


// Add definitions for your own functions below.
// Make them static to limit their scope to this file.


// Create a new pokenode containing a pokemon 
// and next fields, return a pointer to the new node.
// Pokemon points to given pokemon.
// next always points to NULL as this pokenode will be 
// the last one of the pokenode created in add_pokemon.
// 'Found' is initially set to be FALSE.
// 'Evolve' is initially set to NULL.
static struct pokenode *create_node(Pokemon pokemon, struct pokenode *next) {
    struct pokenode *node = malloc(sizeof (struct pokenode));  
    if (node == NULL) {
        fprintf(stderr, "Exiting because out of memory\n");
        exit(1);
    }
    node->pokemon = pokemon;
    node->next = next;
    node->found = FALSE;
    node->evolve = NULL;
    return node;
}

// Return pointer to last pokenode in list.
// NULL is returned if list is empty.
static struct pokenode *last(Pokedex pokedex) {
    pokedex->curr = pokedex->head;
    if (pokedex->curr == NULL) {
        return NULL;
    }
    while (pokedex->curr->next != NULL) {
        pokedex->curr = pokedex->curr->next;
    }
    return pokedex->curr;
}

// Return FALSE if the pokemon has been added and TRUE otherwise.
static int check(Pokedex pokedex, Pokemon pokemon) {
    pokedex->curr = pokedex->head;
    while (pokedex->curr != NULL) {
        if (pokemon_id(pokedex->curr->pokemon) == pokemon_id(pokemon)) {
            return FALSE;
        }
        pokedex->curr = pokedex->curr->next;
    }
    return TRUE;
}

// Print a pokemon's name with asterisks in same length.
static void name_asterisk(char *name) {
    int i = 0;
    while (name[i] != '\0') {
        printf("*");
        i++;
    }
    printf("\n");
}

// Destroy a pokenode using destroy_pokemon.
// Free the pokenode after destroy corresponding pokemon.
static void destroy_node(struct pokenode *node) {
    destroy_pokemon(node->pokemon);
    free(node);
}

// Print a pokemon's information in evolution process.
// Hide name and type if it is not 'found'.
static void print_evolve(struct pokenode *node) {
    pokemon_type first = pokemon_first_type(node->pokemon);
    pokemon_type second = pokemon_second_type(node->pokemon);
    printf("#%03d", pokemon_id(node->pokemon));
    if (node->found == TRUE) {
        printf(" %s ", pokemon_name(node->pokemon));
        if (second == NONE_TYPE) {
            printf("[%s]", pokemon_type_to_string(first));
        } else {
            printf("[%s, %s]", pokemon_type_to_string(first), 
                               pokemon_type_to_string(second));
        }  
    } else {
        printf(" ???? [????]");
    }
}

// Change every pokemon in new pokedex created in stage4 to 'found'.
// 'Found' in new pokenode created by creat_node is defaultly set to be FALSE
// However, all pokemons picked from original pokedex in stage 4 is 'found'.
// If pokedex is empty, this function does nothing.
static void find_all(Pokedex pokedex) {
    if (pokedex != NULL) {
        pokedex->curr = pokedex->head;
        while (pokedex->curr != NULL) {
            pokedex->curr->found = TRUE;
            pokedex->curr = pokedex->curr->next;
        }
    }   
}

// Check if pokemon's name contains provid.
// A TRUE will be returned, FALSE otherwise.
// Lower case text and name use malloc so they should be free before return.
static int contain(char *text, char *name) {
    // Count the length of name and text then convert them to all-lowercase.
    int text_len = 0;
    int name_len = 0;
    while (text[text_len] != '\0') {
        text_len++;
    }
    while (name[name_len] != '\0') {
        name_len++;
    }
    char *lower_text = lowercase(text, text_len);
    char *lower_name = lowercase(name, name_len);
    // Use lowercase name and text to check if name contains the provided text.
    int i = 0;
    int j = 0;
    // A pointer 'select' is used as a ‘Vernier scale‘ to limit the compared part
    // of name. It moves forward if a comparation fails.
    char *select = lower_name;
    int num_match = 0;
    while (i + text_len <= name_len) {
        select = &lower_name[i];
        j = 0;
        num_match = 0;
        while (j < text_len) {
            if (select[j] == lower_text[j]) {
                num_match++;
            }
            j++;
        }
        // If num_match equals the length of text, it means a certain part of name 
        // is tatally the same with the text.
        if (num_match == text_len) {
            free(lower_text);
            free(lower_name);
            return TRUE;
        }
        i++;
    }
    free(lower_text);
    free(lower_name);
    return FALSE;
}

// Convert a string to corresponding lower case string.
static char *lowercase(char *string, int length) {
    char *lower = malloc((length + 1) * sizeof(char));
    int i = 0;
    while (i <= length) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            lower[i] = string[i] + 'a' - 'A';
        } else {
            lower[i] = string[i];
        }
        i++;
    }
    return lower;
}