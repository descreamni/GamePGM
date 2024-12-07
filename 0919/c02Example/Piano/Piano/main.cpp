#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <Conio.h>
int calc_frequency(int octave, int inx)
{
	double do_scale = 32.7032;
	double ratio = pow(2., 1 / 12.), temp;
	int i;
	temp = do_scale * pow(2, octave - 1);
	for (i = 0; i < inx; i++)
	{
		temp = (int)(temp + 0.5);
		temp *= ratio;
	}
	return(int)temp;
}
void print_frequency(int octave)
{
	double do_scale = 32.7032;
	double ratio = pow(2., 1 / 12.), temp;
	int i;
	temp = do_scale * pow(2, octave - 1);
	printf("%d��Ÿ�� : ", octave);
	for (i = 0; i < 12; i++)
	{
		printf("%4ld", (unsigned long)(temp + 0.5));
		temp *= ratio;
	}
	printf("\n");
}
void printing() {
	const char* scale[] = { "��","��#", "��","��#", "��", "��","��#", "��","��#", "��","��#","��","��" };
	int i, octave, count = 0;
	printf("����� ���ļ�\n\n����\t		");
	for (i = 0; i < 12; i++)
	{
		printf("%-5s", scale[i]);
	}
	printf("\n");
	for (i = 0; i <= 70; i++)
	{
		printf("-");
	}
	printf("\n");
	for (octave = 1; octave < 7; octave++)
	{
		print_frequency(octave);
	}
}
void sound()
{
	int index[] = { 0,2,4,5,7,9,11,12 };
	int freq[8];
	int i;
	for (i = 0; i < 8; i++)
	{
		freq[i] = calc_frequency(4, index[i]);
	}
	for (i = 0; i < 8; i++)
		Beep(freq[i], 500);
	return;
}
void practice_piano()
{
	int index[] = { 0,2,4,5,7,9,11,12 };
	int freq[8], code,i;
	for (i = 0; i < 8; i++)
		freq[i] = calc_frequency(4, index[i]);
	do
	{
		code = getch();
		if ('1' <= code && code <= '8')
		{
			code -= 49;
			Beep(freq[code], 300);
		}
	} while (code != 27);
}
void pushKeyboard()
{
	printf("1���� 8���� ���� Ű�� ������\n");
	printf("�� ���� �Ҹ��� ��µ˴ϴ�.\n\n");
	printf("1:�� 2:�� 3:�� 4:�� 5:�� 6:�� 7:�� 8:��\n");
	printf("���α׷� �����  ESCŰ\n");
	printf("1���� 8���� ���� Ű�� ������\n");
	practice_piano();
	return;
}
int main()
{
	//printing();
	//sound();
	pushKeyboard();
}