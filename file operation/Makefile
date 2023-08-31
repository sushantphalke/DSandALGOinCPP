
m1: driver.c mergeOp1.o
	gcc -o m1 driver.c mergeOp1.o -lm
mergeOp1.o: mergeOp1.c
	gcc -c mergeOp1.c

m2: driver.c mergeOp2.o
	gcc -o m2 driver.c mergeOp2.o -lm
mergeOp2.o: mergeOp2.c
	gcc -c mergeOp2.c

clean:
	rm -f *.o foutput*.txt
