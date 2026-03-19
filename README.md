# attendance-registry-c<br>
CLI-based attendance registry system built in C

This was originally supposed to be a basic CLI-based attendance registry mini-project done using simple file handling, before it evolved into its current form.<br>
At present, its running on a small data storage system using files, with basic error correction integrated into it.

Currently it contains :-

01. Initialization of program, to ensure the files and the system is in order before the registry runs. <br>
    ref: initialize()

02. TMR Redundancy as fault tolerance<br>
    ref: tmr_create(), tmr_save(), tmr_redundancy(), exit_prg()

03. Date file checking system using a seprate file, metadata<br>
    ref: df_check()

04. Two Deletion types<br>
    One delete adds the name to the exclusion list.<br>
    Other deletes the name from the student list, as well as removes the attendance from each date file.<br>
    ref: stu_rem(), stu_del()

05. A basic attendance registry to store the student's attendance<br>
    ref: MAIN PROGRAM FUNCTIONS


FILE STRUCTURE:<br>
Each file stores the line count of the file on the very first line.

There are 3 core files:<br>
a. metadata.dat<br>
b. student.dat<br>
c. exclusino.dat

Date files to store a day's attendance are created as per requirement.<br>
Date file names are stored in YYYYMMDD.dat format in metadata.

NOTE:<br>
Example Files can be used by copying them from example folder to folder where main_win.exe is stored.
