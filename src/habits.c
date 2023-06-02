#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_HABITUDES 100
#define MAX_JOURS 7

typedef struct {
    char nom[50];
    char description[100];
    int priorite;
    bool jours[MAX_JOURS];
} Habitude;

typedef struct {
    Habitude habitudes[MAX_HABITUDES];
    int nombreHabitudes;
} ListeHabitudes;

void ajouterHabitude(ListeHabitudes *liste) {
    if (liste->nombreHabitudes >= MAX_HABITUDES) {
        printf("La liste des habitudes est pleine.\n");
        return;
    }

    Habitude nouvelleHabitude;

    printf("Nom de l'habitude : ");
    scanf("%s", nouvelleHabitude.nom);

    printf("Description de l'habitude : ");
    scanf("%s", nouvelleHabitude.description);

    printf("Priorite de l'habitude : ");
    scanf("%d", &nouvelleHabitude.priorite);

    for (int i = 0; i < MAX_JOURS; i++) {
        nouvelleHabitude.jours[i] = false;
    }

    liste->habitudes[liste->nombreHabitudes] = nouvelleHabitude;
    liste->nombreHabitudes++;

    printf("L'habitude a ete ajoutee avec succes.\n");
}

void cocherJour(Habitude *habitude, int jour) {
    if (jour >= 0 && jour < MAX_JOURS) {
        habitude->jours[jour] = !habitude->jours[jour];
    }
}

void afficherHabitudes(const ListeHabitudes *liste) {
    printf("---------------------------\n");
    printf("     Habits Tracker\n");
    printf("---------------------------\n\n");

    for (int i = 0; i < liste->nombreHabitudes; i++) {
        const Habitude *habitude = &(liste->habitudes[i]);

        printf("[ Habitude %d ]\n\n", i + 1);
        printf("Nom : %s\n", habitude->nom);
        printf("Description : %s\n", habitude->description);
        printf("Priorite : %d\n", habitude->priorite);

        printf("---------------------------\n");
        printf("      L      M      M      J      V      S      D\n");
        printf("---------------------------\n");

        for (int j = 0; j < MAX_JOURS; j++) {
            printf(" [%c]    ", habitude->jours[j] ? 'V' : 'X');
        }

        printf("\n\n");
    }
}

int main() {
    ListeHabitudes liste;
    liste.nombreHabitudes = 0;

    int choix = 0;
    while (choix != 3) {
        printf("---------------------------\n");
        printf("     Habits Tracker\n");
        printf("---------------------------\n\n");
        printf("1. Ajouter une habitude\n");
        printf("2. Afficher les habitudes\n");
        printf("3. Quitter\n\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterHabitude(&liste);
                break;
            case 2:
                afficherHabitudes(&liste);
                break;
            case 3:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}
