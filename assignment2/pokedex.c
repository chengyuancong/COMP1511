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
    struct pokenode *temp;
};


// You don't have to use the provided struct pokenode, you are free to
// make your own struct instead.
// If you use the provided struct pokenode, you will need to add fields
// to it to store other information.

struct pokenode {
    struct pokenode *next;
    struct pokenode *evolve;
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
static void destroy_node(struct pokenode *np);
static void print_evolve(struct pokenode *np);
static int contain(char *text, char *name);
static void find_all(Pokedex pokedex);


// You need to implement the following 20 functions.
// In other words, replace the lines calling fprintf & exit with your code.
// You can find descriptions of what each function should do in pokedex.h


Pokedex new_pokedex(void) {
    Pokedex new_pokedex = malloc(sizeof (struct pokedex));
    assert(new_pokedex != NULL);
    // add your own code here
    new_pokedex->head = NULL;
    new_pokedex->select = NULL;
    new_pokedex->curr = NULL;
    new_pokedex->temp = NULL;
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
            pokedex->select = pokedex->head; 
            pokedex->curr = pokedex->head;
        } else {
            last(pokedex->head)->next = new;
        }
    } else {
        printf("Error!This pokemon has been added.\n");
        exit(EXIT_FAILURE);
    }
}

void detail_pokemon(Pokedex pokedex) {
    if (pokedex->select != NULL) {
        pokemon_type first = pokemon_first_type(pokedex->select->pokemon);
        pokemon_type second = pokemon_second_type(pokedex->select->pokemon);
        printf("Id: ");
        id_digit(pokemon_id(pokedex->select->pokemon));
        printf("\n");
        if (pokedex->select->found == 1) {
            printf("Name: %s\n", pokemon_name(pokedex->select->pokemon));
            printf("Height: %.1lfm\n", pokemon_height(pokedex->select->pokemon));
            printf("Weight: %.1lfkg\n", pokemon_weight(pokedex->select->pokemon));
            if (second == NONE_TYPE) {
                printf("Type: %s\n", pokemon_type_to_string(first));
            } else {
                printf("Type: %s %s\n", pokemon_type_to_string(first), pokemon_type_to_string(second));
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

Pokemon get_current_pokemon(Pokedex pokedex) {
    if (pokedex->select == NULL) {
        printf("No Pokedex\n");
        exit(EXIT_FAILURE);
    } else {
        return pokedex->select->pokemon;
    }
}


void find_current_pokemon(Pokedex pokedex) {
    if (pokedex->select != NULL) {
        pokedex->select->found = 1;
    }
}

void print_pokemon(Pokedex pokedex) {
    pokedex->curr = pokedex->head;
    while (pokedex->curr != NULL) {
        if (pokedex->curr == pokedex->select) {
            printf("--> #");
        } else {
            printf("    #");
        }
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


////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

void next_pokemon(Pokedex pokedex) {
    if (pokedex->select != NULL) {
        if (pokedex->select->next != NULL) {
            pokedex->select = pokedex->select->next;
        }
    }
}

void prev_pokemon(Pokedex pokedex) {
    pokedex->curr = pokedex->head;
    if (pokedex->select != NULL && pokedex->select != pokedex->head) {
        while (pokedex->curr->next != pokedex->select) {
            pokedex->curr = pokedex->curr->next;
        }
        pokedex->select = pokedex->curr;
    }
}

void change_current_pokemon(Pokedex pokedex, int id) {
    pokedex->curr = pokedex->head;
    while (pokedex->curr != NULL && pokemon_id(pokedex->curr->pokemon) != id) {
        pokedex->curr = pokedex->curr->next;
    }
    pokedex->select = pokedex->curr;
}


void remove_pokemon(Pokedex pokedex) {
    int length = count_total_pokemon(pokedex);
    if (pokedex->select != NULL) {
        if (length == 1) {
            destroy_node(pokedex->select);
            pokedex->select = NULL;
            pokedex->curr = NULL;
            pokedex->head = NULL;
        } else {
            if (pokedex->select == pokedex->head) {
                pokedex->temp = pokedex->select;
                next_pokemon(pokedex);
                destroy_node(pokedex->temp);
                pokedex->head = pokedex->select;
            } else if (pokedex->select->next == NULL) {
                pokedex->temp = pokedex->select;
                prev_pokemon(pokedex);
                destroy_node(pokedex->temp);
                pokedex->select->next = NULL;
            } else {
                pokedex->temp = pokedex->select;
                prev_pokemon(pokedex);
                pokedex->select->next = pokedex->select->next->next;
                destroy_node(pokedex->temp);
                next_pokemon(pokedex);
            }
        } 
    }   
}

void destroy_pokedex(Pokedex pokedex) {
    while (pokedex->head != NULL) {
        pokedex->temp = pokedex->head;
        pokedex->head = pokedex->head->next;
        destroy_node(pokedex->temp);
    }
    free(pokedex);
}


int count_found_pokemon(Pokedex pokedex) {
    int counter = 0;
    pokedex->curr = pokedex->head;
    while (pokedex->curr != NULL) {
        if (pokedex->curr->found == 1) {
            counter++;
        }
        pokedex->curr = pokedex->curr->next;
    }
    pokedex->curr = pokedex->head;
    return counter;
}

int count_total_pokemon(Pokedex pokedex) {
    int counter = 0;
    pokedex->curr = pokedex->head;
    while (pokedex->curr != NULL) {
        counter++;
        pokedex->curr = pokedex->curr->next;
    }
    pokedex->curr = pokedex->head;
    return counter;
}


////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

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
        printf("ID error occurs!\n");
        exit(EXIT_FAILURE);
    } else {
        pokedex->curr->evolve = pokedex->temp;
    }
}

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

int get_next_evolution(Pokedex pokedex) {
    if (pokedex->select->evolve == NULL) {
        return DOES_NOT_EVOLVE;
    } else {
        return pokemon_id(pokedex->select->evolve->pokemon);
    }
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    if (type == NONE_TYPE || type == INVALID_TYPE || type == MAX_TYPE) {
        fprintf(stderr, "exiting because wrong pokemon type\n");
        exit(EXIT_FAILURE);
    } else {
        Pokedex newdex = new_pokedex();
        pokedex->curr = pokedex->head;
        while (pokedex->curr != NULL) {
            if (pokemon_first_type(pokedex->curr->pokemon) == type 
                || pokemon_second_type(pokedex->curr->pokemon) == type
                || pokedex->curr->found == 1) {
                add_pokemon(newdex , clone_pokemon(pokedex->curr->pokemon));
            }
            pokedex->curr = pokedex->curr->next;
        }
        pokedex->select = pokedex->head;
        find_all(newdex);
        return newdex;
    }
}

Pokedex get_found_pokemon(Pokedex pokedex) {
    Pokedex found = new_pokedex();
    pokedex->curr = pokedex->head;
    while (pokedex->curr != NULL) {
        if (pokedex->curr->found == 1) {
            add_pokemon(found, clone_pokemon(pokedex->curr->pokemon));
        }
        pokedex->curr = pokedex->curr->next;
    }
    found->curr = found->head;
    int max = pokemon_id(found->curr->pokemon);
    int min = pokemon_id(found->curr->pokemon);
    found->curr = found->curr->next;
    while(found->curr != NULL) {
        if (min > pokemon_id(found->curr->pokemon)) {
            min = pokemon_id(found->curr->pokemon);
        }
        if (max < pokemon_id(found->curr->pokemon)) {
            max = pokemon_id(found->curr->pokemon);
        }
        found->curr = found->curr->next;
    }
    Pokedex found_ordered = new_pokedex();
    while (min <= max) {
        found->curr = found->head;
        while (found->curr != NULL) {
            if (pokemon_id(found->curr->pokemon) == min) {
                add_pokemon(found_ordered, clone_pokemon(found->curr->pokemon));
            }
             found->curr = found->curr->next;
        }
        min = min + 1;
    }
    found_ordered->select = found_ordered->head;
    find_all(found_ordered);
    return found_ordered;
}    


Pokedex search_pokemon(Pokedex pokedex, char *text) {
    Pokedex newdex = new_pokedex();
    pokedex->curr = pokedex->head;
    while (pokedex->curr != NULL) {
        if (pokedex->curr->found == 1 && contain(text, pokemon_name(pokedex->curr->pokemon)) == 1) {
            add_pokemon(newdex , clone_pokemon(pokedex->curr->pokemon));
        }
        pokedex->curr = pokedex->curr->next;
    }
    pokedex->select = pokedex->head;
    find_all(newdex);
    return newdex;
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
    n->evolve = NULL;
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

// free name of pokemon, then pokemon, then a pokenode
static void destroy_node(struct pokenode *np) {
    destroy_pokemon(np->pokemon);
    free(np);
}

// print a evolution node
static void print_evolve(struct pokenode *np) {
    pokemon_type first = pokemon_first_type(np->pokemon);
    pokemon_type second = pokemon_second_type(np->pokemon);
    printf("#");
    id_digit(pokemon_id(np->pokemon));
    if (np->found == 1) {
        printf(" %s ", pokemon_name(np->pokemon));
        if (second == NONE_TYPE) {
            printf("[%s]", pokemon_type_to_string(first));
        } else {
            printf("[%s, %s]", pokemon_type_to_string(first), pokemon_type_to_string(second));
        }  
    } else {
        printf(" ???? [????]");
    }
}

// change every pokemon in new pokedex to 'found'
static void find_all(Pokedex pokedex) {
    if (pokedex != NULL) {
        pokedex->curr = pokedex->head;
        while (pokedex->curr != NULL) {
            pokedex->curr->found = 1;
            pokedex->curr = pokedex->curr->next;
        }
    }   
}


// check if pokemon's name contains provided text
static int contain(char *text, char *name) {
    int i = 0;
    int j = 0;
    
    while (text[i] != '\0') {
        i++;
    }
    int length = i;
    i = 0;
    j = 0;
    while (name[j] != '\0') {
        while ((text[i] == name[j] 
                || text[i] + ('a' - 'A') == name[j] 
                || text[i] == name[j] + ('a' - 'A'))
                && text[i] != '\0') {
            i++;
        }
        j++;
    }
    if (length == i) {
        return 1;
    } else {
        return 0;
    }
}