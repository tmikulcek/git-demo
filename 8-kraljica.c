#include <stdio.h>

int ploca[8][8];
int postavljeno;
int preskoci[8][8];

void kraljice();
void postavi_kraljicu(int red, int stupac);
void ukloni_kraljicu();
int kvadrat(int red, int stupac, int i, int j);
void ispisi();

int main()
{
	int i, j;
	
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
		{
			ploca[i][j] = 0;
			preskoci[i][j] = 0;
		}
	postavljeno = 0;
	
	kraljice();
	ispisi();
	return 0;
}

void kraljice()
{
	int stupac, pronasao_mjesto;
	
	while(postavljeno < 8)
	{
		pronasao_mjesto = 0;
		
		for (stupac = 0; stupac < 8; stupac++)
		{
			if (ploca[postavljeno][stupac] == 0 && preskoci[postavljeno][stupac] == 0)
			{
				postavi_kraljicu(postavljeno, stupac);
				pronasao_mjesto = 1;
				break;
			}
		}
		
		if (!pronasao_mjesto)
			ukloni_kraljicu();
	}
}

void postavi_kraljicu(int red, int stupac)
{
	int i, j;
	
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
		{
			if (i == red || j == stupac || kvadrat(red, stupac, i, j))
				ploca[i][j]++;
		}
		
	ploca[red][stupac] = 10;
	postavljeno++;
	printf("postavio kraljicu broj %d na stupac %d\n", postavljeno, stupac + 1);
}

void ukloni_kraljicu()
{
	int red, stupac, stupac_kraljice;
	postavljeno--;
	
	for (stupac = 0; stupac < 8; stupac++)
	{
		if (ploca[postavljeno][stupac] == 10)
		{
			ploca[postavljeno][stupac] = 0;
			preskoci[postavljeno][stupac] = 1;
			stupac_kraljice = stupac;
			break;
		}
	}
	
	for (red = 0; red < 8; red++)
		for (stupac = 0; stupac < 8; stupac++)
			if ((red == postavljeno || stupac == stupac_kraljice || kvadrat(postavljeno, stupac_kraljice, red, stupac)) && ploca[red][stupac] > 0)
				ploca[red][stupac]--;
			
	for (stupac = 0; stupac < 8; stupac++)
		preskoci[postavljeno + 1][stupac] = 0;
	
	printf("uklonio kraljicu broj %d\n", postavljeno + 1);
}

void ispisi()
{
	int red, stupac;
	
	for (red = 0; red < 8; red++)
	{
		for (stupac = 0; stupac < 8; stupac++)
		{
			if (ploca[red][stupac] != 10)
				printf("_ ");
			else
				printf("K ");
		}
		printf("\n");
	}
}

int kvadrat(int red, int stupac, int i, int j)
{
	int apsolutni_i, apsolutni_j;
	
	apsolutni_i = red - i;
	if (apsolutni_i < 0)
		apsolutni_i = 0 - apsolutni_i;
	
	apsolutni_j = stupac - j;
	if (apsolutni_j < 0)
		apsolutni_j = 0 - apsolutni_j;
		
	if (apsolutni_i == apsolutni_j)
		return 1;
	else
		return 0;
}
