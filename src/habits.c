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
    printf("Date : %s\n", habitude->date);
    printf("Heure : %s\n", habitude->heure);
    printf("Statut : %s\n", habitude->estCochee ? "Cochee" : "Non cochee");
    printf("---------------\n");
}

void modifierHabitude(ListeHabits *liste) {
    if (liste->nombreHabits == 0) {
        printf("Aucune habitude n'est disponible.\n");
        return;
    }

    printf("Choisissez le numero de l'habitude a modifier (1-%d) : ", liste->nombreHabits);
    int choix;
    scanf("%d", &choix);

    if (choix < 1 || choix > liste->nombreHabits) {
        printf("Numero invalide.\n");
        return;
    }

    Habit *habitude = &(liste->habits[choix - 1]);

    printf("Nouveau nom de l'habitude : ");
    scanf("%s", habitude->nom);

    printf("Nouvelle description de l'habitude : ");
    scanf("%s", habitude->description);

    printf("Nouvelle priorite de l'habitude : ");
    scanf("%d", &(habitude->priorite));

    printf("Nouvelle date de l'habitude (JJ/MM/AAAA) : ");
    scanf("%s", habitude->date);

    printf("Nouvelle heure de l'habitude (HH:MM) : ");
    scanf("%s", habitude->heure);

    printf("L'habitude a été modifiée avec succès.\n");
}

void supprimerHabitude(ListeHabits *liste) {
    if (liste->nombreHabits == 0) {
        printf("A

