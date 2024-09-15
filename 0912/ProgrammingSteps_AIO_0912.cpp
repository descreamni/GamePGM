#include <stdio.h>
//실행에서 입출력을 하기 위해 필요한 것 
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
struct Vector2
{
	int m_ix;
	int m_iy;
};

enum SizeOfMap
{
	MAXIMIZE_X = 79,
	MAXIMIZE_Y = 24
};
enum Scene
{
	PRINT_DIVISION_TEXT = 1,
	MULTIPLY_CHART,
	DEL_CONSOLE_SCREEN,
	EMPTY_BUFFER,
	ASCII_EXPAND_KEY,
	MOVE_ARROW_KEY,
	DRAW_RECT,
	DRAW_RECT_WITH_NULL,
	MENU,
	SCENE,
	RANDOM_DEVICE,
	VARIABLE_ARGUMENT,
	END
};
enum RandomVariationsType
{
	DICE = 1,
	DUPLICATION,
	WITHOUT_DUPLICATION,
	SORTING_WITHOUT_DUPLICATION
};
/*
* MODULE FOR MENU
*/
void Engine();

/*
* MODULE CODES (NON-USED CLASS)
*/
void gotoxy(int x, int y);
void CursorPrinterPosition(Vector2 _FirstCursor, Vector2 _SecondCursor, const char* _textSpace);
int MenuSelector();
void Hamburger();
void Spaghetti();
void PressKey();


int MagazineMenu();
int Opt01_Disp();
int Opt02_Disp();
void Opt01_Direction();
void Opt02_Direction();

void MCKinsey_Topic01();
void MCKinsey_Topic02();
void Science_Topic01();
void Science_Topic02();
void SortArry(int* target, int size);

double sum(int count,...);
/*
* EXAMPLE CODES ARRANGED OF A LEAST COMPONENT
*/
void PrintDivisionText();
void MultiplyChart();
void DeletingConsoleScreen();
void EmptyBufferTest();
void ASCIIOrExpandKeyExample();
void MoveArrowKey();
void DrawRectangle();
void DrawRectangle(Vector2 _TopLeft, Vector2 _RightBottom); 
void Menu();
int Scene();
void RandomVariations(int _RandomVariationsType);
void VariableArgument(); 

