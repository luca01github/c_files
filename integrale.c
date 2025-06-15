#include <stdio.h>
#define INTERVALLI 1000

float fun(float x);
float area_trapezio(float B, float b, float h);
float area_tot(float a, float z, int interv);

int main(){
	float areaTotale = area_tot(2, 8, INTERVALLI);
	printf("Area calcolata: %.2f\n", areaTotale);
	puts("Expected: 30");
}

//Semplice funzione lineare
float fun(float x){
	return x;
}

float area_trapezio(float B, float b, float h){
	return (B+b)*h/2;
}

float area_tot(float a, float z, int interv){
	float area = 0.0;

	//L'intervallo diventa l'altezza del trapezio
	float h = (z-a) / interv;

	for(int i=0; i<interv; i++){
		float x0 = a+i*h;
		float x1 = x0+h;
		area += area_trapezio(fun(x0), fun(x1), h);
	}
	return area;
}



