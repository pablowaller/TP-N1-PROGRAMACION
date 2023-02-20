#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define ESC 27

int cicloLavadoManual();
int cicloAutomaticoPinturaBase();
void delay();

int main()
{
    int opcion;

    while (opcion != 3)
    {

        printf("\nAutoPlus, menu de opciones:\n");
        printf("1) Ejecutar ciclo de lavado manual\n");
        printf("2) Ejecutar ciclo automático de pintura base\n");
        printf("3) Salir del programa\n");

        printf("\nIngrese una opción (1, 2 o 3): ");
        scanf("%d", &opcion);

        if (opcion > 3 || opcion == 0)
        {
            printf("\nOpción inexistente, vuelve a ingresar\n");
            continue;
        }

        switch (opcion)
        {
        case 1:
            cicloLavadoManual();
            break;
        case 2:
            cicloAutomaticoPinturaBase();
            break;
        case 3:
            printf("\nPrograma finalizado\n");
            break;
        }
    }
}

int cicloLavadoManual()
{

    int tiempoLavado, tiempoSecado, tiempoTotal;
    int potenciaBombaElectrica, potenciaHornoElectrico;
    char enter;

    printf("\nIngrese  el tiempo de lavado (entre 30 y 60 seg): ");
    scanf("%d", &tiempoLavado);

    printf("\nIngrese el tiempo de secado (entre 20 y 90 seg): ");
    scanf("%d", &tiempoSecado);

    while ((tiempoLavado < 30 || tiempoLavado > 60) || (tiempoSecado < 20 || tiempoSecado > 90))
    {
        printf("\nLos valores no cumplen con las condiciones establecidas\n");
        printf("\nIngrese  el tiempo de lavado (entre 30 y 60 seg): ");
        scanf("%d", &tiempoLavado);
        printf("\nIngrese el tiempo de secado (entre 20 y 90 seg): ");
        scanf("%d", &tiempoSecado);
    }

    printf("\nPresione <Enter> para iniciar el ciclo");
    scanf("%c", &enter);

    enter = getchar();

    potenciaBombaElectrica = 5 * tiempoLavado;
    potenciaHornoElectrico = 12 * tiempoSecado;
    tiempoTotal = tiempoLavado + tiempoSecado;

    if (enter == '\n')
    {

        printf("\nIniciando proceso de lavado...\n");
        delay(tiempoLavado);
        printf("\n(después de %d segundos): Lavado finalizado\n", tiempoLavado);
        printf("\nIniciando proceso de secado...\n");
        delay(tiempoSecado);
        printf("\n(después de %d segundos): Secado finalizado\n", tiempoSecado);
        printf("\nCiclo finalizado");
        printf("\nTiempo total: %d", tiempoTotal);
        printf("\nPotencia de lavado: %dW", potenciaBombaElectrica);
        printf("\nPotencia de Secado: %dW\n", potenciaHornoElectrico);
    }
}

int cicloAutomaticoPinturaBase()
{

    char enter;

    printf("Presione <Enter> para iniciar el ciclo");
    scanf("%c", &enter);

    enter = getchar();

    if (enter == '\n')
    {

        printf("\nIniciando baño decapante de la pieza...\n");
        delay(20);
        printf("\nBaño decapante finalizado...\n");
        printf("\nIniciando lavado desengrasante...\n");
        delay(35);
        printf("\nLavado desengrasante finalizado\n");
        printf("\nIniciando secado en horno...\n");
        delay(20);
        printf("\nSecado en horno finalizado\n");
        printf("\nAplicar pintura base...\n");
        delay(15);
        printf("\nPintura finalizada\n");
        printf("\nCiclo finalizado\n");
    }
}

void delay(int second)
{
    int milisec = 1000 * second;
    clock_t startTime = clock();
    char lastchar = '\0';

    printf("\n[Presionar <Escape> para interrumpir el proceso]\n");

    while (clock() < (startTime + milisec) && lastchar != ESC)
    {
        if (kbhit())
            lastchar = getch(); 
    }
    
    if (lastchar == ESC)
        printf("\nProceso interrumpido\n");
    else
        printf("\nProceso finalizado\n");
}
