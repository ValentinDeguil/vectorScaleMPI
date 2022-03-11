# Vector scale with MPI

To compile with MPI:
```cmd
    mpicc vectorScale.c
```

To execute the program on 8 cores (for example):
```cmd
    mpirun -n 8 ./a.out
```

If you want to scale a vector of size 8 by 2.5:

```cmd
    Enter n:
    8 //press enter
    
    Enter scale :
    2.5 //press enter
    
    Enter x[0] :
    4 //press enter
    Enter x[1] :
    5 //press enter
    ...
    Enter x[7] :
    2 //press enter
    
    Result :
    10.000000
    12.500000
    ...
    5.000000
    
```