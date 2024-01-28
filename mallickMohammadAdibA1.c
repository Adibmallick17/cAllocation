#include "givenA1.h" 

FILE *openFileForReading(char fileName[MAX_STR]) { //Task 1
    // Declare a pointer to a file type, named `fp`.
    FILE *fp = fopen(fileName, "r");
    // Check if the file was successfully opened.
    if (fp == NULL){
        // If the file failed to open, print an error message indicating the file name and return `NULL`
        printf("Error opening file %s\n", fileName);
        return NULL;
    }
    // If the file was successfully opened, return the `fp` pointer.
    return fp;

}


int readCourse(char filename [MAX_STR], struct courseStruct courseInfo [NUMBER_COURSES]) { //Task 2
    // w is a counter variable for the for-loops
    int w;
    // in is a pointer to the file specified by "filename"
    FILE* in;
    // open the file for reading
    in = fopen(filename, "r");
    // check if the file was successfully opened
    if(in == NULL){
        // if not, print an error message and return -1
        printf("Could not open file %s\n", filename);
        return - 1; 
    }

    // loop through the courseInfo array to read the course names
    for (w = 0; w < NUMBER_COURSES; w++)
    {
        // use fgets to read a line of text from the file and store it in courseInfo[w].courseName
        fgets(courseInfo[w].courseName, MAX_STR, in);
        // remove the newline character from the end of the string
        if(courseInfo[w].courseName[strlen(courseInfo[w].courseName) - 1] == '\n'){
            courseInfo[w].courseName[strlen(courseInfo[w].courseName) - 1] = '\0';
        }
    }

    // loop through the courseInfo array to read the course IDs
    for (w = 0; w < NUMBER_COURSES; w++)
    {
        // use fscanf to read an integer value from the file and store it in courseInfo[w].courseID
        fscanf(in, "%d", &courseInfo[w].courseID);
    }   
    // close the file
    fclose(in); 
    // return 1 to indicate success
    return 1;
}


int readProfAndCoursesTaught (char filename[MAX_STR], struct profStruct profInfo [NUMBER_PROFS], struct courseStruct courseInfo [NUMBER_COURSES]) {
    // Open the file for reading
    FILE* in;
    in = fopen(filename, "r");
    // Check if the file was opened successfully
    if(in == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }
    // Read the professor names from the file and store them in the profInfo array
    for(int i = 0; i < NUMBER_PROFS; i++) {
        fgets(profInfo[i].profName, MAX_STR, in);
        // Remove the newline character from the professor name
        if(profInfo[i].profName[strlen(profInfo[i].profName) - 1] == '\n') {
            profInfo[i].profName[strlen(profInfo[i].profName) - 1] = '\0';
        }
    }
    
    // Read the information about which courses each professor teaches from the file
    int index;
    char buffer[NUMBER_PROFS][MAX_STR];

    for(int m =0; m<6; m++){
        // Read a line of information about which courses a professor teaches 
       fgets(buffer[m],MAX_STR,in);
       // Truncate the line of information to 9 characters
       buffer[m][9]='\0';
    }

    // Store the information about which courses each professor teaches in the profInfo array
    for(int i = 0; i < NUMBER_PROFS; i++) {
        index = 0;
        for(int j = 0; j < NUMBER_COURSES; j++) {
                    // Check if the professor teaches the course with ID 
                    if(tolower(buffer[i][j]) == 'y') {
                        // If the professor teaches the course, store its ID in the coursesTaught array
                        profInfo[i].coursesTaught[index] = courseInfo[j].courseID;
                        index++;
                    } else {
                        // If the professor does not teach the course, store -1 in the coursesTaught array
                        profInfo[i].coursesTaught[index] = -1;
                        index++;
                    }
                
            
        }
    }
    // Close the file
    fclose(in);
    // Return success
    return 1;
}


