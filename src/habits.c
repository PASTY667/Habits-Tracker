#include <stdio.h>
#include "habits.h"
#include <string.h>

void creerHabitude(ListeHabits *liste) {
    // Code pour créer une nouvelle habitude
}

void afficherHabitude(const Habit *habitude) {
    // Code pour afficher une habitude
}

void modifierHabitude(ListeHabits *liste) {
    // Code pour modifier une habitude existante
}

void supprimerHabitude(ListeHabits *liste) {
    // Code pour supprimer une habitude de la liste
}



void creerHabitude(ListeHabits *liste) {
    if (liste->nombreHabits >= 100) {
        printf("La liste des habitudes est pleine.\n");
        return;
    }

    Habit nouvelleHabitude;
    printf("Nom de l'habitude : ");
    scanf("%s", nouvelleHabitude.nom);

    printf("Description de l'habitude : ");
    scanf("%s", nouvelleHabitude.description);

    printf("Priorite de l'habitude : ");
    scanf("%d", &(nouvelleHabitude.priorite));

    printf("Date de l'habitude (JJ/MM/AAAA) : ");
    scanf("%s", nouvelleHabitude.date);

    printf("Heure de l'habitude (HH:MM) : ");
    scanf("%s", nouvelleHabitude.heure);

    nouvelleHabitude.estCochee = 0; // Par défaut, l'habitude n'est pas cochée

    liste->habits[liste->nombreHabits] = nouvelleHabitude;
    liste->nombreHabits++;

    printf("L'habitude a été créée avec succès.\n");
}

void afficherHabitude(const Habit *habitude) {
    printf("Nom : %s\n", habitude->nom);
    printf("Description : %s\n", habitude->description);
    printf("Priorite : %d\n", habitude->priorite);
    printf("Date : %s\n",

