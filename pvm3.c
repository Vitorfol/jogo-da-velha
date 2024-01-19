#include <stdio.h>

int main(){
	
	double filiais[20];
	double media; 
	int i; 
	for (i = 0; i < 20; i++) {
		scanf(" %lf", &filiais[i]);
	}
	for (i = 0; i < 20; i++) { 
		if (filiais[i] > 0) {
			printf("%d ", i);
		}
	}  // item a resolvido 
	
	double soma = 0.0;
	int fpositivas = 0;
	for (i = 1; i < 20; i++) {
		if (filiais[i] > 0) {
			soma += filiais[i];
			fpositivas++;
		}
	}
	if (fpositivas != 0) {
	media = soma / fpositivas; 
	printf("%lf\n", media); }  // item b resolvido 
	return 0; 
}
