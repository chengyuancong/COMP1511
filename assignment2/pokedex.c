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
    struct pokenode *head;
    struct pokenode *select;
    struct pokenode *curr;
};


// You don't have to use the provided struct pokenode, you are free to
// make your own struct instead.
// If you use the provided struct pokenode, you will need to add fields
// to it to store other information.

struct pokenode {
    struct pokenode *next;
    struct pokenode *prev;
    Pokemon         pokemon;
    int found;
};

// Add any other structs you define here.


// Add prototypes for any extra functions you create here.
static struct pokenode *createNode(Pokemon pokemon, struct pokenode *next);
static struct pokenode *last(struct pokenode *head);
static int check(struct pokenode *head,Pokemon pokemon);
static void name_asterisk(char *name);
static void id_digit(int id);


// You need to implement the following 20 functions.
// In other words, replace the lines calling fprintf & exit with your code.
// You can find descriptions of what each function should do in pokedex.h


Pokedex new_pokedex(void) {
    Pokedex new_pokedex = malloc(sizeof (struct pokedex));
    assert(new_pokedex != NULL);
    // add your own code here
    new_pokedex->head = NULL;
    return new_pokedex;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

void add_pokemon(Pokedex pokedex, Pokemon pokemon) {
    if (check(pokedex->head ,pokemon) == 1) {
        struct pokenode *new = createNode(pokemon, NULL);
        if (pokedex->head == NULL) {
            pokedex->head = new; 
        } else {
            last(pokedex->head)->next = new;
        }
    } else {
        printf("Error!This pokemon has been added.\n");
        exit(EXIT_FAILURE);
    }
}

void detail_pokemon(Pokedex pokedex) {
    if (pokedex->head != NULL) {
        pokemon_type first = pokemon_first_type(pokedex->head->pokemon);
        pokemon_type second = pokemon_second_type(pokedex->head->pokemon);
        printf("Id: ");
        id_digit(pokemon_id(pokedex->head->pokemon));
        printf("\n");
        if (pokedex->head->found == 1) {
            printf("Name: %s\n", pokemon_name(pokedex->head->pokemon));
            printf("Height: %.1lfm\n", pokemon_height(pokedex->head->pokemon));
            printf("Weight: %.1lfkg\n", pokemon_weight(pokedex->head->pokemon));
            if (second == NONE_TYPE) {
                printf("Type: %s\n", pokemon_type_to_string(first));
            } else {
                printf("Type: %s %s\n", pokemon_type_to_string(first), pokemon_type_to_string(second));
            }  
        } else {
            printf("Name: ");
            name_asterisk(pokemon_name(pokedex->head->pokemon));
            printf("Height: --\n");
            printf("Weight: --\n");
            printf("Type: --\n");
        }
    }   
}

Pokemon get_current_pokemon(Pokedex pokedex) {
    if (pokedex->head == NULL) {
        printf("No Pokedex\n");
        exit(EXIT_FAILURE);
    } else {
        return pokedex->head->pokemon;
    }
}


void find_current_pokemon(Pokedex pokedex) {
    if (pokedex->head != NULL) {
        pokedex->head->found = 1;
    }
}

void print_pokemon(Pokedex pokedex) {
    pokedex->curr = pokedex->head;
    if (pokedex->curr != NULL) {
        printf("--> #");
        id_digit(pokemon_id(pokedex->curr->pokemon));
        printf(": ");
        if (pokedex->curr->found == 1) {
            printf("%s\n", pokemon_name(pokedex->curr->pokemon));
        } else {
            name_asterisk(pokemon_name(pokedex->curr->pokemon));
        }
        pokedex->curr = pokedex->curr->next;
        while (pokedex->curr != NULL) {
            printf("    #");
            id_digit(pokemon_id(pokedex->curr->pokemon));
            printf(": ");
            if (pokedex->curr->found == 1) {
                printf("%s\n", pokemon_name(pokedex->curr->pokemon));
            } else {
                name_asterisk(pokemon_name(pokedex->curr->pokemon));
            }
            pokedex->curr = pokedex->curr->next;
        }    
    }
}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

void next_pokemon(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the next_pokemon function in pokedex.c\n");
    exit(1);
}

void prev_pokemon(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the prev_pokemon function in pokedex.c\n");
    exit(1);
}

void change_current_pokemon(Pokedex pokedex, int id) {
    fprintf(stderr, "exiting because you have not implemented the change_current_pokemon function in pokedex.c\n");
    exit(1);
}

void remove_pokemon(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the remove_pokemon function in pokedex.c\n");
    exit(1);
}

void destroy_pokedex(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the destroy_pokedex function in pokedex.c\n");
    exit(1);
}


int count_found_pokemon(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the count_found_pokemon function in pokedex.c\n");
    exit(1);
}

int count_total_pokemon(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the count_total_pokemon function in pokedex.c\n");
    exit(1);
}


////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

void add_pokemon_evolution(Pokedex pokedex, int from_id, int to_id) {
    fprintf(stderr, "exiting because you have not implemented the add_pokemon_evolution function in pokedex.c\n");
    exit(1);
}

void show_evolutions(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the show_evolutions function in pokedex.c\n");
    exit(1);
}

int get_next_evolution(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the get_next_evolution function in pokedex.c\n");
    exit(1);
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    fprintf(stderr, "exiting because you have not implemented the get_pokemon_of_type function in pokedex.c\n");
    exit(1);
}

Pokedex get_found_pokemon(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the get_found_pokemon function in pokedex.c\n");
    exit(1);
}

Pokedex search_pokemon(Pokedex pokedex, char *text) {
    fprintf(stderr, "exiting because you have not implemented the search_pokemon function in pokedex.c\n");
    exit(1);
}

// Add definitions for your own functions below.
// Make them static to limit their scope to this file.


// Create a new pokenode containing a pokemon struct,
// and next fields, return a pointer to the new  node.

static struct pokenode *createNode(Pokemon pokemon, struct pokenode *next) {
    struct pokenode *n = malloc(sizeof (struct pokenode));  
    if (n == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(EXIT_FAILURE);
    }
    n->pokemon = pokemon;
    n->next = next;
    n->found = 0;
    return n;
}

// return pointer to last pokenode in list
// NULL is returned if list is empty
static struct pokenode *last(struct pokenode *head) {
    struct pokenode * curr = head;
    if(curr == NULL) {
        return NULL;
    }
    while (curr->next != NULL){
        curr = curr->next;
    }
    return curr;
}

// return 0 if the pokemon has been added and 1 otherwise
static int check(struct pokenode *head,Pokemon pokemon) {
    struct pokenode * curr = head;
    while(curr != NULL) {
        if (pokemon_id(curr->pokemon) == pokemon_id(pokemon)) {
            return 0;
        }
        curr = curr->next;
    }
    return 1;
}


// replace name with asterisks
static void name_asterisk(char *name) {
    int i = 0;
    while (name[i] != '\0') {
        printf("*");
        i++;
    }
    printf("\n");
}

// add 0 to id less than three digits
static void id_digit(int id) {
    if (id >= 0 && id <= 9) {
        printf("00");
        printf("%d", id);
    } else if (id >= 10 && id <= 99) {
        printf("0");
        printf("%d", id);
    } else {
        printf("%d", id);
    }
}