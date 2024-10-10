#pragma once
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "Queue.h"
/*
* DESCRIPTION
* THE HERTZ BASED ON THE REAL OCTAVE SIZE
*/
#define C2 260
#define D2 290
#define E2 330
#define F2 340
#define G2 380
#define A2 430
#define B2 490

#define B0 (int)(30.87  *3.974)
#define A0 (int)(27.50 *3.974)
#define G0 (int)(24.50 *3.974)
#define F0 (int)(21.83 *3.974)
#define E0 (int)(20.60 *3.974)
#define D0 (int)(18.35 *3.974)
#define C0 (int)(16.35*3.974)

#define C1 (int)(32.70*3.974)
#define D1 (int)(36.71*3.974)
#define E1 (int)(41.20*3.974)
#define F1 (int)(43.65*3.974)
#define G1 (int)(49.00*3.974)
#define A1 (int)(55.00*3.974)
#define B1 (int)(61.74*3.974)


#define C3 (int)(130.81*3.974)
#define D3 (int)(146.83*3.974)
#define E3 (int)(164.81*3.974)
#define F3 (int)(174.61*3.974)
#define G3 (int)(196.00*3.974)
#define A3 (int)(220.00*3.974)
#define B3 (int)(246.94*3.974)

#define C4 (int)(261.63*3.974)
#define D4 (int)(293.66*3.974)
#define E4 (int)(329.63*3.974)
#define F4 (int)(349.23*3.974)
#define G4 (int)(392.00*3.974)
#define A4 (int)(440.00*3.974)
#define B4 (int)(493.88*3.974)

#define C5 C4+C4

#define c0 C0
#define d0 D0
#define e0 E0
#define f0 F0
#define g0 G0
#define a0 A0
#define b0 B0

#define c1 C1
#define d1 D1
#define e1 E1
#define f1 F1
#define g1 G1
#define a1 A1
#define b1 B1

#define c2 C2
#define d2 D2
#define e2 E2
#define f2 F2
#define g2 G2
#define a2 A2
#define b2 B2

#define c3 C3
#define d3 D3
#define e3 E3
#define f3 F3
#define g3 G3
#define a3 A3
#define b3 B3

#define c4 C4
#define d4 D4
#define e4 E4
#define f4 F4
#define g4 G4
#define a4 A4
#define b4 B4

#define c5 C5

#define _w 4000
#define _h 2000
#define _q 1500
#define _e 1000
#define _sx 500
#define _th 250
#define _hte 175

#define _qbpm_w _w
#define _qbpm_h _h/2
#define _qbpm_q _q/4
#define _qbpm_e _e/4
#define _qbpm_sx _sx/4
#define _qbpm_th _th/4
#define _qbpm_hte _hte/4


int _sharp(int T)
{
	if (T == e0 || T == e1 || T == e2 || T == e3 || T == e4)  return T;
	else if (T == b0 || T == b1 || T == b2 || T == b3 || T == b4) return T;
	else return (int)(T * 1.05946);
}
int _flat(int T)
{
	if (T == c0 || T == c1 || T == c2 || T == c3 || T == c4 || T == c5) return T;
	else if (T == f0 || T == f1 || T == f2 || T == f3 || T == f4) return T;
	else return (int)(T / 1.05946);
}

int StringToBeats(char*);
int StringToBPM(char*);

#define MAX_LINE_SIZE 5000
#define MAX_WORD_SIZE 500
#define MAX_STRING_LENGTH_SIZE 10

Terminal DownloadNote(const char* getLink, Node* Front, Node* Rear)
{
	FILE* FL;
	char line[MAX_LINE_SIZE];
    char* token;
    char string[MAX_STRING_LENGTH_SIZE];

	FL = fopen(getLink, "r");
	if (FL == NULL) {
		printf("파일을 열 수 없습니다.\n");
        return Terminal{NULL, NULL};
	}
	while (fgets(line, MAX_LINE_SIZE , FL) != NULL)
	{
		token = strtok(line, ",\r\t\n");

		while (token != NULL)
		{
            //printf("%s", line[*wordCount]);
            strcpy(string,token);
            printf("%s\n", string);
            Rear = EnQueue(token, Rear);
            if (Front == NULL)
                Front = Rear;
            //(*wordCount)++;
            token = strtok(NULL, ",\r\t\n");
            
		}
	}

	fclose(FL);
    return Terminal{ Front, Rear };
}


