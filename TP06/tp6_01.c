#define N 10
#define M 20

int
main (void)
{
	int dim = 7;
	int vectorA[ M * N];
	int vectorB[ -10 ]; //error de compilacion
	int vectorC[ 10.0 ];  //error de compilacion
	int vectorD[dim];
	vectorC[2.5] = 'a'; //error de compilacion
	vectorB[-1] = 5;
	vectorA['0'] = 10;
	vectorC[vectorA[48]] = 5.5;
	vectorA[1000] = 0;
	vectorA[M * N] = 10;
	return 0;
}
