#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <iostream>
#include <time.h>
using namespace std;

void toSpanish() {
	setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
}

void printing() {
	printf("\n\n----------------------------------------------------------------------------\n\n\n");
	printf("*-*-*-*-*-*-               Modulo Administracion                -*-*-*-*-*-*\n\n\n");
	printf("----------------------------------------------------------------------------\n\n\n\n");
	printf("[1] --> Registrar Veterinario\n");
	printf("[2] --> Registrar Usuario Asistente\n");
	printf("[3] --> Atenciones por Veterinarios\n\n");
	printf("[4] --> Cerrar la aplicaci�n.\n\n");
	printf("Ingrese una opci�n: ");
}

void menu();
void rVet();
void rAsi();
void atenV();
void exit();

struct veterin {
	char apeNom[50];
	int matricula;
	int dni;
	char telefono[15];
};

struct user {
	char usrID[50];
	char password[32];
	char name[50];
};

int opc=0;
int err=0;
FILE *vets;
FILE *users;

main() {
	toSpanish();
    menu();
}

void menu() {
	system("color 0f");
	srand(time(NULL));
	do {
		system("cls");
		printing();
		err = 0;
		if(!(cin >> opc)) {
			cin.clear();
			cin.ignore(10000, '\n');
			err = 1;
			system("cls");
			printf("\n\n\n************************************************\n");
			printf("--> ERROR: Solo se permite el ingreso de numeros\n");
			printf("************************************************\n\n\n\n\n");
			system("pause");
		}
		if(err == 0) {
			if(opc == 1 || opc == 2 || opc == 3 || opc == 4 || opc == 5) {
				err = 0;
				if(opc == 1) rVet();
				if(opc == 2) rAsi();
				if(opc == 3) atenV();
				if(opc == 4) exit();
				opc = 500;
			} else {
				system("cls");
				printf("\n\n\n***********************************\n");
				printf("--> ERROR: Ingrese un numero valido\n");
				printf("***********************************\n\n\n\n\n");
				err = 1;
				system("pause");
			}
		}
	} while(err == 1);
}

void rVet() {
	system("cls");
	vets = fopen("Veterinarios.dat","a+b");
	if (vets == NULL) {
		printf ("ERROR: No se pudo abrir el archivo");
	} else {
		veterin vet;
		printf("\n\n----------------------------------------------------------------------------\n\n\n");
		printf("*-*-*-*-*-*-           Registro de nuevo Veterinario            -*-*-*-*-*-*\n\n\n");
		printf("----------------------------------------------------------------------------\n\n\n\n");
		
		printf("Ingrese apellido y nombre: ");
		_flushall();
		gets(vet.apeNom);
		printf("Ingrese la matricula: ");
		scanf("%d", &vet.matricula);
		printf("Ingrese el DNI: ");
		scanf("%d", &vet.dni); 
		printf("Ingrese el numero de telefono: ");
		_flushall();
		gets(vet.telefono);
		fwrite(&vet, sizeof(veterin), 1, vets);
	}
	fclose(vets);
	printf("\n\n");
	system("pause");
	menu();
}

void rAsi() {}

void atenV() {}

void exit() {
	system("cls");
	printf("\n\n\n\n---------------------------------------------------------------\n\n\n");
	printf("*-*-*-*-*-*-           Fin del Programa            -*-*-*-*-*-*\n\n\n");
	printf("---------------------------------------------------------------\n\n\n\n\n\n");
	system("pause");
}
