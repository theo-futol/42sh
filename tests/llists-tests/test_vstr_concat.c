/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(vstr_concat, concatening_strings_together)
{
    char *string = NULL;
    char *string2 = "epzgjoierghuizfeigoeruigbzforuebgjzifeuzzhuirzbgz";
    char *string3 = NULL;

    string = vstr_concat(2, "Co", "Ala");
    cr_assert_str_eq(string, "CoAla");
    string2 = vstr_concat(4, string, " est ", "de retour", "lol");
    cr_assert_str_eq(string2, "CoAla est de retourlol");
    cr_assert(vstr_concat(0, "My", " mistake") == NULL);
    cr_assert(vstr_concat(0, "My", " mistake", NULL, " again") == NULL);
    string3 = vstr_concat(4, "", "", "", "");
    cr_assert_str_eq(string3, "");
    string3 = vstr_concat(1, "Lol");
    cr_assert(string3, "Lol");
}
