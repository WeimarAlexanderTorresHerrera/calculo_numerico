#include<stdio.h>

int main() {

	int s = 0;
	char ch;
	FILE *entrada;
	entrada = fopen("Datos.txt", "r");
	while ((ch = fgetc(entrada)) != EOF) {
		if (ch == '\n') {
			s++;
		}
	}
	fclose(entrada);
	float d[s];
	FILE *tempData;
	tempData = fopen("Datos.txt", "r");
	for(int i = 0; i < s; i++) {
		fscanf(tempData, "%f", &d[i]);
	}
	fclose(tempData);
	int n;
	printf("Introduzca el valor de k\n");
	scanf("%i", &n);
	float r[s-(n - 1)];
	float xr[s-(n - 1)];
	for(int i = n - 1; i < s; i++) {
		float acc = 0;
		for(int j = i - (n - 1); j <= i; j++) {
			acc += d[j];
		}
		xr[i - (n - 1)] = ((float)(i + (i - (n - 1)))) / 2;
		r[i - (n - 1)] = acc/n;
	}

	char *commandsForGnuPlot[] = {"set title \"Media movil simple\"", "plot 'dataOr.txt' w l lw 2 lt 22, 'dataMe.txt' w l lw 2 lt 23"};
	FILE *gnuplotPipe = popen("gnuplot -persistent", "w");

	FILE *temp1 = fopen("dataOr.txt", "w");
	for(int i = 0; i < s; i++) {
		fprintf(temp1, "%d %f\n", i, d[i]);
	}

	FILE *temp2 = fopen("dataMe.txt", "w");
	for(int i = 0; i < s - (n - 1); i++) {
		fprintf(temp2, "%f %f\n", xr[i], r[i]);
	}

	for(int i = 0; i < 2; i++) {
		fprintf(gnuplotPipe, "%s \n", commandsForGnuPlot[i]);
	}

	return 0;

}
