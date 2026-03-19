# attendance-registry-c
CLI-based attendance registry system built in C

This was originally supposed to be a basic CLI-based attendance registry done using simple file handling, before it evolved into its current form.
At present, its running on a small data storage system using files, with basic fault tolerance integrated into it.

Currently it contains :-

01. Initialization of program, to ensure the files and the system is in order before the registry runs. 
    ref: initialize()

02. TMR Redundancy as fault tolerance
    ref: tmr_create(), tmr_save(), tmr_redundancy(), exit_prg()

03. Date file checking system using a seprate file, metadata
    ref: df_check()

04. Two Deletion types
    One delete adds the name to the exclusion list.
    Other deletes the name from the student list, as well as removes the attendance from each date file.
    ref: stu_rem(), stu_del()

05. A basic attendance registry to store the student's attendance
    ref: MAIN PROGRAM FUNCTIONS


FILE STRUCTURE:
Each file stores the line count of the file on the very first line.

There are 3 core files:
a. metadata.dat
b. student.dat
c. exclusino.dat

Date files to store a day's attendance are created as per requirement.
Date file names are stored in YYYYMMDD.dat format in metadata

NOTE: 
Example Files can be used by copying them from example folder to folder where main_win.exe is stored.
