#include <stdio.h>
#include "structures.h"
#include "ui.h"
#include "habits.h"

int main() {
    ListeHabits liste;
    liste.nombreHabits = 0;

    int choix = 0;
    while (choix != 5) {
        afficherMenuPrincipal();
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                creerHabitude(&liste);
                break;
            case 2:
                modifierHabitude(&liste);
                break;
            case 3:
                supprimerHabitude(&liste);
                break;
            case 4:
                afficherHabitudes(&liste);
                break;
            case 
