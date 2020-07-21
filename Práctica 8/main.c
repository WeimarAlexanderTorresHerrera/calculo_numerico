#include <stdio.h>

long incrementarCon(long con) {
  long dia = con / 10000000000;
  long mes = (con / 100000000) % 100;
  long anio = (con / 10000) % 10000;
  long hora = (con / 100) % 100;
  long minuto = con % 100;
  //31
  if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
    if(mes == 12 && dia == 31 && hora == 23 && minuto == 59) {
      con -= 301100002359;
      con += 10000;
    } else if(dia == 31 && hora == 23 && minuto == 59) {
      con -= 300000002359;
      con += 100000000;
    } else if(hora == 23 && minuto == 59) {
      con -= 2359;
      con += 10000000000;
    } else if(minuto == 59) {
      con -= 59;
      con += 100;
    } else {
      con++;
    }
  //30
  } else if(mes == 4 || mes == 6 || mes == 9 || mes == 11) {
    if(dia == 30 && hora == 23 && minuto == 59) {
      con -= 290000002359;
      con += 100000000;
    } else if(hora == 23 && minuto == 59) {
      con -= 2359;
      con += 10000000000;
    } else if(minuto == 59) {
      con -= 59;
      con += 100;
    } else {
      con++;
    }
  //29-28
  } else {
    if(((anio % 4 == 0) && !(anio % 100 == 0)) || (anio % 400 == 0)) {
      if(dia == 29 && hora == 23 && minuto == 59) {
        con -= 280000002359;
        con += 100000000;
      } else if(hora == 23 && minuto == 59) {
        con -= 2359;
        con += 10000000000;
      } else if(minuto == 59) {
        con -= 59;
        con += 100;
      } else {
        con++;
      }
    } else {
      if(dia == 28 && hora == 23 && minuto == 59) {
        con -= 270000002359;
        con += 100000000;
      } else if(hora == 23 && minuto == 59) {
        con -= 2359;
        con += 10000000000;
      } else if(minuto == 59) {
        con -= 59;
        con += 100;
      } else {
        con++;
      }
    }
  }

  return con;

}

int main() {

  int s = 0;
  char ch;
	FILE *entrada;
	entrada = fopen("fechas.txt", "r");
	while ((ch = fgetc(entrada)) != EOF) {
		if (ch == '\n') {
			s++;
		}
	}
	fclose(entrada);

  FILE *tempData;
  tempData = fopen("fechas.txt", "r");
  FILE *temp1 = fopen("fechasCompletas.txt", "w");
  long var;
  fscanf(tempData, "%ld", &var);
  long con = var;
  for(int i = 0; i < s; i++) {
    if(con == var) {
      fprintf(temp1, "%ld\n", con);
      con = incrementarCon(con);
    } else {
      while (con != var) {
        fprintf(temp1, "%ld\n", con);
        con = incrementarCon(con);
      }
      fprintf(temp1, "%ld\n", con);
      con = incrementarCon(con);
    }
    fscanf(tempData, "%ld", &var);
  }

  return 0;
}
