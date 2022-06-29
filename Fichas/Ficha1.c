#include <stdio.h>


void ex1_1 () {
	int x, y;
	x = 3; y = x+1;
	x = x*y; y = x + y;
	printf("%d %d\n", x, y);
}

void ex1_2() {
	int x, y;
	x = 0;
	printf ("%d %d\n", x, y);
}

void ex1_3() {
	char a, b, c;
	a = 'A'; b = ' '; c = '0';
	printf ("%c %d\n", a, a);
	a = a+1; c = c+2;
	printf ("%c %d %c %d\n", a, a, c, c);
	c = a + b;
	printf ("%c %d\n", c, c);
}


void ex1_4() {
	int x, y;
	x = 200; y = 100;
	x = x+y; y = x-y; x = x-y;
	printf ("%d %d\n", x, y);
}


void ex2_1_a() {
	int x, y;
	x = 3; y = 5;
	if (x > y)
	y = 6;
	printf ("%d %d\n", x, y);
}


void ex2_1_b() {
	int x, y;
	x = y = 0;
	while (x != 11) {
		x = x+1; y += x;
	}
	printf ("%d %d\n", x, y);
}

void ex2_1_c() {
	int i;
	for (i=0; (i<20) ; i++)
	if (i%2 == 0) putchar ('_');
	else putchar ('#');
}

void f (int n) {
	while (n>0) {
		if (n%2 == 0) putchar ('1');
		else putchar ('0');
		n = n/2;
	}
	putchar ('\n');
}


void ex2_1_d () {
	int i;
	for (i=0;(i<16);i++)
	f (i);
}

void ex3_1(int n) {
	int i,j;
	for(i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			putchar('#');
		}
		putchar('\n');
	}
}

void ex3_2(int n) {
	int i,j;
	for(i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			if (i%2==0) {
				if (j%2==0) putchar('#');
				else putchar('_');
			}
			else {
				if (j%2==0) putchar('_');
				else putchar('#');
			}
		}
		putchar('\n');
	}
}

void ex3_3(int n) {
	int i,j;
	for(i=0;i<n;i++) {
		for (j=0;j<i+1;j++) {
			putchar('#');
		}
		putchar('\n');
	}

	for(i=0;i<n-1;i++) {
		for (j=0;j<n-1-i;j++) {
			putchar('#');
		}
		putchar('\n');
	}
}

void ex3_3_(int n) {
	int i,j;
	for (i=0;i<n;i++) {

		for (j=0;j<n-1-i;j++) {
			putchar(' ');	
		}

		for (;j<n;j++) {
			putchar('#');
		}
		
		for (j=0;j<i;j++) {
			putchar('#');
		}

		for (;j<n-1;j++) {
			putchar(' ');
		}
	
		putchar('\n');
	}


}


void ex3_4(int raio) {
	int x,y;
  	for (y=raio;y>=(-1)*raio;y--) {
      	for (x=(-1)*raio;x<=raio;x++)
      		if ((x*x + y*y) <= raio*raio) putchar ('#');   // só escrever se (x,y) estiver dentro do circulo 
      		else putchar (' '); 
    	putchar ('\n');
    }


}



int main (int argc, char *argv[]) {
	
	printf("Ex 1.1:\n");
	ex1_1();
	printf("\nEx 1.2:\n");
	ex1_2();
	printf("\nEx 1.3:\n");
	ex1_3();
	printf("\nEx 1.4:\n");
	ex1_4();
	printf("\nEx 2.1 a):\n");
	ex2_1_a();
	printf("\nEx 2.1 b):\n");
	ex2_1_b();
	printf("\nEx 2.1 c):\n");
	ex2_1_c();
	printf("\n\nEx 2.1 d):\n");
	ex2_1_d();
	printf("\nEx 3.1:\n");
	ex3_1(5);
	printf("\nEx 3.2:\n");
	ex3_2(5);
	printf("\nEx 3.3:\n");
	ex3_3(5);
	printf("\nEx 3.3_:\n");
	ex3_3_(5);
	printf("\nEx 3.4:\n");
	ex3_4(4);

	return 0;
}



