#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
struct card
{
	char order;
	char number;
};
struct trump
{
	char order;
	char shape[3];
	char number;
};
void make_card(trump m_card[])
{
	int i, j;
	char shape[4][3] = {"¢¼","¡ß","¢¾" ,"¢À"};
	for (i = 0; i < 4; i++)
	{
		for (j = i * 13; j < i * 13+13; j++)
		{
			m_card[j].order = i;
			strcpy(m_card[j].shape, shape[i]);
			m_card[j].number = j % 13 + 1;
			
			if(m_card[j].number == 1)
			{
				m_card[j].number = 'A';
			}
			else if (m_card[j].number == 11)
			{
				m_card[j].number = 'J';
			}
			else if (m_card[j].number == 12)
			{
				m_card[j].number = 'Q';
			}
			else if (m_card[j].number == 13)
			{
				m_card[j].number = 'K';
			}
		}
	}
}

void display_card(trump m_card[])
{
	int i, count =0;
	for(i = 0; i < 52; i++)
	{
		printf("%s", m_card[i].shape);
		if(10<m_card[i].number)
			printf("%-2c	", m_card[i].number);
		else
			printf("%-2d	", m_card[i].number);
		count++;
		if(i % 13+1 == 13)
		{
			printf("\n");
			count = 0;
		}
	}
}
void Shuffle(trump card[])
{
	int rnd;
	trump temp;
	for(int i = 0; i < 10; i++)
	{
		rnd = rand()%10;
		temp = card[rnd];
		card[rnd] = card[i];
		card[i] = temp;
	}
	
}

void DurstenfieldShuffle(trump card[], int size)
{
	int target;
	trump temp;
	for(int i = 0; i < 52; i++)
	{
		target = rand()%(52);
		temp = card[i];
		card[i] = card[target];
		card[target] = temp;
	}

}
trump card[52];
int main(void)
{
	srand(time(NULL));
	make_card(card);
	DurstenfieldShuffle(card, sizeof(card)/sizeof(trump));
	display_card(card);
	return 0;
}



