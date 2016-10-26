#include <stdlib.h>
#include <stdio.h>

void	echanger(int *tab, int x, int y);
void	tri_selection(int *infraction, int *taille);
int		prix_amende(int *tab);
void	afficheAmende (int *infraction,  int *points, int type_infraction, int *compteur);

void	echanger(int *tab, int x, int y)
{
		int var_temp;

		var_temp = tab[x];
		tab[x] = tab[y];
		tab[y] = var_temp;
}

void	tri_selection(int *infraction, int *taille)
{
		int min;
		int compteur_i;

		compteur_i = 0;
		while (compteur_i <= *taille-1)
		{
				int compteur_j;

				min = compteur_i;
				compteur_j = compteur_i + 1;
				while (compteur_j <= *taille)
				{
						if (infraction[compteur_j] < infraction[min])
								min = compteur_j;
						compteur_j++;
				}
				if (min != compteur_i)
						echanger(infraction, compteur_i, min);
				compteur_i++;
		}

}

int		prix_amende(int *tab)
{
		int amende;
		int i;

		i = 0;
		int type_infraction1 (void)
		{
				int nb_infraction = 0;

				while (tab[i] == 2)
				{
						i++;
						nb_infraction++;
				}
				return nb_infraction;
		}
		int type_infraction2 (void)
		{
				int nb_infraction = 0;

				while (tab[i] == 4)
				{
						i++;
						nb_infraction++;
				}
				return nb_infraction;
		}
		int type_infraction3 (void)
		{
				int nb_infraction = 0;

				while (tab[i] == 6)
				{
						i++;
						nb_infraction++;
				}
				return nb_infraction;
		}
		int type_infraction4 (void)
		{
				int nb_infraction = 0;

				while (tab[i] == 20)
				{
						i++;
						nb_infraction++;
				}
				return nb_infraction;
		}

		amende = (type_infraction1() * 100) + (type_infraction2() * 200) + (type_infraction3() * 300) + (type_infraction4() * 400);

		return amende;
}


void	afficheAmende (int *infraction,  int *points, int type_infraction, int *compteur)
{
		int *pointsPerdus;
		int a;

		pointsPerdus = malloc(sizeof(int));
		switch (type_infraction)
		{
			case 1:
				*pointsPerdus = 2;
				break;
			case 2:
				*pointsPerdus = 4;
				break;
			case 3:
				*pointsPerdus = 6;
				break;
			case 4:
				*pointsPerdus = 20;
				break;
		}
		system("cls");
		system("clear");
		*points = *points - *pointsPerdus;
		infraction[*compteur] = *pointsPerdus;
		printf("Tableau avant tri : ");
		for (a = 0; infraction[a] != 0; a++)
		{
				printf("| %d ", infraction[a]);
		}
		printf("\n\n\n");
		printf("Vous venez de perdre %d points\n", *pointsPerdus);
		printf("Vous avez maintenant %d points\n\n", *points);
		printf("Calcul de l'amende avec utilisation du tableau\n");
		tri_selection(infraction, compteur);
		printf("Amende de %d €\n\n", prix_amende(infraction));
		printf("Tableau apres tri : ");
		for ( a = 0; infraction[a]; a++)
		{
				printf("| %d ", infraction[a]);
		}
		printf("\n\n");
		*compteur = *compteur + 1;
		type_infraction = 0;
		free(pointsPerdus);
}



int		main (void)
{
		int	ch = '\0';
		int type_infraction;
		int *infraction = NULL;
		int points;
		int compteur;
	//	for (i = 0; i < 10; i++)
	//	{
	//			infraction[i] = NULL;
	//	}

		printf("Vous possedez une clef permis neuve, vous avez donc 20 points.\n");
		printf("Afin de démarrer le programme, appuyez sur la touche entree.\n");
		compteur = 0;
		points = 20;
		infraction = malloc(sizeof(int) * 10);
		while (1)
		{
				ch = getchar();
				if (ch != '\0')
				{
						printf("Entrez le type d'infraction (1, 2, 3, 4) ou 0 pour terminer le programme\n");
						printf("Infraction de type : ");
						scanf("%d", &type_infraction);
						printf("\n\n\n");
						ch = '\0';
				}
				if (type_infraction == 1)
				{
						afficheAmende (infraction, &points, type_infraction, &compteur);
				}
				else if (type_infraction == 2) 
				{
						afficheAmende (infraction, &points, type_infraction, &compteur);
				}
				else if (type_infraction == 3)
				{
						afficheAmende (infraction, &points, type_infraction, &compteur);
				}
				else if (type_infraction == 4)
				{
						afficheAmende (infraction, &points, type_infraction, &compteur);
				}
				else if (type_infraction == 0)
				{
					printf("Vous avez toujours votre permis avec %d points et une amende en cours de %d €.\n", points, prix_amende(infraction));
					free(infraction);
					exit(0);
				}
				if (points <= 0)
				{
						printf("Vous n'avez plus de points, vous ne pouvez donc plus conduire\n");
						free(infraction);
						exit(0);
				}
		}
}
