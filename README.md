# The Wave File Processor

## **Challenge Level Project**

**Jann Arellano:**

- Processor
- Doxygen

**Andrew Kalb:**

- Wav/File IO
- Debugging

**Alec Redera:**

- UI
- Documentation
- Quality Checker

**UML Diagram**

-------

![https://cdn.discordapp.com/attachments/903063902697439242/916590326704136192/Screen_Shot_2021-12-03_at_11.22.11_PM.png](https://cdn.discordapp.com/attachments/903063902697439242/916590326704136192/Screen_Shot_2021-12-03_at_11.22.11_PM.png)

**Current Issues**

---------

- Low Pass Filter doesn’t work with the method described in the hints/discord. It only creates a delay. However, Jann thinks that coding a Fourier's Transform would work, and separate the high frequencies.
- The CreateFile function in Wav doesn't work quite properly. The intent was to have the function return false if the filename entered was already the name of a file, but instead it just writes over that filename and essentially always returns true.
- When generating the docs, having "Challenge Level" at the top where the rubric states it should be generates weird HTML that is not recognized. It says `<strong></strong>` which should not be there given our README.md format. Fixing it seems to be almost impossible other than removing it. That or I (Jann) just haven't found the correct combination of syntax to make it so that it isn't strong anymore.

**Past Challenges**

----------------

- Many segmentation faults were caused by our PrintMetaData() method taking in a copy of the Wav object instead of a reference, which therefore copied a pointer which was deleted when the function went out of scope, causing a double delete of the sample array later.
- There was some difficulties attempting to convert the raw data from the wav file to usable and proper types (shorts and unsigned chars). I (Andrew) was forced to use some arguably "dangerous" direct memory manipulation to forcefully set two bytes into a short via reinterpret casts and other safer casts.
- The segmentation faults we experienced during runtime were extremely hard to debug, especially in Visual Studio Code. I (Andrew) have more experience with Visual Studio Community, so throwing all the files into community and then using the debugger I'm familiar with and actually viewing memory and stepping through code made the errors go away much quicker. Debugging in VSC consisted of us commenting out most of our code trying to isolate the problem, but after I moved it into Visual Studio Community, it gave me explicit errors like vector out of range instead of just "segmentation fault", which allowed me to make efficient progress on fixing our code.
- Creating a really advanced makefile made Jann read half of the GNU Make documentation to have a really cool makefile. However, implicit rules don’t work with the makefile sadly.
- Putting .cpp and .h files in a directory/folder made for a challenge when creating the makefile.

**Application Building**

-----------------------------

`make` builds the program and the necessary directories.

`make clean` cleans the root folder of the .exe and .wav files. It also cleans the objs directory of all .o files. 

**How To Use This Application**

-----------------------------------------

- Build the Application.
- Enter “./wavman” in your terminal to run the application.
- Enter the Name of the .wav file that you wish to edit.
  - OR Type “q” to Exit the program.
- The Application will display the file’s Metadata, and ask you to choose a processing method to apply to your .wav file.
- Enter a Number based on which Processor you would like to use.
  - (1) Normalization:
    - This processing method will Maximize the Amplitude of your file.
    - This processing method will automatically apply to your file and return you to the “Choose a Processing Method” page.
  - (2) Echo:
    - This processing method will create an Echo effect from your file.
    - This processing method will ask you to enter a Percentage to scale the Echo’s Volume, then it will ask you to enter a Delay Value by number of samples, and return you to the “Choose a Processing Method” page.
  - (3) Gain:
    - This processing method will raise or lower the Overall Amplitude of your file.
    - This processing method will ask you to enter a Percentage to scale the Overall Amplitude, and return you to the “Choose a Processing Method” page.
  - (4) Low-Pass Filter:
    - This processing method does not currently work.
    - Avoid using this processing method.
  - (5) Compression:
    - This processing method will scale the Volume of your .wav file by a Ratio based on a Maximum Threshold.
    - This processing method will ask you to enter a Ratio that will scale aspects of your file that exceed the Maximum Threshold, then it will ask you to set a Maximum Threshold.
- After the user is done using processor functions on the wav data, to see the input they need to save the file by entering 
- the number 6, and then entering the name of the file they would like to output to.