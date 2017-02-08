#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	//Called from the command line, takes either -a or -? as flags, accpets file names to write information to


	int append = 0;
	char ch;
	char in[80];
	int count;
	FILE *file1;


	while ((ch = getopt(argc, argv, "a?")) != EOF)
  		switch(ch) {
  			case 'a':
  				//handling append flag
  				append = 1;
  				break;
  			case '?':
  				//Handling help flag
  				fprintf(stdout, "\n Calls must be of the format: './ex03 -a/? filename ... < inputFile' \n\n");
  				exit(1);
  		}
  		argc -= optind;
		argv += optind;


	while (fscanf(stdin, "%79[^\n]\n", in) == 1) {
		if (argc == 0) {
			//if there is no output file, print to stdout and exit
			fprintf(stdout, "%s\n", in);
			exit(1);
		}
		if(append) {
			for (count = 0; count < argc; count++) {
			//print to standard out and append to requested files
				file1 = fopen(argv[count], "a");
				fprintf(file1, "%s\n", in);	
				fclose(file1);
				
				fprintf(stdout, "%s\n", in);
				
			}
		}
		else {
			for (count = 0; count < argc; count++) {
			//print to standard out and overwrite requested files
				FILE *temp = fopen(argv[count], "w"); 
				fprintf(temp, "%s\n", in);
				fprintf(stdout, "%s\n", in);
				fclose(temp);
			}
		}
	}
}



//Reflect:
// Figuring out how to use scanf and getopt was much harder than I originally anticipated. 
// I didn't quite connect scanf to standard in and getopt to command line arguments when I 
// was doing the reading, so figuring out what went where and in what order was a challenge. 
// Additionally, there wasn't a lot of cohesive example code in Head First C to use as an example, 
// because I had to draw from two different C programs to get all the functionality I needed. 
// There isn't much that jumps out at me to do differently next time, but I'll have a better 
// understanding of moving data around, which would speed the process dramatically.

//Compare:
// The more production quality code is very difficult to read and completely uncommented,
// but some of the major differences I could pick up on are the presence of structs in 
// the production code, more diverse error and warning checking, and the use of exit codes.
// The way they handled flags was much more sophisticated, but I couldn't really get it.