#include <stdlib.h>
#include <stdio.h>

void	echanger(int tab[], int x, int y);
void	tri_selection(int infraction[], int taille);
int		prix_amende(int tab[]);

void echanger(int tab[], int x, int y)
{
	int var_temp;

	var_temp = tab[x];
	tab[x] = tab[y];
	tab[y] = var_temp;
}

void tri_selection(int infraction[], int taille)
{
	int min;
	int compteur_i = 0;

	while (compteur_i <= taille-1)
	{
		min = compteur_i;
		int compteur_j = compteur_i + 1;
		while (compteur_j <= taille)
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

int	prix_amende(int tab[])
{
	int amende;
	int i = 0;

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






int	main (void)
{
	int	ch = '\0';
	int type_infraction;
	int infraction[10];
	int points = 20;
	int amende = 0;
	int amendetest;
	int i;

	for (i = 0; i < 10; i++)
	{
		infraction[i] = 0;
	}

	printf("Vous possedez une clef permis neuve, vous avez donc 20 points.\n");
	printf("Afin de démarrer le programme, appuyez sur une touche puis sur la touche entree.\n");
	i = 0;
	while (1 && i < 10)
	{
		ch = getchar();
		if (ch != '\0')
		{
			printf("Entrez le type d'infraction (1, 2, 3, 4)\n");
			printf("Infraction de type : ");
			scanf("%d", &type_infraction);
			printf("\n\n\n");
			ch = '\0';
		}
		if (type_infraction == 1)
		{
			system("cls");
			system("clear");
			printf("Vous venez de perdre 2 points\n");
			points = points - 2;
			printf("Vous avez maintenant %d points\n", points);
			amende = amende + 100;
			printf("Calcul de l'amende sans utilisation du tableau\n");
			printf("Vous avez %d € d'amende à payer", amende);
			printf("\n\n");
			infraction[i] = 2;
			printf("Calcul de l'amende avec utilisation du tableau\n");
			printf("Tableau avant tri : ");
			for (int a = 0; infraction[a] != 0; a++)
			{
				printf("| %d ", infraction[a]);
			}
			printf("\n");
			tri_selection(infraction, i);
			amendetest = prix_amende(infraction);
			printf("Amende de %d €\n", amendetest);
			printf("Tableau apres tri : ");
			for (int a = 0; infraction[a]; a++)
			{
				printf("| %d ", infraction[a]);
			}
			printf("\n\n");
			i++;
			type_infraction = 0;





		}
		else if (type_infraction == 2) 
		{
			system("cls");
			system("clear");
			printf("Vous venez de perdre 4 points\n");
			points = points - 4;
			printf("Vous avez maintenant %d points\n", points);
			amende = amende + 200;
			printf("Calcul de l'amende sans utilisation du tableau\n");
			printf("Vous avez %d € d'amende à payer", amende);
			printf("\n\n");
			infraction[i] = 4;
			printf("Calcul de l'amende avec utilisation du tableau\n");
			printf("Tableau avant tri : ");
			for (int a = 0; infraction[a] != 0; a++)
			{
				printf("| %d ", infraction[a]);
			}
			printf("\n");
			tri_selection(infraction, i);
			amendetest = prix_amende(infraction);
			printf("Amende de %d €\n", amendetest);
			printf("Tableau apres tri : ");
			for (int a = 0; infraction[a] != 0; a++)
			{
				printf("| %d ", infraction[a]);
			}
			printf("\n\n");
			i++;
			type_infraction = 0;
		}
		else if (type_infraction == 3)
		{
			system("cls");
			system("clear");
			printf("Vous venez de perdre 6 points\n");
			points = points - 6;
			printf("Vous avez maintenant %d points\n", points);
			amende = amende + 300;
			printf("Calcul de l'amende sans utilisation du tableau\n");
			printf("Vous avez %d € d'amende à payer", amende);
			printf("\n\n");
			infraction[i] = 6;
			printf("Calcul de l'amende avec utilisation du tableau\n");
			printf("Tableau avant tri : ");	
			for (int a = 0; infraction[a] != 0; a++)
			{
				printf("| %d ", infraction[a]);
			}
			printf("\n");
			tri_selection(infraction, i);
			amendetest = prix_amende(infraction);
			printf("Amende de %d €\n", amendetest);
			printf("Tableau apres tri : ");
			for (int a = 0; infraction[a] != 0; a++)
			{
				printf("| %d ", infraction[a]);
			}
			printf("\n\n");
			i++;
			type_infraction = 0;
		}
		else if (type_infraction == 4)
		{
			system("cls");
			system("clear");
			printf("Vous venez de perdre 20  points\n");
			points = points - 20;
			printf("Vous avez maintenant %d points\n", points);
			amende = amende + 400;
			printf("Calcul de l'amende sans utilisation du tableau\n");
			printf("Vous avez %d € d'amende à payer", amende);
			printf("\n\n");
			infraction[i] = 20;
			printf("Calcul de l'amende avec utilisation du tableau\n");
			printf("Tableau avant tri : ");
			for (int a = 0; infraction[a] != 0; a++)
			{
				printf("| %d ", infraction[a]);
			}
			printf("\n");
			tri_selection(infraction, i);
			amendetest = prix_amende(infraction);
			printf("Amende de %d €\n", amendetest);
			printf("Tableau apres tri : ");
			for (int a = 0; infraction[a] != 0; a++)
			{
				printf("| %d ", infraction[a]);
			}
			printf("\n\n");
			i++;
			type_infraction = 0;
		}

		if (points <= 0)
		{
			printf("Vous n'avez plus de points, vous ne pouvez donc plus conduire\n");
			exit(0);
		}
	}
}
