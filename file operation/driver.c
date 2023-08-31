/*Name: 	driver.c
 * Created by:	Biju K Raveendran
 * Created on:	30/Aug/2023
 * Purpose:	Driver file for Lab 02
 * Arguments:	<float Number> <I/P Filename1> <I/P Filename2> <O/P Filename>
 */

#include "mergeOp.h"
/* Include all the other required header files in mergeOp.h */

int main(int argc, char *argv[])
{
	const int MAX_CLASS_STRENGTH=100;
	if(argc!=5)
	{
		printf("Wrong number of Input Arguments\n");
		printf("Format: executableName floatingPoint fileinput1 fileinput2 fileoutput\n");
		printf("Exiting.... Better luck next time\n");
		return 1;
	}
	float Num = atof(argv[1]);
	int CNum = ceilf(Num);
	if ((CNum<=0) || (CNum >=MAX_CLASS_STRENGTH))
	{
		printf("Wrong input\n");
		printf("Exiting.... Better luck next time\n");
		return 2;
	}	
	FILE *fpin1, *fpin2, *fpout;
	if((fpin1=fopen(argv[2],"r"))==NULL)
	{
		printf("%s failed to open\n",argv[2]);
		return 3;
	}
	if((fpin2=fopen(argv[3],"r"))==NULL)
	{
		printf("%s failed to open\n",argv[3]);
		return 4;
	}
	if((fpout=fopen(argv[4],"w"))==NULL)
	{
		printf("%s failed to open\n",argv[4]);
		return 4;
	}
	struct ret result;
	NumLines=CNum;
	result=mergeFiles(fpin1,fpin2,fpout);
	printf("Result: Num = %d and status = %d\n",result.tot_records,result.success);
	return 0;
}
