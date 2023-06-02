#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "habits.h"

void creerHabitude(ListeHabits *liste) {
    if (liste->nombreHabits >= MAX_HABITS) {
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
        printf("Aucune habitude n'est disponible.\n");
        return;
    }

    printf("Choisissez le numero de l'habitude a supprimer (1-%d) : ", liste->nombreHabits);
    int choix;
    scanf("%d", &choix);

    if (choix < 1 || choix > liste->nombreHabits) {
        printf("Numero invalide.\n");
        return;
    }

    // Supprimer l'habitude en décalant les éléments suivants du tableau
    for (int i = choix - 1; i < liste->nombreHabits - 1; i++) {
        liste->habits[i] = liste->habits[i + 1];
    }

    liste->nombreHabits--;

    printf("L'habitude a été supprimée avec succès.\n");
}

void afficherHabitudes(const ListeHabits *liste) {
    if (liste->nombreHabits == 0) {
        printf("Aucune habitude n'est disponible.\n");
        return;
    }

    printf("----- Liste des habitudes -----\n");
    for (int i = 0; i < liste->nombreHabits; i++) {
        printf("Habitude %d :\n", i + 1);
        afficherHabitude(&(liste->habits[i]));
    }
}

void afficherMenu(ListeHabits *liste) {
    int choix = 0;

    while (choix != 5) {
        printf("----- Menu -----\n");
        printf("1. Créer une habitude\n");
        printf("2. Afficher les habitudes\n");
        printf("3. Modifier une habitude\n");
        printf("4. Supprimer une habitude\n");
        printf("5. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                creerHabitude(liste);
                break;
            case 2:
                afficherHabitudes(liste);
                break;
            case 3:
                modifierHabitude(liste);
                break;
            case 4:
                supprimerHabitude(liste);
                break;
            case 5:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }

        printf("\n");
    }
}

int main() {
    ListeHabits liste;
    liste.nombreHabits = 0;

    afficherMenu(&liste);

    return 0;
}
