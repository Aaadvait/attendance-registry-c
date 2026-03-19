#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    TO DO:-
000. DONE :D
*/

// --- DECLARATION: PROGRAM CONTROL OPERATIONS
void att_reg();
void mark_att();
void view_att();
void add_remv();
void dis_misc();
void developer();

// --- DECLARATION: FILE OPERATION FUNCTIONS
void initialize();
void exit_prg();
void tmr_create(char filename[]);           // [Parameter: file_name] Creates two backup of the file, allowing it to take part in TMR
void tmr_save(char filenameinp[]);          // [Parameter: file_name] Saves the file into the two backups
int tmr_redundancy(char filenameinp[]);     // [Parameter: file_name] Runs the Redundancy program

int df_check(char date[]);                              // [Parameter: Date(YYYYMMDD)] FoundFile (exit 1) = Nothing, NotFoundFile (exit 0) = Create file + Metadata Update.
int stu_check(char stu_name[]);                         // [Parameter: Name] Returns index number, 0: Not found.
void att_mark(char date[],char attendance, int index);  // [Parameter: Date(YYYYMMDD), [P,N,A], no_stu] Marks a Date's Attendance to a Index.
void fil_cpy(char filename[], char tempfile[]);         // Copies file on the right to file on the left.
int file_check(int i);

// --- DECLARATION: MAIN PROGRAM FUNCTIONS
void indv_mark();
void batc_mark();

void stu_att();
void day_att();

void stud_add();
void stud_rem();
void stud_del();

void view_stu();
void view_del();
void view_dat();

// --- DECLARATION: OTHER FUNCTIONS
int string_to_int(char strng[]);                //Converts input string into integer value
int raise_to(int x, int y);                     //Raise Parameter 1 to 2
int date_get(char date_ptr[]);                  //Takes Data Input from user
int stud_get(char stud_ptr[]);                  //Takes Student name from user
void chUP(char *c);                             //Uppercase the string
void month_rtn(char month[], int month_index);  //Parameter 1 is converted to name of month based on its location in the year (para 2)
void clr_stdin();                               //Clears the Input Stream

int main() {

    initialize();   //Run Pre-program-file-check and TMR Check

    att_reg();      //Run Program

    exit_prg();     //Create backup

    return 0;
}

// --- DEFINITION: MENU CONTROL FUNCTIONS --- //

void att_reg(){
    char prg_ctrl_main = 0;

    while(prg_ctrl_main != '5'){
        system("cls");
        printf("---------------------\n\n");
        printf("ATTENDANCE REGISTRY: \n");
        printf("1. MARK ATTENDANCE\n");
        printf("2. VIEW ATTENDANCE\n");
        printf("3. ADD/REMOVE STUDENT\n");
        printf("4. DISPLAY FILES\n");
        printf("\n------------\n");
        printf("5. EXIT\n\n");
        printf("--> ");
        scanf("%c", &prg_ctrl_main);

        if(prg_ctrl_main >= '0' && prg_ctrl_main <= '9'){
            switch(prg_ctrl_main){
            case '1':
                mark_att();
                break;
            case '2':
                view_att();
                break;
            case '3':
                add_remv();
                break;
            case '4':
                dis_misc();
                break;
            case '9':
                developer();
                break;
            default:
                break;
            }
        }
    }
}

void mark_att(){
    char prg_ctrl_sec = '0';

    while(prg_ctrl_sec != '3'){
        system("cls");
        printf("---------------------\n\n");
        printf("MARKING ATTENDANCE:\n\n");
        printf("1. INDIVIDUAL MARK\n");
        printf("2. BATCH MARK\n");
        printf("3. GO BACK\n");
        printf("--> ");
        scanf("%c", &prg_ctrl_sec);

        if(prg_ctrl_sec >= '0' && prg_ctrl_sec <= '9'){
            switch(prg_ctrl_sec){
            case '1':
                indv_mark();
                break;
            case '2':
                batc_mark();
                break;
            default:
                break;
            }
        }
    }
}
void view_att(){
    char prg_ctrl_sec = '0';

    while(prg_ctrl_sec != '3'){
        system("cls");
        printf("---------------------\n\n");
        printf("VIEW ATTENDANCE:\n\n");
        printf("1. STUDENT ATTENDANCE\n");
        printf("2. DAY ATTENDANCE\n");
        printf("3. GO BACK\n");
        printf("--> ");
        scanf("%c", &prg_ctrl_sec);

        if(prg_ctrl_sec >= '0' && prg_ctrl_sec <= '9'){
            switch(prg_ctrl_sec){
            case '1':
                stu_att();
                break;
            case '2':
                day_att();
                break;
            default:
                break;
            }
        }
    }
}
void add_remv(){
    char prg_ctrl_sec = '0';

    while(prg_ctrl_sec != '4'){
        system("cls");
        printf("---------------------\n\n");
        printf("STUDENT OPERATIONS:\n\n");
        printf("1. ADD STUDENT\n");
        printf("2. REMOVE STUDENT\n");
        printf("3. DELETE STUDENT\n");
        printf("4. GO BACK\n");
        printf("--> ");
        scanf("%c", &prg_ctrl_sec);

        if(prg_ctrl_sec >= '0' && prg_ctrl_sec <= '9'){
            switch(prg_ctrl_sec){
            case '1':
                stud_add();
                break;
            case '2':
                stud_rem();
                break;
            case '3':
                stud_del();
            default:
                break;
            }
        }
    }
}
void dis_misc(){
    int prg_ctrl_sec = '0';

    while(prg_ctrl_sec != '4'){
        system("cls");
        printf("---------------------\n\n");
        printf("DISPLAY:\n\n");
        printf("1. STUDENT NAMES\n");
        printf("2. DELETED STUDENTS\n");
        printf("3. DATE FILES\n");
        printf("4. GO BACK\n");
        printf("--> ");
        scanf("%c", &prg_ctrl_sec);

        if(prg_ctrl_sec >= '0' && prg_ctrl_sec <= '9'){
            switch(prg_ctrl_sec){
            case '1':
                view_stu();
                break;
            case '2':
                view_del();
                break;
            case '3':
                view_dat();
                break;
            default:
                break;
            }
        }
    }
}
void developer(){
    int prg_ctrl_sec = '0';
    int buffer[64];
    char ch = '0';

    while(prg_ctrl_sec != '9'){
        system("cls");
        printf("---------------------\n\n");
        printf("DEVELOPER OPTIONS:\n\n");
        printf("1. INITIALIZE\n");
        printf("2. EXECUTE TMR\n");
        printf("3. SAVE WITHOUT EXIT\n");
        printf("9. GO BACK\n");
        printf("--> ");
        scanf("%c", &prg_ctrl_sec);

        if(prg_ctrl_sec >= '0' && prg_ctrl_sec <= '9'){
            switch(prg_ctrl_sec){
            case '1':
                initialize();
                printf("\nInitialized Successfully...");
                break;
            case '2':
                tmr_redundancy("metadata.dat");
                tmr_redundancy("student.dat");
                tmr_redundancy("exclusion.dat");
                printf("\nTMR Successful...");
                clr_stdin();
                scanf("%c", &ch);
                break;
            case '3':
                exit_prg();
                printf("\nBackup Successful...");
                clr_stdin();
                scanf("%c", &ch);
                break;
            default:
                break;
            }
        }
    }
}

