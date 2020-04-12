// Assignment 2 19T1 COMP1511: Pokedex
// test_pokedex.c
//
// This file allows you to automatically test the functions you
// implement in pokedex.c.
//
// This program was written by Yuancong Cheng (z5285978)
// on 9 Apr 2020
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: Added pointer check for the provided tests.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "pokedex.h"


// Sample data on Bulbasaur, the Pokemon with pokemon_id 1.
#define BULBASAUR_ID 1
#define BULBASAUR_NAME "Bulbasaur"
#define BULBASAUR_HEIGHT 0.7
#define BULBASAUR_WEIGHT 6.9
#define BULBASAUR_FIRST_TYPE GRASS_TYPE
#define BULBASAUR_SECOND_TYPE POISON_TYPE

// Sample data on Ivysaur, the Pokemon with pokemon_id 2.
#define IVYSAUR_ID 2
#define IVYSAUR_NAME "Ivysaur"
#define IVYSAUR_HEIGHT 1.0
#define IVYSAUR_WEIGHT 13.0
#define IVYSAUR_FIRST_TYPE GRASS_TYPE
#define IVYSAUR_SECOND_TYPE POISON_TYPE

// Sample data on Venusaur, the Pokemon with pokemon_id 3
#define VENUSAUR_ID 3
#define VENUSAUR_NAME "Venusaur"
#define VENUSAUR_HEIGHT 2.0
#define VENUSAUR_WEIGHT 100.0
#define VENUSAUR_FIRST_TYPE POISON_TYPE
#define VENUSAUR_SECOND_TYPE GRASS_TYPE

// Sample data on Charmander, the Pokemon with pokemon_id 4.
#define CHARMANDER_ID 4
#define CHARMANDER_NAME "Charmander"
#define CHARMANDER_HEIGHT 0.6
#define CHARMANDER_WEIGHT 8.5
#define CHARMANDER_FIRST_TYPE FIRE_TYPE
#define CHARMANDER_SECOND_TYPE NONE_TYPE

// Sample data on Charmeleon, the Pokemon with pokemon_id 5.
#define CHARMELEON_ID 5
#define CHARMELEON_NAME "Charmeleon"
#define CHARMELEON_HEIGHT 1.1
#define CHARMELEON_WEIGHT 19.0
#define CHARMELEON_FIRST_TYPE FIRE_TYPE
#define CHARMELEON_SECOND_TYPE NONE_TYPE

// Sample data on Charizard, the Pokemon with pokemon_id 6.
#define CHARIZARD_ID 6
#define CHARIZARD_NAME "Charizard"
#define CHARIZARD_HEIGHT 1.7
#define CHARIZARD_WEIGHT 90.5
#define CHARIZARD_FIRST_TYPE FLYING_TYPE
#define CHARIZARD_SECOND_TYPE FIRE_TYPE



// Tests for Pokedex functions from pokedex.c.
static void test_new_pokedex(void);
static void test_add_pokemon(void);
static void test_get_current_pokemon(void);
static void test_find_current_pokemon(void);
static void test_next_pokemon(void);
static void test_prev_pokemon(void);
static void test_change_current_pokemon(void);
static void test_remove_pokemon(void);
static void test_count_found_pokemon(void);
static void test_count_total_pokemon(void);
static void test_add_pokemon_evolution(void);
static void test_get_next_evolution(void); 
static void test_get_found_pokemon(void);
static void test_search_pokemon(void);


// Helper functions for creating/comparing Pokemon.
static Pokemon create_bulbasaur(void);
static Pokemon create_ivysaur(void);
static Pokemon create_venusaur(void);
static Pokemon create_charmander(void);
static Pokemon create_charmeleon(void);
static Pokemon create_charizard(void);
static int is_same_pokemon(Pokemon first, Pokemon second);
static int is_copied_pokemon(Pokemon first, Pokemon second);



