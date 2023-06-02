#ifndef HABITS_H
#define HABITS_H

#include "structures.h"

void creerHabitude(ListeHabits *liste);
void afficherHabitude(const Habit *habitude);
void modifierHabitude(ListeHabits *liste);
void supprimerHabitude(ListeHabits *liste);

#endif
