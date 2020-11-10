#include <stdio.h>
#include <stdlib.h>

int main(){
  system("color 02");// Cambiamos colores
  int i, y, cd = 4; //cd = cantidad de materias.
  char *alfa = NULL, *beta[cd], Nom[30]; //Se inicializa puntero en NULL para evitar posibles errores.

//---------- Solicitamos Nombre Alumnno --------------

  printf("\nIngrese Nombre de Alumno: ");
  scanf("%50[^\n]", Nom);

//---------- Solicitamos 4 nombres de materias --------------

  for(i=0; i<cd; i++) // ESTRUCTURA CONTROL: Ciclo solicita 4 nombres de materias.
  {
    char *alfa = (char*)malloc(sizeof(char) * 50); //En cada ciclo se declara puntero para limpiarlo.
    printf("\nIngrese Nombre de materia %d: ",i+1);
    fflush(stdin); //Vaciamos bufer de entrada para que scanf lea limpio y no nos envie directo al while.
    y = scanf("%50[^\n]",alfa); //Si scanf no obtiene dato asigna a "y" valor nulo (o cero).
    
       while(y == '\0') // ESTRUCTURA CONTROL: Mientras usuario no proporcione algun caracter a scanf.
        {
            printf("\nUsted no ingreso datos. Ingrese Nombre de materia %d: ",i+1);
            fflush(stdin); //Vaciamos bufer de entrada para que scanf lea limpio y While no entre en loop infinito (solo sirve en windows).
            //getchar(); //Solicitamos un char de entrada para resetear el stdin, sirve como alternativa a fflush para Linux.
            y = scanf("%50[^\n]",alfa);
        }   

    beta[i] = alfa; // Si Wile detecto caracteres en scanf los asigna "alfa" en array "beta".
    while(getchar()!= '\n'); // ESTRUCTURA CONTROL: El programa queda en espera de un salto de linea para siguiente ciclo.
  } 

  system("cls");
//---------- Solicitamos 4 calificaciones de materias --------------

  float cali[cd];

  for(i=0; i<cd; i++) // ESTRUCTURA CONTROL: Solicitamos las 4 calificaciones
  {
    printf("\nIngrese calificacion \"%s\": ", beta[i]);
    fflush(stdin);
    y = scanf("%f", &cali[i]);  // si tipo de dato incorrecto scanf retorna 0 bytes.

        while(y == '\0' || cali[i] < 1 || cali[i] > 10)  // ESTRUCTURA CONTROL: Solicitamos datos nuevamente mientras "y" tenga 0 bytes (no fue float) o dato no esta entre 1 y 10.
        {
            printf("\nINCORRECTO: (solo numeros entre 1 al 10). Ingrese calificacion de \"%s\": ", beta[i]);
            fflush(stdin); // Vaciamos bufer para que While pueda leer scanf y no entre en loop infinito
            y = scanf("%f", &cali[i]);
        }
  }

  system("cls"); // limpia pantalla

//---------- Calculamos promedo y beca con datos de matriz --------------
  float prom = 0;
  int beca;

  for (i=0; i<cd; i++) //ESTRUCTURA CONTROL: Sumamos todas las calificaciones que contiene nuestra matriz.
  {
    prom = prom + cali[i];
  }
  
  prom = prom/cd; // Dividimos entre la cantidad de datos.

  if(prom>=9) // ESTRUCTURA CONTROL: Asignamos porcentaje de beca.
  {
    beca = 50;
  }
  else if(prom<8)
  {
    beca = 0;
  }
  else //Si >= 8 && < 9
  {
    beca = 30;
  }

//---------- Publicamos resultados --------------

  printf("\nNombre del Alumno: %s", Nom);
  printf("\n\nPromedio: %.2f", prom);
  printf("\n\nPorcentaje de Beca: %d%% \n", beca);

for ( i = 0; i < cd; i++) // ESTRUCTURA CONTROL: para extraer las calificaciones.
{
    printf("Calificacion %s: %.2f \n", beta[i], cali[i]);
}

system("pause");
return 0;
} 
