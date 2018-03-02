#include <stdio.h>
#include <math.h>
//using namespace std;

void PrintDigit(unsigned int N)
{
	printf("%d", N);
}
void PrintOut(unsigned int N)
{
	if (N >= 10)
		PrintOut(N / 10);
	PrintDigit(N % 10);
}
unsigned int IntPart(double N)
{
	return (unsigned int)N;
}
double DecPart(double N)
{
	return (N - IntPart(N));
}

//保留有效数字位数
double RoundUp(double N, int DecPlaces)
{
	int i;
	double AmountToAdd = 0.5;
	for (i = 0; i < DecPlaces; i++)
		AmountToAdd /= 10;
	return N + AmountToAdd;
}
void PrintFractionPart(double FractionPart, int DecPlaces)
{
	int i, Adigit = 0;
	for (i = 0; i < DecPlaces; i++)
	{
		FractionPart *= 10;
		Adigit = IntPart(FractionPart);
		PrintDigit(Adigit);
		FractionPart = DecPart(FractionPart);
	}
}
void PrintReal(double N, int DecPlaces)
{
	int IntegerPart = 0;
	double FractionPart = 0;
	if (N < 0)
	{
		putchar('-');
		N = -N;
	}
	N = RoundUp(N, DecPlaces);
	IntegerPart = IntPart(N); FractionPart = DecPart(N);
	PrintOut(IntegerPart); /* Using routine in text */
	if (DecPlaces > 0)
		putchar('.');
	PrintFractionPart(FractionPart, DecPlaces);
}
int main()
{
	PrintReal(12.5617, 2);
	printf("\n");
	return 0;
}