// --- DEFINITION: FILE OPERATION FUNCTIONS --- //

void initialize() {

    /*
    Runs pre-program runtime checks.
    1. If core files [Metadata, Student, Exclusion] are not present, creates them in proper format.
    2. Runs Redundancy Check on all the three files
    3. Checks for date files stored in metadata, if not found, removes the entry from metadata.
    */

    printf("Program is starting...\n");
    printf("\n------------------------------\n\n");

    // TASK 1 --------------------------------------------------

    char garbage = '0';

    const char *files[] = {"metadata.dat", "student.dat", "exclusion.dat"};
    int fileCount = 3;
    for (int i = 0; i < fileCount; i++) {
        FILE *fp = fopen(files[i], "r");
        if (fp == NULL) {
            fp = fopen(files[i], "w");
            fprintf(fp, "0\n");                 //The file line count = 0
        }
        if (fp){
            fclose(fp);
        }
    }

    // TASK 2 --------------------------------------------------

    tmr_redundancy(files[0]);
    tmr_redundancy(files[1]);
    tmr_redundancy(files[2]);

    // TASK 3 --------------------------------------------------
    // The metadata is rebuilt on every run from the previous metadata.

    int iodf = 1, num_date_file = 0;
    char buffer[64], day[3], month[3], year[5];
    FILE *pMeda = fopen("metadata.dat", "r");

    fgets(buffer, sizeof(buffer), pMeda);
    num_date_file = string_to_int(buffer);      //File Line count = num_date_file
    char arr_date_file[num_date_file][13];

    int traverse = 0;
    while(fgets(buffer, sizeof(buffer), pMeda) != NULL){
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(arr_date_file[traverse], buffer);
        strcat(arr_date_file[traverse], ".dat");
        traverse++;
    }

    FILE *pTemp = fopen("temp.dat", "w");
    int removed = 0;

    for(int a = 0; a < num_date_file; a++){
        FILE *pCHECK = fopen(arr_date_file[a], "r");
        if (pCHECK == NULL){
            printf("ERROR: %s NOT FOUND", arr_date_file[a]);
            printf("  -> REMOVING FILE\n");
            removed++;
        }
        else {
            arr_date_file[a][8] = '\0';
            fprintf(pTemp, "%s\n", arr_date_file[a]);
        }
        if (pCHECK) fclose(pCHECK);
    }
    fclose(pMeda);
    fclose(pTemp);

    pTemp = fopen("temp.dat", "r");
    pMeda = fopen("metadata.dat", "w");

    num_date_file = num_date_file - removed;
    fprintf(pMeda, "%d\n", num_date_file);

    while(fgets(buffer, sizeof(buffer), pTemp) != NULL){
        buffer[strcspn(buffer, "\n")] = '\0';
        fprintf(pMeda, "%s\n", buffer);
    }

    fclose(pMeda);
    fclose(pTemp);
}

void exit_prg(){

    //Creates Backup of files before program exits.

    tmr_save("metadata.dat");
    tmr_save("student.dat");
    tmr_save("exclusion.dat");
}

void tmr_create(char filenamedemn[]){
    // Creates the files required for TMR for input filename if they dont exist. //
    // If file with backup exists, it is kept untouched. //

    char filename[128];
    strcpy(filename, filenamedemn);
    filename[strcspn(filename,".")] = '\0';

    // --- Creatiing file names --- //

    char file1[128], file2[128], file3[128];
    strcpy(file1, filename);
    strcpy(file2, filename);
    strcpy(file3, filename);
    strcat(file1, ".dat");
    strcat(file2, "_b1.dat");
    strcat(file3, "_b2.dat");


    // --- Opening Files --- //

    FILE *p1, *p2, *p3;

    p1 = fopen(file1, "r");
    if(p1 == NULL){
        return;
    }
    fclose(p1);

    p2 = fopen(file2, "r");
    if(p2 == NULL){
        p2 = fopen(file2, "w");
        fclose(p2);
        fil_cpy(file2, file1);
    }

    p3 = fopen(file3, "r");
    if(p3 == NULL){
        p3 = fopen(file3, "w");
        fclose(p3);
        fil_cpy(file3, file1);
    }

    return;
}

void tmr_save(char filenameinp[]){
    //Saves the data of the file to its backups

    tmr_create(filenameinp);    //This function makes sure the backupfiles exist to save data into

    char filename[128];
    strcpy(filename, filenameinp);
    filename[strcspn(filename,".")] = '\0';

    // --- Creatiing file names --- //

    char file1[128], file2[128], file3[128];
    strcpy(file1, filename);
    strcpy(file2, filename);
    strcpy(file3, filename);
    strcat(file1, ".dat");
    strcat(file2, "_b1.dat");
    strcat(file3, "_b2.dat");

    fil_cpy(file2, file1);
    fil_cpy(file3, file1);
}

