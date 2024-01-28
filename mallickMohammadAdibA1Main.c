#include "givenA1.h" 

int main(int argc, char* argv[]){
    char filename1[50];  
    char filename2[50];
    char taughtBy[NUMBER_PROFS][MAX_STR]; 
    char profsNCourses[NUMBER_PROFS][MAX_STR];
    struct profStruct profInfo [NUMBER_PROFS];
    struct courseStruct courseInfo [NUMBER_COURSES];
    char cNameFound[MAX_STR];
    char userIn[MAX_STR];

    int cNumFound;
    int choice;  
    int courseNum;
    int courseNum2;
    int level;
    int numPTeachingNLevelC;
    int t5,t6,t7,t8;

    choice = 0;

    strcpy(filename1,argv[1]);
    readCourse (filename1,courseInfo);

    strcpy(filename2, argv[2]);
    readProfAndCoursesTaught (filename2,profInfo,courseInfo);

    do{
    printf("***************************\n");
    printf("Enter a choice from the menu displayed below:\n");
    printf("4 for Task 4 - count and print all profs teaching atleast n-level courses\n");
    printf("5 for Task 5 - search for the course name from code\n");
    printf("6 for Task 6 - search for course code from name\n");
    printf("7 for Task 7 - displays profs that teach that course\n");
    printf("8 for Task 8 - average no of courses taught\n");
    scanf("%d", &choice);

    if(choice == 4){
        printf("TASK 4:\n");
        printf("n-amount of courses: ");
        scanf("%d", &level);
        numPTeachingNLevelC = nCourses(level,profInfo,profsNCourses);
        printf("Number of profs teaching n-level courses = %d\n", numPTeachingNLevelC);
    }
    else if(choice == 5){
         printf("Enter a Course Number : ");
            scanf("%d",&courseNum2);
            t5 = getCourseName(courseNum2,cNameFound,courseInfo);
            printf("%d\n",t5);
            printf("Course Name: %s\n",cNameFound);
    }
    else if(choice == 6){
       printf("search for course code from name\n");
            getchar();
            fgets(userIn,50,stdin);
            userIn[strlen(userIn)-1]='\0';
            t6 = getCourseNum (userIn, &cNumFound,courseInfo);
            printf("%d\n",t6);
            printf("Course Code: %d\n", cNumFound);
    }
    else if(choice == 7)
	{
        printf("Enter a Course Number : ");
            scanf("%d",&courseNum);
            t7 = profsTeachingCourse(courseNum,profInfo,taughtBy);
            printf("Profs that teach course code =%d\n",t7);
            for(int i=0;i<NUMBER_PROFS;i++){

                  printf("%s\n",taughtBy[i]);
            }
         }
    else if(choice == 8){
         t8 = avgNumCourses (profInfo);
            printf("%d\n",t8);
        }
    else
    {
    	printf("invalid option");
    }
    
    } while(choice > 3 && choice < 9);

}
