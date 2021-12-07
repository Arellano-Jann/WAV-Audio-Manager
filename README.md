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

**Past Challenges**

----------------

- Many segmentation faults were caused by our PrintMetaData() method taking in a copy of the Wav object instead of a reference, which therefore copied a pointer which was deleted when the function went out of scope, causing a double delete of the sample array later.
- There was some difficulties attempting to convert the raw data from the wav file to usable and proper types (shorts and unsigned chars). I (Andrew) was forced to use some arguably "dangerous" direct memory manipulation to forcefully set two bytes into a short via reinterpret casts and other safer casts.
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