int tmr_redundancy(char filenameinp[]){
    /*
    Runs TMR check on the input file name.
    The files are checked for TMR per line instead of per file
    Hence if a small portion of file is corrupted, it can be restored.
    */

    tmr_create(filenameinp);    //This function makes sure the backupfiles exist to properly run TMR

    char filename[128];
    strcpy(filename, filenameinp);
    filename[strcspn(filename,".")] = '\0';

    // --- Creatiing file names --- //

    char file1[128], file2[128], file3[128];
    strcpy(file1, filename);
    strcpy(file2, filename);
    strcpy(file3, filename);
    strcat(file1, ".dat");
    strcat(file2, "_b1.dat");
    strcat(file3, "_b2.dat");


    // --- Opening Files --- //

    FILE *p1, *p2, *p3, *t1, *t2, *t3;

    p1 = fopen(file1, "r");
    p2 = fopen(file2, "r");
    p3 = fopen(file3, "r");
    t1 = fopen("tmrtemp1.dat", "w");
    t2 = fopen("tmrtemp2.dat", "w");
    t3 = fopen("tmrtemp3.dat", "w");

    if(p1 == NULL || p2 == NULL || p3 == NULL)
    {
        printf("\n: TWR Error : File Cant be opened.");
        return 1;
    }

    // --- Line by Line Checking --- //

    int err_line = 0;
    int filelen = 0, lenerr_flag = 0;
    int cmp1 = 0, cmp2 = 0, cmp3 = 0;
    char buffer1[64], buffer2[64], buffer3[64];

    fgets(buffer1, sizeof(buffer1), p1);
    fgets(buffer2, sizeof(buffer2), p2);
    fgets(buffer3, sizeof(buffer3), p3);

    cmp1 = strcmp(buffer1, buffer2);
    cmp2 = strcmp(buffer1, buffer3);
    cmp3 = strcmp(buffer2, buffer3);

    if(cmp1 < 0 || cmp1 > 0) cmp1 = 1;
    if(cmp2 < 0 || cmp2 > 0) cmp2 = 1;
    if(cmp3 < 0 || cmp3 > 0) cmp3 = 1;

    //

    if(cmp1 == cmp2 && cmp2 == cmp3 && cmp1 == 1)
        {
            printf("\n: ERROR : Critical File Error.");
            fclose(p1);
            fclose(p2);
            fclose(p3);
            fclose(t1);
            fclose(t2);
            fclose(t3);

            char yes_no = '0';
            printf("\n Reset File(Y/N): %s\n(default: Y)\n-->", filename);
            scanf(" %c", &yes_no);

            if(yes_no == 'N' || yes_no == 'n'){
                return 2;
            }
            else{
                printf("\nResetting File...");
                p1 = fopen(file1, "w");
                fprintf(p1, "0\n");
                fclose(p1);
                fil_cpy(file2, file1);
                fil_cpy(file3, file1);

                return 3;
            }
        }
        else if(cmp1 == cmp2 && cmp2 == cmp3 && cmp1 == 0)
        {
            filelen = string_to_int(buffer1);
            fprintf(t1, "%s\n", buffer1);
            fprintf(t2, "%s\n", buffer1);
            fprintf(t3, "%s\n", buffer1);
        }
        else
        {
            if(cmp1 == cmp2 && cmp1 == 1)
            {
                filelen = string_to_int(buffer2);
                fprintf(t1, "%s\n", buffer2);
                fprintf(t2, "%s\n", buffer2);
                fprintf(t3, "%s\n", buffer2);
            }
            else if(cmp1 == cmp3 && cmp1 == 1)
            {
                filelen = string_to_int(buffer3);
                fprintf(t1, "%s\n", buffer3);
                fprintf(t2, "%s\n", buffer3);
                fprintf(t3, "%s\n", buffer3);
            }
            else
            {
                filelen = string_to_int(buffer1);
                fprintf(t1, "%s\n", buffer1);
                fprintf(t2, "%s\n", buffer1);
                fprintf(t3, "%s\n", buffer1);
            }
        }

    //

    for(int a = 0; a < filelen; a++)
    {
        fgets(buffer1, sizeof(buffer1), p1);
        fgets(buffer2, sizeof(buffer2), p2);
        fgets(buffer3, sizeof(buffer3), p3);

        cmp1 = strcmp(buffer1, buffer2);
        cmp2 = strcmp(buffer1, buffer3);
        cmp3 = strcmp(buffer2, buffer3);

        if(cmp1 < 0 || cmp1 > 0) cmp1 = 1;
        if(cmp2 < 0 || cmp2 > 0) cmp2 = 1;
        if(cmp3 < 0 || cmp3 > 0) cmp3 = 1;

        if(cmp1 == cmp2 && cmp2 == cmp3 && cmp1 == 1)
        {
            printf("\n: ERROR : Critical File Error.");
            fclose(p1);
            fclose(p2);
            fclose(p3);
            fclose(t1);
            fclose(t2);
            fclose(t3);

            char yes_no = '0';
            printf("\n Reset File(Y/N): %s\n(default: Y)\n-->", filename);
            scanf(" %c", &yes_no);

            if(yes_no == 'N' || yes_no == 'n'){
                return 2;
            }
            else{
                printf("\nResetting File...");
                p1 = fopen(file1, "w");
                fprintf(p1, "0\n");
                fclose(p1);
                fil_cpy(file2, file1);
                fil_cpy(file3, file1);

                return 3;
            }
        }
        else if(cmp1 == cmp2 && cmp2 == cmp3 && cmp1 == 0)
        {
            fprintf(t1, "%s", buffer1);
            fprintf(t2, "%s", buffer1);
            fprintf(t3, "%s", buffer1);
        }
        else
        {
            if(cmp1 == cmp2 && cmp1 == 1)
            {
                printf("\n: TMR : File 1 : Line %d", a);
                fprintf(t1, "%s", buffer2);
                fprintf(t2, "%s", buffer2);
                fprintf(t3, "%s", buffer2);
            }
            else if(cmp1 == cmp3 && cmp1 == 1)
            {
                printf("\n: TMR : File 2 : Line %d", a);
                fprintf(t1, "%s", buffer3);
                fprintf(t2, "%s", buffer3);
                fprintf(t3, "%s", buffer3);
            }
            else
            {
                printf("\n: TMR : File 3 : Line %d", a);
                fprintf(t1, "%s", buffer1);
                fprintf(t2, "%s", buffer1);
                fprintf(t3, "%s", buffer1);
            }
        }
    }

    fclose(p1);
    fclose(p2);
    fclose(p3);
    fclose(t1);
    fclose(t2);
    fclose(t3);

    fil_cpy(file1, "tmrtemp1.dat");
    fil_cpy(file2, "tmrtemp2.dat");
    fil_cpy(file3, "tmrtemp3.dat");

    printf("\nTMR SUCCESSFUL: %s", file1);

    return 0;
}