int nCourses(int n,struct profStruct profInfo [NUMBER_PROFS],char profsNCourses [NUMBER_PROFS][MAX_STR]){ //Task 4
    // a is a loop counter, p is the index of profsNCourses array
    int a,p=0;
    // s is a loop counter
    int s;
    // counterProfs and counterCourses are used to count the number of professors and courses respectively
    int counterProfs, counterCourses;
    // initialize the value of counterProfs to 0
    counterProfs = 0;

    // loop through all the professors
    for (a = 0; a < NUMBER_PROFS; a++)
    {
        // clear the content of the current professor in the profsNCourses array
        strcpy(profsNCourses[a],"");
        // initialize the value of counterCourses to 0
        counterCourses = 0;
        // loop through all the courses
        for (s = 0; s < NUMBER_COURSES; s++)
        {
            // check if the professor is teaching this course
            if(profInfo[a].coursesTaught[s] != -1){
            // if yes, increase the value of counterCourses by 1
            counterCourses++;
            }
        }
        // check if the professor is teaching at least n courses
        if(counterCourses >= n){
            // if yes, increase the value of counterProfs by 1
            counterProfs++;
            // copy the name of the professor to the profsNCourses array
            strcpy(profsNCourses[p++],profInfo[a].profName);
        }
    }
    // return the number of professors who are teaching at least n courses
    return counterProfs;
}

int getCourseName (int  courseNum, char cNameFound[MAX_STR], struct courseStruct courseInfo [NUMBER_COURSES]){ //Task 5
    // variable to store the loop counter
    int u;
    // loop through all the courses
    for (u = 0; u < NUMBER_COURSES; u++)
    {
        // if the course number is found in the courseInfo array
        if(courseNum==courseInfo[u].courseID){
            // copy the course name to cNameFound
            strcpy(cNameFound,courseInfo[u].courseName);
            // return success
            return 1;
        }
    }
    // return failure if the course number was not found
    return 0;
}

int getCourseNum (char cName [MAX_STR], int * cNumFound, struct courseStruct courseInfo [NUMBER_COURSES]){ //Task 6
    // u is the loop variable used to traverse the courseInfo array
     int u;

    for (u = 0; u < NUMBER_COURSES; u++)
    {
        // Compare the input course name with the name in the courseInfo array
        // strcmp returns 0 if two strings are equal.

        if(strcmp(courseInfo[u].courseName, cName) == 0){
            // Store the found course ID in the variable pointed by cNumFound
            *cNumFound = courseInfo[u].courseID;
            // Indicate that the course number is found
            return 1;
        }
    }
    // Return 0 if course number is not found.
    return 0;
}

int profsTeachingCourse (int courseNum, struct profStruct profInfo [NUMBER_PROFS],char taughtBy [NUMBER_PROFS][MAX_STR]) //task7
{
    //g and m are loop variables, k is the number of professors teaching the course
	int g,m,k=0;

        for (g = 0; g < NUMBER_PROFS; g++)
        {
            //clear the current element of the `taughtBy` array
           strcpy(taughtBy[k],"");
         for(m=0; m <NUMBER_COURSES; m++){
            //check if the current professor teaches the specified course
           if(profInfo[g].coursesTaught[m]==courseNum)
    	   {
            //copy the professor's name to the `taughtBy` array
    	      strcpy(taughtBy[k],profInfo[g].profName);
              //increment the counter
              k++;
    	   }
         }
        }
    //return the number of professors teaching the course
    return k;
}

float avgNumCourses(struct profStruct profInfo [NUMBER_PROFS]){ //Task 8
    int i;
    int j;
    int nuY;  
    float avg;  
    //initialize the total number of courses variable
    nuY = 0;
    for (i = 0; i < NUMBER_PROFS; i++)
    {
        for (j = 0; j < NUMBER_COURSES; j++)
        {
            //check if the current course is not equal to -1
            if(profInfo[i].coursesTaught[j] != -1 ){
                //increment the total number of courses
                nuY++;
            }
        }        
    }
    //calculate the average by dividing the total number of courses by the number of professors
    avg = (float)nuY/NUMBER_PROFS;
    //return the average
    return avg;    
}