int main(int argc, char *argv[]) {
    printf("Welcome to the COMP1511 Pokedex Tests!\n");

    printf("\n==================== Pokedex Tests ====================\n");

    test_new_pokedex();
    test_add_pokemon();
    test_get_current_pokemon();
    test_find_current_pokemon();
    test_next_pokemon();
    test_prev_pokemon();
    test_change_current_pokemon();
    test_remove_pokemon();
    test_count_found_pokemon();
    test_count_total_pokemon();
    test_add_pokemon_evolution();
    test_get_next_evolution(); 
    test_get_found_pokemon();
    test_search_pokemon();

    printf("\nAll Pokedex tests passed, you are Awesome!\n");
}


////////////////////////////////////////////////////////////////////////
//                     Pokedex Test Functions                         //
////////////////////////////////////////////////////////////////////////

// `test_new_pokedex` checks whether the new_pokedex and destroy_pokedex
// functions work correctly, to the extent that it can.
//
// It does this by creating a new Pokedex, checking that it's not NULL,
// then calling destroy_pokedex.
//
// Note that it isn't possible to check whether destroy_pokedex has
// successfully destroyed/freed the Pokedex, so the best we can do is to
// call the function and make sure that it doesn't crash..
static void test_new_pokedex(void) {
    printf("\n>> Testing new_pokedex\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("       --> Checking that the returned Pokedex is not NULL\n");
    assert(pokedex != NULL);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed new_pokedex tests!\n");
}

// `test_add_pokemon` checks whether the add_pokemon function works
// correctly.
//
// It does this by creating the Pokemon Bulbasaur (using the helper
// functions in this file and the provided code in pokemon.c), and
// calling add_pokemon to add it to the Pokedex.
//
// Some of the ways that you could extend these test would include:
//   - adding additional Pokemon other than just Bulbasaur,
//   - checking whether the currently selected Pokemon is correctly set,
//   - checking that functions such as `count_total_pokemon` return the
//     correct result after more Pokemon are added,
//   - ... and more!
static void test_add_pokemon(void) {
    printf("\n>> Testing add_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur\n");
    Pokemon bulbasaur = create_bulbasaur();

    printf("    ... Adding Bulbasaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);

    printf("       --> Checking that Bulbasaur was correctly added\n");
    assert(count_total_pokemon(pokedex) == 1);
    
    printf("    ... Creating Ivysaur\n");
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, ivysaur);
    
    printf("       --> Checking that Ivysaur was correctly added\n");
    assert(count_total_pokemon(pokedex) == 2);

    printf("    ... Creating Venusaur\n");
    Pokemon Venusaur = create_venusaur();

    printf("    ... Adding Venusaur to the Pokedex\n");
    add_pokemon(pokedex, Venusaur);
    
    printf("       --> Checking that Venusaur was correctly added\n");
    assert(count_total_pokemon(pokedex) == 3);

    printf("       --> Checking that the current selected Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("       --> Checking that the pokedex is empty after add command\n");
    assert(count_total_pokemon(pokedex) != 0);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed add_pokemon tests!\n");
}

// `test_get_current_pokemon` checks whether the get_current_pokemon
// function works correctly.
// 
// It checks that if the pokedex is empty, this function returns NULL.
// It checks that the function correctly returns the currently selected pokemon.
static void test_get_current_pokemon(void) {
    printf("\n>> Testing get_current_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    --> Checking that if the pokedex is empty, this function returns NULL\n");
    assert(get_current_pokemon(pokedex) == NULL);

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf("       --> Checking that pokemons were correctly added\n");
    assert(count_total_pokemon(pokedex) == 2);
    
    printf("       --> Checking that the get_current_pokemon returns Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the get_current_pokemon returns Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed get_current_pokemon tests!\n");
}

// `test_find_current_pokemon` checks whether the find_current_pokemon
// function works correctly.
// 
// It checks that if the pokedex is empty, this function does nothing.
// It checks that the function is successfully setting the pokemons to be found.
static void test_find_current_pokemon(void) {
    printf("\n>> Testing find_current_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Setting selected pokemon to be found\n");
    find_current_pokemon(pokedex);
    
    printf("       --> Checking that if the pokedex is empty, this function does nothing\n");
    assert(count_found_pokemon(pokedex) == 0);
  

    printf("    ... Creating Bulbasaur, Ivysaur and Venusaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();

    printf("    ... Adding Bulbasaur, Ivysaur and Venusaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);
    
    printf("       --> Checking that pokemons were correctly added\n");
    assert(count_total_pokemon(pokedex) == 3);
    
    printf("       --> Checking that the current selected Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("    ... Setting Bulbasaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("       --> Checking that Bulbasaur is found\n");
    assert(count_found_pokemon(pokedex) == 1);
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Venusaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), venusaur));
    
    printf("    ... Setting Venusaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("       --> Checking that Venusaur is found\n");
    assert(count_found_pokemon(pokedex) == 2);
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed find_current_pokemon tests!\n");
}

// `test_next_pokemon` checks whether the next_pokemon function works
// correctly.
//
// It does this by creating two Pokemon: Bulbasaur and Ivysaur (using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, then checks that calling the
// next_pokemon function changes the currently selected Pokemon from
// Bulbasaur to Ivysaur.
//
// Some of the ways that you could extend these tests would include:
//   - adding even more Pokemon to the Pokedex,
//   - calling the next_pokemon function when there is no "next" Pokemon,
//   - calling the next_pokemon function when there are no Pokemon in
//     the Pokedex,
//   - ... and more!
static void test_next_pokemon(void) {
    printf("\n>> Testing next_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that if the pokedex is empty, this function does nothing\n");
    assert(count_total_pokemon(pokedex) == 0);

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the select pokemon is unchanged when there is no next pokemon\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed next_pokemon tests!\n");
}

// `test_prev_pokemon` checks whether the prev_pokemon function works
// correctly.
//
// It checks that if the pokedex is empty, this function does nothing.
// It checks that the selected pokemon is correctly changed to the previous one.
// It checks that the current pokemon is unchanged if there is no previous pokemon.
static void test_prev_pokemon(void) {
    printf("\n>> Testing prev_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);

    printf("       --> Checking that if the pokedex is empty, this function does nothing\n");
    assert(count_total_pokemon(pokedex) == 0);

    printf("    ... Creating Bulbasaur, Ivysaur and Venusaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();
    
    printf("    ... Adding Bulbasaur, Ivysaur and Venusaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Venusaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), venusaur));

    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));

    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);
    
    printf("       --> Checking that the select pokemon is unchanged when there is no previous pokemon\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed prev_pokemon tests!\n");
}

// `test_change_current_pokemon` checks whether the change_current_pokemon 
// function works correctly.
//
// It checks that the selected pokemon is correctly changed to the pokemon with provided ID.
// It checks that this function does nothing if there is no pokemon with that ID.
static void test_change_current_pokemon(void) {
    printf("\n>> Testing change_current_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur, Ivysaur and Venusaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();

    printf("    ... Adding Bulbasaur, Ivysaur and Venusaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);
    
    printf("       --> Checking that pokemons were correctly added\n");
    assert(count_total_pokemon(pokedex) == 3);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Moving to the pokemon with ID 2\n");
    change_current_pokemon(pokedex, 2);
    
    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed change_current_pokemon tests!\n");
}

// `test_remove_pokemon` checks whether the remove_pokemon 
// function works correctly.
//
// It checks that selected pokemon becomes previous one if we remove last one of pokemon.
// It checks that selected pokemon becomes next one if we remove pokemon that is not last one.
// It checks that an empty pokedex is returned if we remove the only pokemon in the pokedex.
// It checks that the function does nothing if the pokedex is empty.
// It checks that the total number of pokemons are correct after remove.
static void test_remove_pokemon(void) {
    printf("\n>> Testing remove_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur, Ivysaur and Venusaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();

    printf("    ... Adding Bulbasaur, Ivysaur and Venusaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);

    printf("       --> Checking that pokemons were correctly added\n");
    assert(count_total_pokemon(pokedex) == 3);
    
    printf("       --> Checking that the current selected Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Venusaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), venusaur));
    
    printf("    ... Removing Venusaur\n");
    remove_pokemon(pokedex);

    printf("       --> Checking that total pokemons is correct\n");
    assert(count_total_pokemon(pokedex) == 2);
    
    printf("       --> Checking that the current selected Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);

    printf("       --> Checking that the current selected Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Removing Bulbasaur\n");
    remove_pokemon(pokedex);
    
    printf("       --> Checking that total pokemons is correct\n");
    assert(count_total_pokemon(pokedex) == 1);

    printf("       --> Checking that the current selected Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Removing Ivysaur\n");
    remove_pokemon(pokedex);
    
    printf("       --> Checking that the pokedex is empty after removing the only pokemon\n");
    assert(count_total_pokemon(pokedex) == 0);

    printf("    ... Removing selected pokemon\n");
    remove_pokemon(pokedex);
    
    printf("       --> Checking that if the pokedex is empty, this function does nothing\n");
    assert(count_total_pokemon(pokedex) == 0);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed remove_pokemon tests!\n");
}

// `test_count_found_pokemon` checks whether the count_found_pokemon
// function works correctly.
//
// It checks that a correct number is returned for found pokemon after adding.
// It checks that a correct number is returned for found pokemon if a found pokemon is removed.
static void test_count_found_pokemon(void) {
    printf("\n>> Testing count_found_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("       --> Checking total found pokemons in a empty pokedex\n");
    assert(count_found_pokemon(pokedex) == 0);

    printf("    ... Creating Bulbasaur, Ivysaur and Venusaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();

    printf("    ... Adding Bulbasaur, Ivysaur and Venusaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);
    
    printf("    ... Setting Bulbasaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("       --> Checking that total found pokemons is correct\n");
    assert(count_found_pokemon(pokedex) == 1);
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
    
    printf("    ... Setting Venusaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("       --> Checking that total found pokemons is correct\n");
    assert(count_found_pokemon(pokedex) == 2);
    
    printf("    ... Removing Venusaur from the pokedex\n");
    remove_pokemon(pokedex);
    
    printf("       --> Checking that total found pokemons is correct\n");
    assert(count_found_pokemon(pokedex) == 1);
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed count_found_pokemon tests!\n");
}

// `test_count_total_pokemon` checks whether the count_total_pokemon
// function works correctly.
//
// It checks that a correct number is returned for all pokemon.
// It checks that a correct number is returned for all pokemon after adding or removing.
static void test_count_total_pokemon(void) {
    printf("\n>> Testing count_total_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("       --> Checking total pokemons in a empty pokedex\n");
    assert(count_total_pokemon(pokedex) == 0);

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf("       --> Checking that total pokemons is correct\n");
    assert(count_total_pokemon(pokedex) == 2);
    
    printf("    ... Removing Bulbasaur from the pokedex\n");
    remove_pokemon(pokedex);
    
    printf("       --> Checking that total pokemons is correct\n");
    assert(count_total_pokemon(pokedex) == 1);
    
    printf("    ... Creating Venusaur\n");
    Pokemon venusaur = create_venusaur();

    printf("    ... Adding Venusaur\n");
    add_pokemon(pokedex, venusaur);
    
    printf("       --> Checking that total pokemons is correct\n");
    assert(count_total_pokemon(pokedex) == 2);
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed count_total_pokemon tests!\n");
}

// `test_add_pokemon_evolution` checks whether the add_pokemon_evolution
// function works correctly.
//
// It checks that the evolutions are correctly set.
// It checks that more than evolutions can be overwritten.
static void test_add_pokemon_evolution(void) {
    printf("\n>> Testing add_pokemon_evolution\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Charmander, Charmeleon and Charizard\n");
    Pokemon charmander = create_charmander();
    Pokemon charmeleon = create_charmeleon();
    Pokemon charizard = create_charizard();

    printf("    ... Adding Charmander, Charmeleon and Charizard to the Pokedex\n");
    add_pokemon(pokedex, charmander);
    add_pokemon(pokedex, charmeleon);
    add_pokemon(pokedex, charizard);
    
    printf("       --> Checking that the current selected Pokemon is Charmander\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), charmander));

    printf("    ... Evolving Charmander to Charmeleon\n");
    add_pokemon_evolution(pokedex, CHARMANDER_ID, CHARMELEON_ID);
    
    printf("       --> Checking the evolution of Charmander is correctly set\n");
    assert(get_next_evolution(pokedex) == CHARMELEON_ID);
    
    printf("    ... Evolving Charmander to charizard\n");
    add_pokemon_evolution(pokedex, CHARMANDER_ID, CHARIZARD_ID);
    
    printf("       --> Checking the evolution of Charmander is overwritten\n");
    assert(get_next_evolution(pokedex) == CHARIZARD_ID);
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed add_pokemon_evolution tests!\n");
}

// `test_get_next_evolution` checks whether the get_next_evolution
// function works correctly.
//
// It checks that a evolution of pokemon can evolve again.
// It checks that if a pokemon has no evolution, this function returns DOES_NOT_EVOLVE.
static void test_get_next_evolution(void) {
    printf("\n>> Testing get_next_evolution\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Charmander, Charmeleon and Charizard\n");
    Pokemon charmander = create_charmander();
    Pokemon charmeleon = create_charmeleon();
    Pokemon charizard = create_charizard();

    printf("    ... Adding Charmander, Charmeleon and Charizard to the Pokedex\n");
    add_pokemon(pokedex, charmander);
    add_pokemon(pokedex, charmeleon);
    add_pokemon(pokedex, charizard);
    
    printf("       --> Checking that the current selected Pokemon is Charmander\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), charmander));

    printf("    ... Evolving Charmander to Charmeleon\n");
    add_pokemon_evolution(pokedex, CHARMANDER_ID, CHARMELEON_ID);
    
    printf("       --> Checking the evolution of Charmander is correctly set\n");
    assert(get_next_evolution(pokedex) == CHARMELEON_ID);

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current selected Pokemon is Charmeleon\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), charmeleon));
    
    printf("    ... Evolving Charmeleon to Charizard\n");
    add_pokemon_evolution(pokedex, CHARMELEON_ID, CHARIZARD_ID);
    
    printf("       --> Checking the evolution of Charmeleon evolves to Charizard\n");
    assert(get_next_evolution(pokedex) == CHARIZARD_ID);

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current selected Pokemon is Charizard\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), charizard));
    
    printf("       --> Checking that Charizard does not evolve\n");
    assert(get_next_evolution(pokedex) == DOES_NOT_EVOLVE);
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed get_next_evolution tests!\n");
}


// `test_get_found_pokemon` checks whether the get_found_pokemon
// function works correctly.
//
// It does this by creating two Pokemon: Bulbasaur and Ivysaur (using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, sets Bulbasaur to be found, and
// then calls the get_found_pokemon function to get all of the Pokemon
// which have been found (which should be just the one, Bulbasaur).
//
// Some of the ways that you could extend these tests would include:
//   - calling the get_found_pokemon function on an empty Pokedex,
//   - calling the get_found_pokemon function on a Pokedex where none of
//     the Pokemon have been found,
//   - checking that the Pokemon in the new Pokedex are in ascending
//     order of pokemon_id (regardless of the order that they appeared
//     in the original Pokedex),
//   - checking that the currently selected Pokemon in the returned
//     Pokedex has been set correctly,
//   - checking that the original Pokedex has not been modified,
//   - ... and more!
static void test_get_found_pokemon(void) {
    printf("\n>> Testing get_found_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Getting all found Pokemon with a empty pokedex\n");
    Pokedex found_pokedex = get_found_pokemon(pokedex);
    
    printf("       --> Checking if the found pokedex is empty\n");
    assert(count_total_pokemon(found_pokedex) == 0);
    
    printf("    ... Returning to the original pokedex\n");
    destroy_pokedex(found_pokedex);
    
    printf("    ... Creating Venusaur, Bulbasaur and Ivysaur\n");
    Pokemon venusaur = create_venusaur();
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Venusaur, Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf("       --> Checking that none of the pokemons are found\n");
    assert(count_found_pokemon(pokedex) == 0);
    
    printf("    ... Getting all found Pokemon with a pokedex that no pokemons are found\n");
    found_pokedex = get_found_pokemon(pokedex);
    
    printf("       --> Checking if the found pokedex is empty\n");
    assert(count_total_pokemon(found_pokedex) == 0);
    assert(count_found_pokemon(found_pokedex) == 0);
    
    printf("    ... Returning to the original pokedex\n");
    destroy_pokedex(found_pokedex);
    
    printf("       --> Checking that the current Pokemon is Venusaur\n");
    assert(get_current_pokemon(pokedex) == venusaur);
    
    printf("    ... Setting Venusaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Getting all found Pokemon\n");
    found_pokedex = get_found_pokemon(pokedex);
    
    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(found_pokedex) == 1);
    assert(count_found_pokemon(found_pokedex) == 1);
    assert(is_copied_pokemon(get_current_pokemon(found_pokedex), venusaur));
    
    printf("    ... Returning to the original pokedex\n");
    destroy_pokedex(found_pokedex);
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Setting Ivysaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Getting all found Pokemon\n");
    found_pokedex = get_found_pokemon(pokedex);

    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(found_pokedex) == 2);
    assert(count_found_pokemon(found_pokedex) == 2);
    assert(is_copied_pokemon(get_current_pokemon(found_pokedex), ivysaur));
    
    printf("    ... Returning to the original pokedex\n");
    destroy_pokedex(found_pokedex);
    
    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);

    printf("    ... Setting Bulbasaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Getting all found Pokemon\n");
    found_pokedex = get_found_pokemon(pokedex);
    
    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(found_pokedex) == 3);
    assert(count_found_pokemon(found_pokedex) == 3);
    assert(is_copied_pokemon(get_current_pokemon(found_pokedex), bulbasaur));
    
    printf("       --> Checking in the new Pokedex are in ascending order of pokemon_id\n");
    assert(pokemon_id(get_current_pokemon(found_pokedex)) == 1);
    next_pokemon(found_pokedex);
    assert(pokemon_id(get_current_pokemon(found_pokedex)) == 2);
    next_pokemon(found_pokedex);
    assert(pokemon_id(get_current_pokemon(found_pokedex)) == 3);
    
    printf("       --> Checking in the new Pokedex that pokemons does not evolve\n");
    assert(get_next_evolution(found_pokedex) == DOES_NOT_EVOLVE);
    prev_pokemon(found_pokedex);
    assert(get_next_evolution(found_pokedex) == DOES_NOT_EVOLVE);
    prev_pokemon(found_pokedex);
    assert(get_next_evolution(found_pokedex) == DOES_NOT_EVOLVE);
    
    printf("    ... Returning to the previous pokedex\n");
    destroy_pokedex(found_pokedex);
    
    printf("       --> Checking if the original pokedex is not modified\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    prev_pokemon(pokedex);
    assert(is_same_pokemon(get_current_pokemon(pokedex), venusaur));
    next_pokemon(pokedex);
    next_pokemon(pokedex);
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    assert(count_total_pokemon(pokedex) == 3);
    assert(count_found_pokemon(pokedex) == 3);
    
    printf("    ... Destroying both Pokedexes\n");
    destroy_pokedex(pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}

// `test_search_pokemon` checks whether the test_search_pokemon
// function works correctly.
//
// It checks the search_pokemon function when the Pokedex is empty.
// It checks the search_pokemon function when the Pokedex has none of
// the Pokemon's name contains provided text.
// It checks that the selected Pokemon in the returned Pokedex has been set correctly.
// It checks that the original Pokedex is not modified.
// It checks that either the lower or upper cases are matched in the name of the pokemon
// the pokemons is copied into new pokedex.
// It checks that pokemons are only copied and returned if name matches and it is found.
// It checks that the number of total pokemons and number of found pokemons are 
// correctly returned in the new pokedex.
static void test_search_pokemon(void) {
    printf("\n>> Testing search_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Getting all Pokemon contains 'saur' in a empty pokedex\n");
    Pokedex search_pokedex = search_pokemon(pokedex, "saur");
    
    printf("       --> Checking if the type pokedex is empty\n");
    assert(count_total_pokemon(search_pokedex) == 0);
    
    printf("    ... Returning to the original pokedex\n");
    destroy_pokedex(search_pokedex);
    
    printf("    ... Creating Venusaur, Bulbasaur and Ivysaur\n");
    Pokemon venusaur = create_venusaur();
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    
    printf("    ... Adding Venusaur, Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf("       --> Checking that none of the pokemons are found\n");
    assert(count_found_pokemon(pokedex) == 0);
    
    printf("       --> Checking that the current Pokemon is Venusaur\n");
    assert(get_current_pokemon(pokedex) == venusaur);
    
    printf("    ... Setting Venusaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Getting all Pokemons contains 'saur'\n");
    search_pokedex = search_pokemon(pokedex, "saur");
    
    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(search_pokedex) == 1);
    assert(count_found_pokemon(search_pokedex) == 1);
    assert(is_copied_pokemon(get_current_pokemon(search_pokedex), venusaur));
    
    printf("    ... Returning to the original pokedex\n");
    destroy_pokedex(search_pokedex);
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Setting Ivysaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Getting all Pokemons contains 'au'\n");
    search_pokedex = search_pokemon(pokedex, "au");

    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(search_pokedex) == 2);
    assert(count_found_pokemon(search_pokedex) == 2);
    assert(is_copied_pokemon(get_current_pokemon(search_pokedex), venusaur));
    next_pokemon(search_pokedex);
    assert(is_copied_pokemon(get_current_pokemon(search_pokedex), ivysaur));
    
    printf("    ... Returning to the original pokedex\n");
    destroy_pokedex(search_pokedex);
    
    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);

    printf("    ... Setting Bulbasaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Getting all Pokemons contains 'AU'\n");
    search_pokedex = search_pokemon(pokedex, "AU");
    
    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(search_pokedex) == 3);
    assert(count_found_pokemon(search_pokedex) == 3);
    assert(is_copied_pokemon(get_current_pokemon(search_pokedex), venusaur));
    next_pokemon(search_pokedex);
    assert(is_copied_pokemon(get_current_pokemon(search_pokedex), bulbasaur));
    next_pokemon(search_pokedex);
    assert(is_copied_pokemon(get_current_pokemon(search_pokedex), ivysaur));
    
    printf("       --> Checking that in the new Pokedex pokemons do not evolve\n");
    assert(get_next_evolution(search_pokedex) == DOES_NOT_EVOLVE);
    prev_pokemon(search_pokedex);
    assert(get_next_evolution(search_pokedex) == DOES_NOT_EVOLVE);
    prev_pokemon(search_pokedex);
    assert(get_next_evolution(search_pokedex) == DOES_NOT_EVOLVE);
    
    printf("    ... Returning to the original pokedex\n");
    destroy_pokedex(search_pokedex);
    
    printf("    ... Getting all Pokemons contains 'pika'\n");
    search_pokedex = search_pokemon(pokedex, "pika");
    
    printf("       --> Checking that the function returned an empty pokedex\n");
    assert(count_total_pokemon(search_pokedex) == 0);
    
    printf("    ... Returning to the original pokedex\n");
    destroy_pokedex(search_pokedex);
    
    printf("       --> Checking if the original pokedex is not modified\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    prev_pokemon(pokedex);
    assert(is_same_pokemon(get_current_pokemon(pokedex), venusaur));
    next_pokemon(pokedex);
    next_pokemon(pokedex);
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    assert(count_total_pokemon(pokedex) == 3);
    assert(count_found_pokemon(pokedex) == 3);
    
    printf("    ... Destroying both Pokedexes\n");
    destroy_pokedex(pokedex);

    printf(">> Passed string_pokedex tests!\n");
}


////////////////////////////////////////////////////////////////////////
//                     Helper Functions                               //
////////////////////////////////////////////////////////////////////////

// Helper function to create Bulbasaur for testing purposes.
static Pokemon create_bulbasaur(void) {
    Pokemon pokemon = new_pokemon(
            BULBASAUR_ID, BULBASAUR_NAME,
            BULBASAUR_HEIGHT, BULBASAUR_WEIGHT,
            BULBASAUR_FIRST_TYPE,
            BULBASAUR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Ivysaur for testing purposes.
static Pokemon create_ivysaur(void) {
    Pokemon pokemon = new_pokemon(
            IVYSAUR_ID, IVYSAUR_NAME,
            IVYSAUR_HEIGHT, IVYSAUR_WEIGHT,
            IVYSAUR_FIRST_TYPE,
            IVYSAUR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Venusaur for testing purposes.
static Pokemon create_venusaur(void) {
    Pokemon pokemon = new_pokemon(
            VENUSAUR_ID, VENUSAUR_NAME,
            VENUSAUR_HEIGHT, VENUSAUR_WEIGHT,
            VENUSAUR_FIRST_TYPE,
            VENUSAUR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Charmander for testing purposes.
static Pokemon create_charmander(void) {
    Pokemon pokemon = new_pokemon(
            CHARMANDER_ID, CHARMANDER_NAME,
            CHARMANDER_HEIGHT, CHARMANDER_WEIGHT,
            CHARMANDER_FIRST_TYPE,
            CHARMANDER_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Charmeleon for testing purposes.
static Pokemon create_charmeleon(void) {
    Pokemon pokemon = new_pokemon(
            CHARMELEON_ID, CHARMELEON_NAME,
            CHARMELEON_HEIGHT, CHARMELEON_WEIGHT,
            CHARMELEON_FIRST_TYPE,
            CHARMELEON_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Charizard for testing purposes.
static Pokemon create_charizard(void) {
    Pokemon pokemon = new_pokemon(
            CHARIZARD_ID, CHARIZARD_NAME,
            CHARIZARD_HEIGHT, CHARIZARD_WEIGHT,
            CHARIZARD_FIRST_TYPE,
            CHARIZARD_SECOND_TYPE
    );
    return pokemon;
}



// Helper function to compare whether two Pokemon are the same.
// This checks that the two pointers contain the same address, i.e.
// they are both pointing to the same pokemon struct in memory.
//
// Pokemon ivysaur = new_pokemon(0, 'ivysaur', 1.0, 13.0, GRASS_TYPE, POISON_TYPE)
// Pokemon also_ivysaur = ivysaur
// is_same_pokemon(ivysaur, also_ivysaur) == TRUE
static int is_same_pokemon(Pokemon first, Pokemon second) {
    return first == second;
}

// Helper function to compare whether one Pokemon is a *copy* of
// another, based on whether their attributes match (e.g. pokemon_id,
// height, weight, etc).
// 
// It also checks that the pointers do *not* match -- i.e. that the
// pointers aren't both pointing to the same pokemon struct in memory.
// If the pointers both contain the same address, then the second
// Pokemon is not a *copy* of the first Pokemon.
// 
// This function doesn't (yet) check that the Pokemon's names match
// (but perhaps you could add that check yourself...).
static int is_copied_pokemon(Pokemon first, Pokemon second) {
    return (pokemon_id(first) == pokemon_id(second))
    &&  (first != second)
    &&  (pokemon_height(first) == pokemon_height(second))
    &&  (pokemon_weight(first) == pokemon_weight(second))
    &&  (pokemon_first_type(first) == pokemon_first_type(second))
    &&  (pokemon_second_type(first) == pokemon_second_type(second));
}

// Write your own helper functions here!