int df_check(char date[]){
    /*
    Date File Check Function
    This fucntion checks if the datefiles exists through 'metadata'
    If found, returns 1,
    else returns 0 and creates te date file and adds its name to the 'metadata'
    */

    char garbage = '0';
    char buffer[64];

    char filename[16] = {0};
    strcpy(filename, date);
    strcat(filename, ".dat");

    FILE *pMETA, *TEMP;
    pMETA = fopen("metadata.dat", "r");
    TEMP = fopen("temp.dat", "w");
    int found_flag = 0;
    char first_line[16];
    fgets(first_line, sizeof(first_line), pMETA);
    int date_files_no = string_to_int(first_line);  //first line refers to line count of metadata

    if(pMETA == NULL){
        printf("\nERROR: unable to open metadata.dat.\nEXITING PROGRAM\n");
        exit(1);
    }
    if(TEMP == NULL){
        printf("\nERROR: unable to create temp.dat.\nEXITING PROGRAM\n");
        exit(1);
    }

    while(fgets(buffer, sizeof(buffer), pMETA) != NULL){
        buffer[strcspn(buffer, "\n")] = '\0';
        if (!strcmp(date, buffer)){
            found_flag = 1;
        }
    }

    if (found_flag == 0){

        FILE *pDATE = fopen(filename, "w");
        if (pDATE == 0){
            printf("\nCRITICAL ERROR: Couldnt create Date File");
            return -1;
        }
        else{
            fprintf(pDATE, "0\n");
            fclose(pDATE);
        }

        fprintf(TEMP, "%d\n", (date_files_no + 1));
        fseek(pMETA, 0, SEEK_SET);                          //fseek used to avoid opening file again
        fgets(buffer, sizeof(buffer), pMETA);
        while(fgets(buffer, sizeof(buffer), pMETA) != NULL){
            fprintf(TEMP, "%s", buffer);
        }
        fprintf(TEMP, "%s\n", date);
        fclose(TEMP);
        fclose(pMETA);

        TEMP = fopen("temp.dat", "r");
        pMETA = fopen("metadata.dat", "w");
        while(fgets(buffer, sizeof(buffer), TEMP) != NULL){
            fprintf(pMETA, "%s", buffer);
        }
        fclose(TEMP);
        fclose(pMETA);

        return 0;
    }

    return 1;
}

int stu_check(char stu_name[]){
    /*
    Student Check Function.
    Checks wether the input student name exists.
    If yes, returns the line on which it exists.
    Else, Returns 0.

    First student is considered to be on line 1.
    */

    char buffer[64];
    char garbage = '\0';

    FILE *pSTU = fopen("student.dat", "r");
    char first_line[16];

    if(pSTU == NULL){
        printf("\nERROR IN FILE OPENING, EXITING PROGRAM");
        exit(1);
    }

    fgets(first_line, sizeof(first_line), pSTU);
    int students_no = string_to_int(first_line);            //students_np is the line count

    if(students_no == 0){
        fclose(pSTU);
        return (-1);
    }

    int found_flag = 0;
    int stu_count = 1;
    while(fgets(buffer, sizeof(buffer), pSTU) != NULL){
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(stu_name, buffer)){
            stu_count++;
        }
        else{
            found_flag = 1;                                 //Student Found
            break;
        }
    }

    if (found_flag == 0){
        fclose(pSTU);
        return 0;
    }                                                       //Student Not Found

    fclose(pSTU);
    return stu_count;
}

int exl_check(char stu_name[]){
    /*
    Exact replica of stu_check(), applied to "Exclusion" file
    */

    char buffer[64];
    char garbage = '\0';

    FILE *pSTU = fopen("exclusion.dat", "r");
    char first_line[16];

    if(pSTU == NULL){
        printf("\nERROR IN FILE OPENING, EXITING PROGRAM");
        exit(1);
    }

    fgets(first_line, sizeof(first_line), pSTU);
    int students_no = string_to_int(first_line);

    if(students_no == 0){
        fclose(pSTU);
        return (-1);
    }

    int found_flag = 0;
    int stu_count = 1;
    while(fgets(buffer, sizeof(buffer), pSTU) != NULL){
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(stu_name, buffer)){
            stu_count++;
        }
        else{
            found_flag = 1;
            break;
        }
    }

    if (found_flag == 0){
        fclose(pSTU);
        return 0;
    }

    fclose(pSTU);
    return stu_count;
}

void att_mark(char date[],char attendance, int index){
    /*
    Attendance Mark Function[Date file name, attendance of student, index of student in student file]

    Marks Attendance of a student at a particular date. Requires position of student in student file.

    Date files are not all upadted on each Student Add.
    However since the Attendance and Student names are connected by position, its necessary to maintain the position when required.

    This function, for a particular date, for a given attendance, at index i,
    if index < linecount of date file, replaces the attendance of the student.
    if index > linecount of date file, adds "N" attendance till the index, before marking required student's attendance.
    */

    char buffer[64];
    char garbage;

    // CONSTRUCTING FILENAME
    char filename[16] = {0};
    strcpy(filename, date);
    strcat(filename, ".dat");

    FILE *pdatefile, *temp;
    pdatefile = fopen(filename, "r");
    temp = fopen("temp.dat", "w");

    char no_att_str[8];
    fgets(no_att_str, sizeof(no_att_str), pdatefile);
    int no_att = string_to_int(no_att_str);             //Line Count of the opened date file

    // ----- START ----- //

    if(index <= no_att){
        int counter = 1;
        fprintf(temp, "%d\n", no_att);
        while(fgets(buffer, sizeof(buffer), pdatefile) != '\0'){
            buffer[strcspn(buffer, "\n")] = '\0';
            if(index == counter){
                fprintf(temp, "%c\n", attendance);
            }
            else{
                fprintf(temp, "%s\n", buffer);
            }
            counter++;
        }
    }                                                   //If for student position < line count
    else{
        int counter = 1;

        fprintf(temp, "%d\n", index);

        while(fgets(buffer, sizeof(buffer), pdatefile) != '\0'){
            buffer[strcspn(buffer, "\n")] = '\0';
            fprintf(temp, "%s\n", buffer);
        }

        for(int a = (no_att + 1); a < index; a++){
            fprintf(temp, "N\n");
        }
        fprintf(temp, "%c\n", attendance);
    }                                                   //Else for student position > line count

    fclose(pdatefile);
    fclose(temp);

    fil_cpy(filename, "temp.dat");
}

void fil_cpy(char filename[], char tempfile[]){
    //File Copy[File1, File2]
    //Copy files [File1 <- File2]

    FILE *pFile, *pTemp;
    pTemp = fopen(tempfile, "r");
    pFile = fopen(filename, "w");

    char buffer[64];

    while(fgets(buffer, sizeof(buffer), pTemp) != NULL){
            fprintf(pFile, "%s", buffer);
    }

    fclose(pFile);
    fclose(pTemp);
}

int file_check(int file_index){
    /*
    Checks wether the core files Exist or not.
    New core files i.e with line count 0 are considered to not exist.

    Core Files:
    Metadata file index = 1
    Student file index = 2
    Exclusion file index = 3
    */

    char buffer[64];
    FILE *pFILE;

    if(file_index > 0 && file_index < 4){
        switch(file_index){
        case 1:
            pFILE = fopen("metadata.dat", "r");
            if(pFILE == NULL){
                return 0;
            }
            fgets(buffer, sizeof(buffer), pFILE);
            if (string_to_int(buffer) == 0) return 0;
            else return 1;

        case 2:
            pFILE = fopen("student.dat", "r");
            if(pFILE == NULL){
                return 0;
            }
            fgets(buffer, sizeof(buffer), pFILE);
            if (string_to_int(buffer) == 0) return 0;
            else return 1;
        case 3:
            pFILE = fopen("exclusion.dat", "r");
            if(pFILE == NULL){
                return 0;
            }
            fgets(buffer, sizeof(buffer), pFILE);
            if (string_to_int(buffer) == 0) return 0;
            else return 1;
        }
    }
    else{
        printf("\n: FILE CHECK ERROR :\n");
        return 0;
    }
}

