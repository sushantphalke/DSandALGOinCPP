#include"mergeOp.h"

struct ret mergeFiles(FILE *fpin1, FILE *fpin2, FILE *fpout)
{
	struct ret result;
	int fLines1, fLines2;
	int mfLines1, mfLines2;
	int var1, var2;
	char temp1[15];
	char temp2[15];
	//printf("NumLines = %d\n",NumLines);
	result.tot_records=0;
	mfLines1=0; mfLines2=0;
	while(!feof(fpin1))
	{
		fscanf(fpin1,"%s\n",temp1);
		mfLines1++;
	}
	while(!feof(fpin2))
	{
		fscanf(fpin2,"%s\n",temp2);
		mfLines2++;
	}
	if(NumLines>mfLines1)
		fLines1=mfLines1;
	else
		fLines1=NumLines;
	if(NumLines>mfLines2)
		fLines2=mfLines2;
	else
		fLines2=NumLines;
	fseek(fpin1,0,SEEK_SET);
	fseek(fpin2,((fLines2)*13),SEEK_SET);
	fscanf(fpin1,"%s\n",temp1);
	fscanf(fpin2,"%s\n",temp2);
	var1=1; var2=1;
	while((var1<=fLines1) && (var2<=fLines2))
	{
		if(strcmp(temp1,temp2)<0)
		{
			fprintf(fpout,"%s\n",temp1);
			result.tot_records++;
			var1++;
			fscanf(fpin1,"%s\n",temp1);
		}
		else if(strcmp(temp1,temp2)>0)
		{
			fprintf(fpout,"%s\n",temp2);
			result.tot_records++;
			var2++;
			fseek(fpin2,((fLines2-var2)*13),SEEK_SET);
			fscanf(fpin2,"%s\n",temp2);
		}
		else
		{
			var2++;
			fseek(fpin2,((fLines2-var2)*13),SEEK_SET);
			fscanf(fpin2,"%s\n",temp2);
		}	
	}
	while(var1<=fLines1)
	{
		fprintf(fpout,"%s\n",temp1);
		result.tot_records++;
		var1++;
		fscanf(fpin1,"%s\n",temp1);
	}
	while(var2<=fLines2)
	{
		fprintf(fpout,"%s\n",temp2);
		result.tot_records++;
		var2++;
		fseek(fpin2,((fLines2-var2)*13),SEEK_SET);
		fscanf(fpin2,"%s\n",temp2);
	}
	result.success=0;
	return result;
}

