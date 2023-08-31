#ifndef MERGE_FILE_H
#define MERGE_FILE_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

extern const int MAX_CLASS_STRENGTH;
int NumLines;
//strcture for return value
struct ret
{
	int success;
	int tot_records;
};
extern struct ret mergeFiles(FILE *, FILE *, FILE *);

#endif /*MERGE_FILE_H */