// --- DEFINITION: MAIN PROGRAM FUNCTIONS --- //

void indv_mark(){
    /*
    Individual Attendance Makrking Function.
    This function marks the individual's attendance at a particular date, if data is valid.
    Valid data requires proper date, student name to exist in student file but not in exclusion and attendace mark to be "A/P/N".
    */

    char garbage = '0';
    char buffer[64];
    while (1){
        if(!file_check(2)){
            printf("\n: NO Students in Registry.");
            break;
        }   //Edge Case: No students present in registry to mark attendance of.

        char date[16] = {0};
        if (date_get(date) == 0){
            printf("\n: ERROR: DATE is INVALID\n");
            break;
        }

        char stu_name[64];
        stud_get(stu_name);

        char attendance = 'N';
        printf("\nMark Attendance (A, P, N): ");
        scanf("%c", &attendance);
        chUP(&attendance);
        clr_stdin();

        if(attendance != 'A' && attendance != 'P' && attendance != 'N'){
            printf("\n: ERROR: DATA is INVALID\n");
            break;
        }

        df_check(date);
        int stu_index = stu_check(stu_name);
        int exl_index = exl_check(stu_name);

        if (stu_index == 0 || exl_index > 0){
            printf("\nStudent not Found.\n");
            break;
        }

        att_mark(date, attendance, stu_index);
        printf("Attendance marked.");
        break;
    }

    clr_stdin();
    scanf("%c", &garbage);
}

void batc_mark(){
    /*
    Batch Mark Function
    For a input Date, this function marks the attendance of all the students in the student file.
    For deleted students i.e students in exclusion file, there are two possibilities
    first, if their attendance is already marked, it remains.
    second, if their attendacne isnt marked, its marked as 'N'.
    */

    char garbage = '0';
    char buffer[64];

    if(!file_check(2)){
        printf("\n: NO Students in Registry.");
        clr_stdin();
        scanf("%c", &garbage);
        return;
    }   //Edge Case: No students present in registry to mark attendance of.

    char date[16] = {0};
    if (date_get(date) == 0){
        clr_stdin();
        scanf("%c", &garbage);
        return;
    }

    df_check(date);
    char filename[16] = {0};
    strcpy(filename, date);
    strcat(filename, ".dat");

    // --- BATCH MARK START --- //

    FILE *pDATE, *pSTUD, *pTEMP, *pEXLC;
    pSTUD = fopen("student.dat", "r");
    pEXLC = fopen("exclusion.dat", "r");
    pTEMP = fopen("temp.dat", "w");
    pDATE = fopen(filename, "r");
    char date_buffer[4];

    char getnosch[16] = {0};
    int getnos = 0;
    char getnoech[16] = {0};
    int getnoe = 0;
    char getnodch[16] = {0};
    int getnod = 0;

    fgets(getnosch, sizeof(getnosch), pSTUD);
    getnos = string_to_int(getnosch);
    fprintf(pTEMP, "%d\n", getnos);
    fgets(getnoech, sizeof(getnoech), pEXLC);
    getnoe = string_to_int(getnoech);
    char exlc[getnoe][64];
    fgets(getnodch, sizeof(getnodch), pDATE);
    getnod = string_to_int(getnodch);
    int date_ctr = 0, date_flag = 1;

    //CREATING EXCLUSION ARRAY AND LOGIC
    int excl_flag = 0;
    for(int a = 0; a < getnoe; a++){
        fgets(buffer, sizeof(buffer), pEXLC);
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(exlc[a], buffer);
    }

    char attendance = ' ';
    printf("\n-- -- -- -- -- -- -- --\n");
    printf("\nStudent Name\t\tAttendance (P / A / N)\n");
    while(fgets(buffer, sizeof(buffer), pSTUD) != NULL){

        if(date_ctr < getnod){
            fgets(date_buffer, sizeof(date_buffer), pDATE);
            date_ctr++;
            date_flag = 1;
        }
        else{
            date_flag = 0;
        }

        buffer[strcspn(buffer, "\n")] = '\0';
        date_buffer[strcspn(date_buffer, "\n")] = '\0';

        excl_flag = 0;
        for(int a = 0; a < getnoe; a++){
            if(strcmp(exlc[a], buffer) == 0){
                excl_flag = 1;
                break;
            }
        }
        if(excl_flag == 0){
            attendance = ' ';
            while (attendance != 'P' && attendance != 'A' && attendance != 'N'){
                if(strlen(buffer) > 15) printf("%s\t", buffer);
                else if (strlen(buffer) > 7) printf("%s\t\t", buffer);
                else printf("%s\t\t\t", buffer);
                scanf(" %c", &attendance);
                chUP(&attendance);
            }
            fprintf(pTEMP, "%c\n", attendance);
        }
        else{
            if(date_flag == 0){
                fprintf(pTEMP, "N\n");
            }
            else{
                fprintf(pTEMP, "%s\n", date_buffer);
            }
        }
    }
    fclose(pTEMP);
    fclose(pSTUD);
    fclose(pEXLC);
    fclose(pDATE);

    fil_cpy(filename, "temp.dat");
    printf("\nBatch Mark Finished.");


    clr_stdin();
    scanf("%c", &garbage);
}

