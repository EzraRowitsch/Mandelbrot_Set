This zip file contains folders Problem_1 and Problem_2.  It also contains HPC_HW2.pdf
and Figures_and_calcs.m.

The pdf contains the text answers to the questions posed in the problems as well as the figures asked for.

Figures_and_calcs.m needs to be used with MATLAB and takes the output from the scripts and .out files to create the figures
as well as calculate the areas in the mandelbrot set.

Within Problem_1 there are files  pi_num_parallel_ver2.c and pi_num_serial.c which can be compiled and ran with intel
compilers with mpi module 2017.  Files ending in .run are Slurm scripts that will run the file.  Files ending in 
.out are the output in text form.  These files are in the for pi_#_(strong or weak).  The indicates the number of 
units running the program and the strong or weak indicates whether it was using strong or weak scaling.

Within Problem_2 there are files Man_Final.c and Man_ver.c.  Man_Final.c splits the mandelbrot set into 4 domains 
about the horizontal axis while Man_ver.c splits along the vertical axis.  These files will need to be compiled
with the intel compilers with the npi 2017 module.  the S_de.run is a Slurm file for running the 4 way domain split
while the S_ver.run will run the vertically split code.  

The jpgs are files contained in the pdf but can also be viewed here.  

get_matrices.bash and get_matrices_vert.bash are scripts that need to be ran taking the .out files from running the 
code as arguments.  These will split the .out files into txt files which can be read using the Figures_and_calcs.m file.
It will also spit out times.txt and Times_vert.txt which will contain the times taken to run each process of the code. 