void ReadNote(char* wordPointer,int wordCount)
{
	int play = 0;
    char* temp;
    strcpy(temp,wordPointer);

   
    int hello = 0;

}
int StringToBeats(char* ch)
{
	if (ch == "_w")
		return _w;
	else if (ch == "_h")
		return _h;
	else if (ch == "_q")
		return _q;
	else if (ch == "_e")
		return _e;
	else if (ch == "_sx")
		return _sx;
	else if (ch == "_th")
		return _th;
	else if (ch == "_hte")
		return _hte;
	else if (ch == "_qbpm_w")
		return _qbpm_w;
	else if (ch == "_qbpm_h")
		return _qbpm_h;
	else if (ch == "_qbpm_q")
		return _qbpm_q;
	else if (ch == "_qbpm_e")
		return _qbpm_e;
	else if (ch == "_qbpm_sx")
		return _qbpm_sx;
	else if (ch == "_qbpm_th")
		return _qbpm_th;
	else if (ch == "_qbpm_hte")
		return _qbpm_hte;
	else
		return 0;
}
int StringToBPM(char* ch)
{
    if (stricmp(ch, "c0") == 0)
        return c0;
    else if (stricmp(ch, "d0") == 0)
        return d0;
    else if (stricmp(ch, "e0") == 0)
        return e0;
    else if (stricmp(ch, "f0") == 0)
        return f0;
    else if (stricmp(ch, "g0") == 0)
        return g0;
    else if (stricmp(ch, "a0") == 0)
        return a0;
    else if (stricmp(ch, "b0") == 0)
        return b0;
    else if (stricmp(ch, "c1") == 0)
        return c1;
    else if (stricmp(ch, "d1") == 0)
        return d1;
    else if (stricmp(ch, "e1") == 0)
        return e1;
    else if (stricmp(ch, "f1") == 0)
        return f1;
    else if (stricmp(ch, "g1") == 0)
        return g1;
    else if (stricmp(ch, "a1") == 0)
        return a1;
    else if (stricmp(ch, "b1") == 0)
        return b1;
    else if (stricmp(ch, "c2") == 0)
        return c2;
    else if (stricmp(ch, "d2") == 0)
        return d2;
    else if (stricmp(ch, "e2") == 0)
        return e2;
    else if (stricmp(ch, "f2") == 0)
        return f2;
    else if (stricmp(ch, "g2") == 0)
        return g2;
    else if (stricmp(ch, "a2") == 0)
        return a2;
    else if (stricmp(ch, "b2") == 0)
        return b2;
    else if (stricmp(ch, "c3") == 0)
        return c3;
    else if (stricmp(ch, "d3") == 0)
        return d3;
    else if (stricmp(ch, "e3") == 0)
        return e3;
    else if (stricmp(ch, "f3") == 0)
        return f3;
    else if (stricmp(ch, "g3") == 0)
        return g3;
    else if (stricmp(ch, "a3") == 0)
        return a3;
    else if (stricmp(ch, "b3") == 0)
        return b3;
    else if (stricmp(ch, "c4") == 0)
        return c4;
    else if (stricmp(ch, "d4") == 0)
        return d4;
    else if (stricmp(ch, "e4") == 0)
        return e4;
    else if (stricmp(ch, "f4") == 0)
        return f4;
    else if (stricmp(ch, "g4") == 0)
        return g4;
    else if (stricmp(ch, "a4") == 0)
        return a4;
    else if (stricmp(ch, "b4") == 0)
        return b4;
    else if (stricmp(ch, "c5") == 0)
        return c5;
        // C0~B0 음계
    else if (stricmp(ch, "c0") == 0)
            return C0;
        else if (stricmp(ch, "d0#") == 0)
            return _sharp(D0);
        else if (stricmp(ch, "f0#") == 0)
            return _sharp(F0);
        else if (stricmp(ch, "g0#") == 0)
            return _sharp(G0);
        else if (stricmp(ch, "a0#") == 0)
            return _sharp(A0);
        else if (stricmp(ch, "d0!") == 0)
            return _flat(D0);
        else if (stricmp(ch, "e0!") == 0)
            return _flat(E0);
        else if (stricmp(ch, "g0!") == 0)
            return _flat(G0);
        else if (stricmp(ch, "a0!") == 0)
            return _flat(A0);
        else if (stricmp(ch, "b0!") == 0)
            return _flat(B0);

    // C1~B1 음계
        else if (stricmp(ch, "d1#") == 0)
            return _sharp(D1);
        else if (stricmp(ch, "f1#") == 0)
            return _sharp(F1);
        else if (stricmp(ch, "g1#") == 0)
            return _sharp(G1);
        else if (stricmp(ch, "a1#") == 0)
            return _sharp(A1);
        else if (stricmp(ch, "d1!") == 0)
            return _flat(D1);
        else if (stricmp(ch, "e1!") == 0)
            return _flat(E1);
        else if (stricmp(ch, "g1!") == 0)
            return _flat(G1);
        else if (stricmp(ch, "a1!") == 0)
            return _flat(A1);
        else if (stricmp(ch, "b1!") == 0)
            return _flat(B1);

    // C2~B2 음계
        else if (stricmp(ch, "d2#") == 0)
            return _sharp(D2);
        else if (stricmp(ch, "f2#") == 0)
            return _sharp(F2);
        else if (stricmp(ch, "g2#") == 0)
            return _sharp(G2);
        else if (stricmp(ch, "a2#") == 0)
            return _sharp(A2);
        else if (stricmp(ch, "d2!") == 0)
            return _flat(D2);
        else if (stricmp(ch, "e2!") == 0)
            return _flat(E2);
        else if (stricmp(ch, "g2!") == 0)
            return _flat(G2);
        else if (stricmp(ch, "a2!") == 0)
            return _flat(A2);
        else if (stricmp(ch, "b2!") == 0)
            return _flat(B2);

    // C3~B3 음계
        else if (stricmp(ch, "d3#") == 0)
            return _sharp(D3);
        else if (stricmp(ch, "f3#") == 0)
            return _sharp(F3);
        else if (stricmp(ch, "g3#") == 0)
            return _sharp(G3);
        else if (stricmp(ch, "a3#") == 0)
            return _sharp(A3);
        else if (stricmp(ch, "d3!") == 0)
            return _flat(D3);
        else if (stricmp(ch, "e3!") == 0)
            return _flat(E3);
        else if (stricmp(ch, "g3!") == 0)
            return _flat(G3);
        else if (stricmp(ch, "a3!") == 0)
            return _flat(A3);
        else if (stricmp(ch, "b3!") == 0)
            return _flat(B3);

    // C4~B4 음계
        else if (stricmp(ch, "d4#") == 0)
            return _sharp(D4);
        else if (stricmp(ch, "f4#") == 0)
            return _sharp(F4);
        else if (stricmp(ch, "g4#") == 0)
            return _sharp(G4);
        else if (stricmp(ch, "a4#") == 0)
            return _sharp(A4);
        else if (stricmp(ch, "d4!") == 0)
            return _flat(D4);
        else if (stricmp(ch, "e4!") == 0)
            return _flat(E4);
        else if (stricmp(ch, "g4!") == 0)
            return _flat(G4);
        else if (stricmp(ch, "a4!") == 0)
            return _flat(A4);
        else if (stricmp(ch, "b4!") == 0)
            return _flat(B4);
        else if (stricmp(ch, "c5#") == 0)
            return _sharp(c5);
        else
            return 0;
}
void music00()
{
    Beep(_sharp(C3), _qbpm_sx); Beep(E3, _qbpm_sx+10); Beep(_sharp(F3), _qbpm_sx);
    Beep(D2, _qbpm_sx); Beep(_sharp(E2), _qbpm_sx); Beep(_sharp(C3), _qbpm_sx);
    Beep(_sharp(G3), _qbpm_sx+10); Beep(A3, _qbpm_sx+10); Beep(_sharp(C4), _qbpm_sx);
    Beep(_sharp(C3), _qbpm_sx); Beep(_sharp(F3), _qbpm_sx); Beep(_sharp(F1), _qbpm_q); Beep(_sharp(F1), _qbpm_q);
    Beep(_sharp(C4), _qbpm_sx); Beep(_sharp(F4), _qbpm_sx); Beep(_sharp(G4), _qbpm_sx); Beep(A4, _qbpm_sx);
    Beep(_sharp(C3), _qbpm_sx); Beep(_sharp(F4), _qbpm_sx); Beep(_sharp(C3), _qbpm_sx); Beep(_sharp(G4), _qbpm_sx);
    Beep(B2, _qbpm_sx); Beep(E4, _qbpm_sx); Beep(B2, _qbpm_sx); Beep(_sharp(C4), _qbpm_sx); Beep(_sharp(C2), _qbpm_q + _qbpm_e); Beep(_sharp(C2), _qbpm_q + _qbpm_e);
    Beep(_sharp(F3), _qbpm_q + _qbpm_e); Beep(_sharp(G3), _qbpm_sx); Beep(A3, _qbpm_sx); Beep(_flat(D4), _qbpm_q + _qbpm_sx); Beep(_sharp(F3), _qbpm_q);
    Beep(F3, _qbpm_sx);
}