void stu_att(){
    /*
    Student Attendance view
    View student attendance across the input month - year.
    */

    char garbage = '0';
    char buffer[64] = {0};

    char stu_name[64];

    if(!file_check(2)){
        printf("\n: NO Students in Registry.");
        clr_stdin();
        scanf("%c", &garbage);
        return;
    }   //Edge Case: No students present in registry to mark attendance of.

    int valid_flag = 0;

    stud_get(stu_name);

    //TAKE IN DATE
    char day[8], month[8], year[8], date[16] = {0};
    printf("\nEnter the Range(MM YYYY): ");
    scanf("%s %s", month, year);

    //CONSTRUCTING DATE
    strcat(date, year);
    strcat(date, month);

    int dy = 0, mh = 0, yr = 0;
    mh = string_to_int(month);
    yr = string_to_int(year);

    if(mh < 1 || mh > 12) {
        valid_flag = 1;
    }

    int stu_index = stu_check(stu_name);
    int exl_index = exl_check(stu_name);
    if(stu_index == 0 || exl_index > 0) {
        valid_flag = 1;
    }

    if(valid_flag == 1){
        printf("\nERROR: Invalid Values.");
        clr_stdin();
        scanf("%c", &garbage);
        return;
    }

    // --- VIEW STUDENT ATTENDANCE --- //

    char day_arr[31][3] = { "01","02","03","04","05","06","07","08","09","10",
                            "11","12","13","14","15","16","17","18","19","20",
                            "21","22","23","24","25","26","27","28","29","30","31"};
    char month_nme[16];
    month_rtn(month_nme, mh);
    char filename[16] = {0};
    int index_ctr = 0;
    int index_pre = 0;

    FILE *pDATE;

    int day_lim = 31;
    if(mh == 2){
        if((yr%4) == 0) day_lim = 29;
        else day_lim = 28;
    }
    else if(mh == 1 || mh == 3 || mh == 5 || mh == 7 || mh == 8 || mh == 10 || mh == 12) day_lim = 31;
    else day_lim = 30;

    int pre_att = 0;
    int null_att = 0;

    printf("\n-- -- -- -- -- -- -- --\n");
    printf("\nAttendence of '%s' in '%s %s'.\n", stu_name, month_nme, year);
    printf("\n-- -- -- -- -- -- -- --\n");
    printf("\nDATE\t\tATTENDENCE\n");

    for(int a = 0; a < day_lim; a++){

        //CONSTRUCT DATE FILE NAME
        strcat(date, day_arr[a]);
        strcpy(filename, date);
        strcat(filename, ".dat");
        date[strlen(date) - 2] = '\0';

        //SKIP FOR NO FILE FOUND
        pDATE = fopen(filename, "r");
        if (pDATE == NULL){
            printf("%s-%s-%s:\t     N\n", day_arr[a], month, year);
            null_att++;
            continue;
        }

        //SKIP FOR STUDENT NOT IN FILE
        fgets(buffer, sizeof(buffer), pDATE);
        index_pre = string_to_int(buffer);
        if (stu_index > index_pre){
            printf("%s-%s-%s:\t     N\n", day_arr[a], month, year);
            null_att++;
            continue;
        }

        //SKIP ALL PREVIOUS STUDENT RECORDS FROM DATE FILE AND GET TO THE REQUIRED STUDENT
        index_ctr = 1;
        while(index_ctr < (stu_index + 1)){
            fgets(buffer, sizeof(buffer), pDATE);
            index_ctr++;
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        if(strcmp(buffer, "P") == 0){
            pre_att++;
        }
        if(strcmp(buffer, "N") == 0){
            null_att++;
        }

        printf("%s-%s-%s:\t     %s\n", day_arr[a], month, year, buffer);
        fclose(pDATE);
    }

    printf("\nAttendance Percent: %0.2f", (((pre_att+0.0)/(day_lim-null_att)*100)));

    clr_stdin();
    scanf("%c", &garbage);
}

void day_att(){
    /*
    Day Attendance View Function
    Displays the attendance of the students on input date.
    */

    char garbage = '0';
    char buffer[64];

    if(!file_check(2)){
        printf("\n: NO Students in Registry.");
        clr_stdin();
        scanf("%c", &garbage);
        return;
    }   //Edge Case: No students present in registry to mark attendance of.

    char date[16] = {0};
    if (date_get(date) == 0){
        clr_stdin();
        scanf("%c", &garbage);
        return;
    }

    df_check(date);
    char filename[16] = {0};
    strcpy(filename, date);
    strcat(filename, ".dat");

    // --- DAY ATTENDANCE START --- //

    FILE *pDATE, *pSTUD, *pTEMP, *pEXLC;
    pSTUD = fopen("student.dat", "r");
    pEXLC = fopen("exclusion.dat", "r");
    pDATE = fopen(filename, "r");
    char date_buffer[4];

    int excluded = 0, students = 0, dates = 0;
    fgets(buffer, sizeof(buffer), pSTUD);
    students = string_to_int(buffer);
    fgets(buffer, sizeof(buffer), pEXLC);
    excluded = string_to_int(buffer);
    fgets(buffer, sizeof(buffer), pDATE);
    dates = string_to_int(buffer);

    //CREATING EXCLUSION NAME ARRAY
    char exlc[excluded][64];
    for(int a = 0; a < excluded; a++){
        fgets(buffer, sizeof(buffer), pEXLC);
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(exlc[a], buffer);
    }

    //DISPLAYING BATCH.

    printf("\n-- -- -- -- -- -- -- --\n");
    printf("\nStudent Name\t    Attendance\n\n");

    int date_ctr = 0;
    int excl_ctrl = 0;
    for(int a = 0; a < students; a++){
        if(date_ctr < dates){
            fgets(date_buffer, sizeof(date_buffer), pDATE);
            date_buffer[strcspn(date_buffer, "\n")] = '\0';
        }
        else{
            strcpy(date_buffer, "N");
        }

        fgets(buffer, sizeof(buffer), pSTUD);
        buffer[strcspn(buffer, "\n")] = '\0';

        excl_ctrl = 0;
        for(int b = 0; b < excluded; b++){
            if(strcmp(exlc[b], buffer) == 0){
                excl_ctrl = 1;
                break;
            }
        }

        if (excl_ctrl == 0){
            if (strlen(buffer) > 15){
                printf("%s\t%s\n", buffer, date_buffer);
            }
            else if (strlen(buffer) > 7){
                printf("%s\t\t%s\n", buffer, date_buffer);
            }
            else{
                printf("%s\t\t\t%s\n", buffer, date_buffer);
            }

        }

        date_ctr++;
    }

    fclose(pSTUD);
    fclose(pEXLC);
    fclose(pDATE);

    clr_stdin();
    scanf("%c", &garbage);
}

void stud_add(){
    /*
    Student Add function
    Adds a student to the student file.
    */

    char garbage;
    char buffer[64];

    char stu_name[64];
    stud_get(stu_name);

    int stu_index = stu_check(stu_name);
    int exl_index = exl_check(stu_name);

    FILE *pSTUD, *pTEMP;

    while (1){

        // IF STUDENT DOSENT EXIST ---
        if (stu_index != (-1)){


            // IF THE STUDENT IS DELETED USING THE EXCLUSION FILE ---
            if (exl_index != 0 && exl_index != (-1)){
                FILE *pEXCL, *pTEMPe;
                pEXCL = fopen("exclusion.dat", "r");
                pTEMPe = fopen("temp.dat", "w");

                int excl_ctr = 0;
                int excl_no = 0;
                fgets(buffer, sizeof(buffer), pEXCL);
                excl_no = string_to_int(buffer);
                excl_no--;
                fprintf(pTEMPe, "%d\n", excl_no);

                while(fgets(buffer, sizeof(buffer), pEXCL) != NULL){
                    excl_ctr++;
                    if(excl_ctr != exl_index){
                        fprintf(pTEMPe, "%s", buffer);
                    }
                }

                fclose(pEXCL);
                fclose(pTEMPe);

                fil_cpy("exclusion.dat", "temp.dat");
                printf("\nAdded Successfully: %s", stu_name);
                break;
            }


            // IF THE STUDENT ALREADY EXISTS ---
            if (stu_index != 0){
                printf("\nStudent already added.\n");
                break;
            }

            pSTUD = fopen("student.dat", "r");
            pTEMP = fopen("temp.dat", "w");

            fgets(buffer, sizeof(buffer), pSTUD);
            stu_index = string_to_int(buffer);
            stu_index++;
            fprintf(pTEMP, "%d\n", stu_index);

            while(fgets(buffer, sizeof(buffer), pSTUD) != NULL){
                buffer[strcspn(buffer, "\n")] = '\0';
                fprintf(pTEMP, "%s\n", buffer);
            }

            fprintf(pTEMP, "%s\n", stu_name);

            fclose(pSTUD);
            fclose(pTEMP);

            fil_cpy("student.dat", "temp.dat");
        }


        // IF STUDENT DOSENT EXIST AND THE FILE IS NEW ---
        else{
            pSTUD = fopen("student.dat", "w");
            fprintf(pSTUD, "1\n");
            fprintf(pSTUD, "%s\n", stu_name);
            fclose(pSTUD);
        }
        printf("\nAdded Successfully: %s", stu_name);
        break;
    }

    clr_stdin();
    scanf("%c", &garbage);
}

void stud_rem(){
    /*
    Student Remove function
    Adds the student to the exclusion file.
    */

    char garbage;
    char buffer[64];

    if(!file_check(2)){
        printf("\n: NO Students in Registry.");
        clr_stdin();
        scanf("%c", &garbage);
        return;
    }   //Edge Case: No students present in registry to mark attendance of.

    char stu_name[64];
    stud_get(stu_name);

    int stu_index = stu_check(stu_name);
    int exl_index = exl_check(stu_name);

    FILE *pEXCL, *pTEMP;

    // CASE: THE EXCLUSION FILE IS NEW ---
    if(stu_index != 0 && exl_index == (-1)){

        pEXCL = fopen("exclusion.dat", "w");
        fprintf(pEXCL, "1\n");
        fprintf(pEXCL, "%s\n", stu_name);
        fclose(pEXCL);

        printf("\nRemoved Successfully: %s", stu_name);
        clr_stdin();
        scanf("%c", &garbage);
        return;
    }

    // CASE: Student already present in exclusion file ---
    if (exl_index > 0){
        printf("\nStudent already deleted.");
        clr_stdin();
        scanf("%c", &garbage);
        return;
    }

    // CASE: Student not present in student file ---
    if (stu_index == 0){
        printf("\nStudent dosent exist.");
        clr_stdin();
        scanf("%c", &garbage);
        return;
    }

    // CASE: Normal Student Remove ---

    pEXCL = fopen("exclusion.dat", "r");
    pTEMP = fopen("temp.dat", "w");

    fgets(buffer, sizeof(buffer), pEXCL);
    exl_index = string_to_int(buffer);
    exl_index++;
    fprintf(pTEMP, "%d\n", exl_index);

    while(fgets(buffer, sizeof(buffer), pEXCL)){
        buffer[strcspn(buffer, "\n")] = '\0';
        fprintf(pTEMP, "%s\n", buffer);
    }
    fprintf(pTEMP, "%s\n", stu_name);

    fclose(pEXCL);
    fclose(pTEMP);

    fil_cpy("exclusion.dat", "temp.dat");

    printf("\nRemoved Successfully: %s", stu_name);
    clr_stdin();
    scanf("%c", &garbage);
}

void stud_del(){
    /*
    Student Delete function
    Removes the student from student file, exclusion file(if present) and his attendance across all stored dates in metadata
    */

    char garbage;
    char buffer[64];

    char stu_name[64];
    stud_get(stu_name);

    int stu_index = stu_check(stu_name);
    int exl_index = exl_check(stu_name);

    if (stu_index < 1){
        printf("\nStudent NOT Found");
    }
    else{
        FILE *pSTUD, *pEXCL, *pTEMP, *pMETA, *pDATE;
        int index = 1;
        int lst_len = 0;

        //STUDENT FILE CHANGE
        pSTUD = fopen("student.dat", "r");
        pTEMP = fopen("temp.dat", "w");

        fgets(buffer, sizeof(buffer), pSTUD);
        lst_len = string_to_int(buffer);
        lst_len--;
        fprintf(pTEMP, "%d\n", lst_len);

        while(fgets(buffer, sizeof(buffer), pSTUD) != NULL){
            buffer[strcspn(buffer, "\n")] = '\0';
            if(index == stu_index){
                index++;
            }
            else{
                fprintf(pTEMP, "%s\n", buffer);
                index++;
            }
        }

        fclose(pSTUD);
        fclose(pTEMP);

        fil_cpy("student.dat", "temp.dat");
        printf("\nDeleted Student '%s' from Main List...", stu_name);

        //EXCLUSION FILE CHANGE
        index = 1;
        if(exl_index > 0){
            pEXCL = fopen("exclusion.dat", "r");
            pTEMP = fopen("temp.dat", "w");

            fgets(buffer, sizeof(buffer), pEXCL);
            lst_len = string_to_int(buffer);
            lst_len--;
            fprintf(pTEMP, "%d\n", lst_len);

            while(fgets(buffer, sizeof(buffer), pEXCL) != NULL){
                buffer[strcspn(buffer, "\n")] = '\0';
                if(index == exl_index){
                    index++;
                }
                else{
                    fprintf(pTEMP, "%s\n", buffer);
                    index++;
                }
            }

            fclose(pEXCL);
            fclose(pTEMP);

            fil_cpy("exclusion.dat", "temp.dat");
            printf("\nDeleted Student '%s' from Excluded List...", stu_name);
        }

        pMETA = fopen("metadata.dat", "r");

        fgets(buffer, sizeof(buffer), pMETA);
        lst_len = string_to_int(buffer);

        char filenames[lst_len][16];

        for(int a = 0; a < lst_len; a++){
            fgets(buffer, sizeof(buffer), pMETA);
            buffer[strcspn(buffer, "\n")] = '\0';
            strcat(buffer, ".dat");
            strcpy(filenames[a], buffer);
        }
        fclose(pMETA);

        int loop_ctrl = lst_len;
        for(int a = 0; a < loop_ctrl; a++){
            pDATE = fopen(filenames[a], "r");
            pTEMP = fopen("temp.dat", "w");

            fgets(buffer, sizeof(buffer), pDATE);
            lst_len = string_to_int(buffer);

            if(stu_index > lst_len){
                fclose(pDATE);
                fclose(pTEMP);
                continue;
            }

            lst_len--;
            fprintf(pTEMP, "%d\n", lst_len);
            lst_len++;

            for(int b = 0; b < lst_len; b++){
                fgets(buffer, sizeof(buffer), pDATE);
                buffer[strcspn(buffer, "\n")] = '\0';
                if((b+1) == stu_index){
                    continue;
                }
                fprintf(pTEMP, "%s\n", buffer);
            }

            fclose(pDATE);
            fclose(pTEMP);

            fil_cpy(filenames[a], "temp.dat");
            printf("\nDeleted Student '%s' from File(YYYYMMDD) : %s", stu_name, filenames[a]);
        }

        printf("\n\nSuccessfully Deleted Student: %s", stu_name);
    }


    clr_stdin();
    scanf("%c", &garbage);
}

void view_stu(){
    /*
    View Student File
    */

    char garbage;
    char buffer[64];

    printf("\nSTUDENT LIST: \n");

    FILE *pFile = fopen("student.dat", "r");
    fgets(buffer, sizeof(buffer), pFile);

    printf("\n Length of list: %s\n List:\n", buffer);
    int cntr = 1;
    while(fgets(buffer, sizeof(buffer), pFile) != NULL){
        buffer[strcspn(buffer, "\n")] = '\0';
        printf("%3d. %s\n", cntr, buffer);
        cntr++;
    }

    fclose(pFile);
    clr_stdin();
    scanf("%c", &garbage);
}

void view_del(){
    /*
    View Exclusion File
    */

    char garbage;
    char buffer[64];

    printf("\nDELETED STUDENT LIST: \n");

    FILE *pFile = fopen("exclusion.dat", "r");
    fgets(buffer, sizeof(buffer), pFile);

    printf("\n Length of list: %s\n List:\n", buffer);
    int cntr = 1;
    while(fgets(buffer, sizeof(buffer), pFile) != NULL){
        buffer[strcspn(buffer, "\n")] = '\0';
        printf("%3d. %s\n", cntr, buffer);
        cntr++;
    }

    fclose(pFile);
    clr_stdin();
    scanf("%c", &garbage);
}

void view_dat(){
    /*
    View Metadata File
    */

    char garbage;
    char buffer[64];

    printf("\nDATE FILE LIST: \n");

    FILE *pFile = fopen("metadata.dat", "r");
    fgets(buffer, sizeof(buffer), pFile);

    printf("\n Length of list: %s\n List:\n", buffer);
    int cntr = 1;
    while(fgets(buffer, sizeof(buffer), pFile) != NULL){
        buffer[strcspn(buffer, "\n")] = '\0';
        printf("%3d. %s\n", cntr, buffer);
        cntr++;
    }

    fclose(pFile);
    clr_stdin();
    scanf("%c", &garbage);
}

// --- DEFINITION: OTHER FUNCTIONS ---

int string_to_int(char strng[]){
    //Converts String into Integer

    int number = 0;
    strng[strcspn(strng, "\n")] = '\0';
    int strnglen = (strlen(strng));

    int b = (strnglen - 1);
    for(int a = 0; a < strnglen; a++){
        number = number + (strng[a] - '0') * raise_to(10, b);
        b--;
    }
    return number;
}

int raise_to(int x, int y){
    //Raises x to y

    if(y==0) return 1;
    return (x * raise_to(x, y-1));
}

int date_get(char date_ptr[]){
    /*
    Date Get Function
    Takes input date from user and validates it.
    In case of invalid input, returns 0, else returns 1

    Input Parameter is replaced by valid input date string in YYYYMMDD format.
    */

    int rv = 1;
    char garbage = '0';

    //TAKE IN DATE
    char day[8], month[8], year[8], date[16] = {0};
    printf("\nEnter the Date(DD MM YYYY): ");
    scanf("%s %s %s", day, month, year);

    //CONSTRUCTING DATE
    strcat(date, year);
    strcat(date, month);
    strcat(date, day);

    int dy = 0, mh = 0, yr = 0;
    dy = string_to_int(day);
    mh = string_to_int(month);
    yr = string_to_int(year);


    if(mh < 1 || mh > 12){
        rv = 0;
    }
    else{
        if(mh == 2){
            if((yr % 4) == 0){
                if (dy < 1 || dy > 29){
                    rv = 0;
                }
            }
            else{
                if (dy < 1 || dy > 28){
                    rv = 0;
                }
            }
        }
        else if(mh == 1 || mh == 3 || mh == 5 || mh == 7 || mh == 8 || mh == 10 || mh == 12){
            if(dy < 1 || dy > 31){
                rv =0;
            }
        }
        else{
            if (dy < 1 || dy > 30){
                rv = 0;
            }
        }
    }

    if (strcspn(date, "\0") > 8 || rv == 0){
        printf("Invalid Date: ");
        printf("%d %s", strcspn(date, "\0"), date);
        scanf("%c", &garbage);
        return 0;
    }

    strcpy(date_ptr, date);

    return rv;
}

int stud_get(char stud_ptr[]){
    //Takes Input Student name and replaces input parameter with it.

    clr_stdin();
    char stu_name[64];
    printf("\nEnter the Student name: ");
    fgets(stu_name, sizeof(stu_name), stdin);
    stu_name[strcspn(stu_name, "\n")] = '\0';
    strcpy(stud_ptr, stu_name);
    return 0;
}

void chUP(char *c){
    //Raises character to capital
    if (*c > 96 && *c < 123){
        *c = *c - 32;
    }
}

void month_rtn(char month[], int month_index){
    //Input Parameter replaced by Month name string, based on month index(1 - 12)

    char mnthstr[16];

    switch(month_index){
    case 1:
        strcpy(mnthstr, "January");
        break;
    case 2:
        strcpy(mnthstr, "February");
        break;
    case 3:
        strcpy(mnthstr, "March");
        break;
    case 4:
        strcpy(mnthstr, "April");
        break;
    case 5:
        strcpy(mnthstr, "May");
        break;
    case 6:
        strcpy(mnthstr, "June");
        break;
    case 7:
        strcpy(mnthstr, "July");
        break;
    case 8:
        strcpy(mnthstr, "August");
        break;
    case 9:
        strcpy(mnthstr, "September");
        break;
    case 10:
        strcpy(mnthstr, "October");
        break;
    case 11:
        strcpy(mnthstr, "November");
        break;
    case 12:
        strcpy(mnthstr, "December");
        break;
    default:
        strcpy(mnthstr, "ERROR");
        break;
    }

    strcpy(month, mnthstr);
}

void clr_stdin(){
    //Clears the stdin

    char garbage = '0';
    while ((garbage = getchar()) != '\n' && garbage != EOF) {}
}