int main(void)
{
	Engine();
	
	
	return 0;
	
}
void gotoxy(int x, int y)
{
	COORD Pos = {x - 1, y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void CursorPrinterPosition(Vector2 _FirstCursor, Vector2 _SecondCursor, const char* _textSpace)
{
	gotoxy(_FirstCursor.m_ix, _FirstCursor.m_iy);
	printf("%s",&_textSpace);
	gotoxy(_SecondCursor.m_ix, _SecondCursor.m_iy);
	printf("%s",&_textSpace);
}

void move_arrow_key(char key,int *x1, int *y1, int x_b, int y_b)
{
	switch(key)
	{
		case 72:
			*y1 = *y1 - 1;
			if(*y1<1)*y1 = 1;
			break;
		case 75:
			*x1 =*x1 -1;
			if(*x1 < 1) *x1 =1;
			break;
		case 77:
			*x1 = *x1 + 1;
			if (*x1 > x_b) *x1 =x_b;
			break;
		case 80:
			*y1 = *y1 + 1;
			if(*y1 > y_b) *y1 = y_b;
			break;
		default:
			return;
	}
}

int MenuSelector()
{
	int selector;
	system("cls");
	printf("Make a Sides \n\n");
	printf("1.Hamburger\n");
	printf("2.Spaghetti\n");
	printf("3.Return to Menu\n");
	printf("Select >");
	selector = getch()-48;
	return selector;
}
void Hamburger()
{
	system("cls");
	printf("Hamburger recipe\n");
	printf("ellipsis");
	PressKey();
}
void Spaghetti()
{
	system("cls");
	printf("Spaghetti recipe\n");
	printf("ellipsis");
	PressKey();
}
void PressKey()
{
	printf("\n\n");
	printf("Press any of a key");
	getch();
}


/*
* DIVIDE GUIDELINE
*/

int MagazineMenu()
{
	int select;
	printf("Magazines\n\n");
	printf("1.Financial Times\n");
	printf("2.Science\n");
	printf("3.Shutdown\n\n");
	printf("Select>");
	select = getch()-48;
	return select;
}

int Opt01_Disp()
{
	int select;
	system("cls");
	printf("Select the topic\n\n");
	printf("1.The future of chemicals in Japan: Shifting toward global specialties\n");
	printf("2.Five trends that will define South Korean grocery in 2023\n");
	printf("3.BACK\n\n");
	printf("Select>");
	select = getch()-48;
	return select;
}
int Opt02_Disp()
{
	int select;
	system("cls");
	printf("Select the topic");
	printf("1.CD4+ T cells with convergent TCR recombination reprogram stroma and halt tumor progression in adoptive therapy");
	printf("2.A spatially resolved single-cell lung atlas integrated with clinical and blood signatures distinguishes COVID-19 disease trajectories");
	printf("BACK\n\n");
	printf("Select>");
	select = getch()-48;
	return select;
}
void Opt01_Direction()
{
	int c;
	while((c=Opt01_Disp())!=3)
	{
		switch(c)
		{
			case 1: 
			MCKinsey_Topic01();
			break;
			case 2: 
			MCKinsey_Topic02();
			break;
			default:
			break;
		}
	}
	system("cls");
}
void Opt02_Direction()
{
	int c;
	while((c=Opt02_Disp())!=3)
	{
		switch(c)
		{
			case 1:
				Science_Topic01();
				break;
			case 2:
				Science_Topic02();
				break;
			default:
				break;
		}
	}
	system("cls");
}
void MCKinsey_Topic01()
{
	system("cls");
	printf("The future of chemicals in Japan:\n Shifting toward global specialties\n\n");
	printf("");
	PressKey();
}
void MCKinsey_Topic02()
{
	system("cls");
	printf("Five trends that will define\nSouth Korean grocery in 2023\n\n");
	printf("");
	PressKey();	
}
void Science_Topic01()
{
	system("cls");
	printf("CD4+ T cells with convergent TCR recombination reprogram stroma\and halt tumor progression in adoptive therapy\n\n");
	printf("");
	PressKey();	
}
void Science_Topic02()
{
	system("cls");
	printf("A spatially resolved single-cell lung atlas integrated\nwith clinical and blood signatures distinguishes COVID-19 disease trajectories\n\n");
	printf("");
	PressKey();	
}
/*
* DIVIDE GUIDELINE
*/

void SortArry(int* target, int size)
{
	int i, j, min, temp;
	for(i = 0; i <= size; i++)
	{
		min = i;
		for(j = i+1; j < size; j++)
			if(target[j] < target[min])
				min = j;
		temp = target[min];
		target[min] = target[i];
		target[i] = temp;
	}
	for(i = 0; i <= 5; i++)
		printf("%2d\n",target[i]);
}

double sum(int count,...)
{
	double total = 0, number;
	int i = 0;
	va_list ap;
	va_start(ap,count);
	while(i < count)
	{
		number = va_arg(ap,double);
		total+=number;
		i++;
	}
	va_end(ap);
	return total;
}

/*
* START SIGNIFICANT CODES 
*/
void PrintDivisionText()
{
	Vector2 first, second;
	const char* textCache;
	printf("Please input the data of the directions of texts.\nFirstCursor :: ");
	scanf("%d", &first.m_ix); scanf("%d", &first.m_iy);
	printf("SecondCursor :: ");
	scanf("%d", &second.m_ix); 	scanf("%d", &second.m_iy);
	printf("Which text do you want to print? :: ");
	scanf("%s", &textCache);
	system("cls");
	
	CursorPrinterPosition(first,second, textCache);
	printf("\n------------------------------\n");
	return;
}
void MultiplyChart()
{
	for(int i = 1; i <= 9; i++)
	{
		gotoxy(35, 5+i);
		printf("%d*%d=%2d", 3,i,3*i);
	}
	printf("\n");
	return;	
}

void DeletingConsoleScreen()
{
	char ch;
	int i;
	printf("Input char and Enter>");
	scanf(" %c", &ch);
	printf("\n");
	printf("Interpinted character::%c\n", ch);
}

void EmptyBufferTest()
{
	int i,j;
	for (j = 1; j <=9; j++)
	{
		system("cls");
		for(i = 1; i<=9;i++)
			printf("%d*%d = %d\n",j,i,j*i);
		printf("아무키나 누르시오.\n");
		getch();
	}
}
void ASCIIOrExpandKeyExample()
{
	int chr;
	bool exit = false;
	printf("== ESC KEY IS THE STOP LOOP ==\n\n");
	do
	{
		chr = getch();
		if(chr == 0||chr == 0xe0)
		{
			chr = getch();
			printf("Expand key code = %d\n",chr);
		}
		else if(chr == 0x1B)
		{
			printf("ASCII key code = %d\n",chr);
			exit = true;
		}
		else
			printf("ASCII key code = %d\n",chr);
	}while(exit == false);
}

void MoveArrowKey()
{
	char key;
	int x = 10, y = 5;
	do
	{
		gotoxy(x,y);
		printf("A");
		key = getch();
		move_arrow_key(key, &x, &y, MAXIMIZE_X, MAXIMIZE_Y);
		system("cls");
	}while(key != 27);
	
}
void DrawRectangle()
{
	unsigned char a =0xa6, b[7],i;
	for(i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	printf("%c%c", a, b[3]);
	printf("%c%c", a, b[4]);
	printf("\n");
	printf("%c%c", a, b[6]);
	printf("%c%c", a, b[5]);
	printf("\n");
}
void DrawRectangle(Vector2 _TopLeft, Vector2 _RightBottom)
{
	
	gotoxy(_TopLeft.m_ix, _TopLeft.m_iy);
	printf("┌");
	for(int i = _TopLeft.m_ix + 1; i < _RightBottom.m_ix; i++)
	{
		printf("─");
	}
	gotoxy(_RightBottom.m_ix, _TopLeft.m_iy);
	printf("┐");
	for(int i = _TopLeft.m_iy + 1; i < _RightBottom.m_iy; i++)
	{
		gotoxy(_TopLeft.m_ix, i);
		printf("│");
		gotoxy(_RightBottom.m_ix, i);
		printf("│");
	}
	gotoxy(_TopLeft.m_ix, _RightBottom.m_iy);
	printf("└");
	for(int i = _TopLeft.m_ix + 1; i < _RightBottom.m_ix; i++)
	{
		printf("─");
	}
	gotoxy(_RightBottom.m_ix, _RightBottom.m_iy);
	printf("┘");
	
	printf("\n");
}
void Menu()
{
	int c;
	while((c = MenuSelector())!= 3)
	{
		switch(c)
		{
			case 1 : 
			Hamburger();
			break;
			case 2 : 
			Spaghetti();
			break;
			default:
				break;
		}
	}
}

int Scene()
{
	int c;
	while((c=MagazineMenu())!= 3)
	{
		switch(c)
		{
			case 1 : 
			Opt01_Direction();
			break;
			case 2 : 
			Opt02_Direction();
			break;
			default:
				break;
		}
	}
}

void RandomVariations(int _RandomVariationsType)
{
	switch(_RandomVariationsType)
	{
		case DICE:
		{
			int i;
			for(i =1;i<=10;i++ )
				printf("%2d:%d\n",i,rand()%6+1);
			
		}
		break;
		case DUPLICATION:
		{
			printf("hello");
			int i;
			for(i =1; i <= 6; i++)
				printf("%2d:%d\n",rand()%45+1);
		}
		break;
		case WITHOUT_DUPLICATION:
		{
			int i, j, lotto[6];
			for(i = 0; i <= 5; i++)
			{
				lotto[i] = rand()%45+1;
				for(j = 0; j < i; j++)
				{
					if(lotto[i] == lotto[j])
					{
						i--;
						break;
					}
				}
			}
			for(i = 0; i <= 5; i++)
				printf("%2d\n", lotto[i]);
		}
		break;
		case SORTING_WITHOUT_DUPLICATION:
		{
			int i,j,lotto[6];
			for(i = 0; i <= 5; i++)
			{
				lotto[i] = rand()%45 + 1;
				for(j = 0; j < i; j++)
				{
					if(lotto[i] == lotto[j])
					{
						i--;
						break;
					}
				}
			}
			/*
			for(int i = 0; i < sizeof(lotto)/sizeof(int); i++)
			{
				printf("%d ",lotto[i]);
			}*/
			SortArry(lotto,sizeof(lotto)/sizeof(int));
		}
		break;
		default:
		{
			printf("Error::IndexOutOfRange");
		}
		break;
	}
}
void VariableArgument()
{
	printf("sum = %lf\n", sum(2,10.5, 20.23));
	printf("sum = %lf\n", sum(5, 10.3, 245.67, 0.51, 198345.764));
} 
/*
* END
*/

void Engine()
{
	srand(time(NULL));
	bool exit = false;
	while(exit == false)
	{
		int i = -1;
		printf("메뉴\n1.커서의 위치 제어\n2.3단출력\n3.화면 지우기\n4.버퍼 비우기\n");
		printf("5.아스키코드와 확장코드\n6.화살표키 움직이기\n7.사각형 그리기\n");
		printf("8.사각형 그리기 확장\n9.메뉴 그리기\n10.메뉴 그리기 2\n11.랜덤함수 예제\n12.가변인수 에제\n13.나가기\n선택:: ");
		//SELECT ONCE
		scanf("%d", &i);
		system("cls");
		
		switch(i)
		{
			case PRINT_DIVISION_TEXT:
			{
				
				PrintDivisionText();
				system("pause");
			}
			break;
			case MULTIPLY_CHART:
			{
				MultiplyChart();
				system("pause");
			}
			break;
			case DEL_CONSOLE_SCREEN:
			{
				DeletingConsoleScreen();
				system("pause");
			} 
			break;
			case EMPTY_BUFFER:
			{
				EmptyBufferTest();
				system("pause");
			}
			break;
			case ASCII_EXPAND_KEY:
			{
				ASCIIOrExpandKeyExample();
				system("pause");
			}
			break;
			case MOVE_ARROW_KEY:
			{
				MoveArrowKey();
				system("pause");
			}
			break;
			case DRAW_RECT:
			{
				DrawRectangle();
				system("pause");
			}
			break;
			case DRAW_RECT_WITH_NULL:
			{
				Vector2 vec1, vec2;
				printf("Left ::");
				scanf("%d", &vec1.m_ix);
				printf("Top ::");
				scanf("%d", &vec1.m_iy);
				printf("Right ::");
				scanf("%d", &vec2.m_ix);
				printf("Bottom ::");
				scanf("%d", &vec2.m_iy);
				
				system("cls");

				DrawRectangle(vec1, vec2);
				system("pause");	
			}
			case MENU:
			{
				Menu();
				system("pause");
			}
			break;
			case SCENE:
			{
				Scene();
				system("pause");
			}
			break;
			case RANDOM_DEVICE:
			{
				int i = -1;
				printf("Select Type\n1.Dice Random Number\n2.Random Number with duplication\n3.Random Number with non-duplication\n4.Sorted random number with non-duplication\nSelect>");
				scanf("%d", &i);
				system("cls");
				RandomVariations(i);
				system("pause");	
			}
			break;
			case VARIABLE_ARGUMENT:
			{
				VariableArgument();
				system("pause");
			}
			break;
			case END:
			{
				exit = true;
			}
			break; 
			default:
			{
				printf("ERROR::Couldn't find any of the instruction chart. Are you input integer upper than %d or lower than %d?\n",END, PRINT_DIVISION_TEXT);
				system("pause");
			}
			break;
		}
		system("cls");
	}

}
/*
변수란, 데이터를 담기 위해 할당되는 공간이다. (메모리의 주소를 대체하는 기호)
상수란, 실제 숫자  
*/



