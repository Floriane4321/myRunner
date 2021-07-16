/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** graphique
*/

//gcc -l csfml-graphics
//sprite sheep

#include "include/graphic.h"

void display_h(void)
{
    my_putstr("\nIl y a une animation à la fin si vous gagnez ! ");
    my_putstr("Sinon il y a une map courte et sans obstacle: win.txt\n");
    my_putstr("Il y a également des animations dans le menu.\n\n");
    my_putstr("USAGE\n");
    my_putstr("    ./my_runnner map/....txt\n");
    my_putstr("Créer une map : 1 pour un espace\n");
    my_putstr("              : o pour un obstacle\n\n");
    my_putstr("USER INTERACTIONS\n\n");
    my_putstr("SPACE_KEY  --> jump\n");
    my_putstr("ENTER_KEY  --> continue\n");
    my_putstr("ESCAPE_KEY --> stop the game\n");
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        display_h();
        return(0);
    }
    create_window(av[1]);
    return EXIT_SUCCESS;
}
