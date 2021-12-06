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
- QC

**UML Diagram**

-------

![https://imgur.com/a/CwPYZCO](https://i.imgur.com/xMNeFSg.png)

**Issues**

---------

- Low Pass Filter doesn’t work with the method described in the hints. It only creates a delay. Fourier Transform would work but I am too “not good at math” to know how to code that.

**Challenges**

----------------

- Many segmentation faults that were caused by PrintMetaData() taking in a copy of the Wav object instead of a reference causing two deletions of the sample array.
- Creating a really advanced makefile made me read half of the GNU Make documentation to have a really cool makefile. Implicit rules don’t work with my makefile but I’m satisfied that it looks cool.
- Putting .cpp and .h files in a directory made for a challenge when creating the makefile.

**Application Building**

-----------------------------

`make` builds the program and the necessary directories

`make clean` cleans the root folder of the .exe and .wav files. It also cleans the objs directory of all .o files. 

**How To Use This Application**

-----------------------------------------

- Build Application
- Enter “./wavman” in Your Terminal to Run the Application
- Enter the Name of the .wav File You Wish to Edit
  - OR Type “q” to Exit the Program
- The Application will Display the File’s Metadata, and Ask You to Choose a Processing Method to Apply to Your .wav File
- Enter a Number Based on Which Processor You Would Like to Use
  - (1) Normalization:
    - This Processing Method Will Maximize the Amplitude of Your File
    - This Processing Method Will Automatically Apply to Your File and Return You to the “Choose a Processing Method” Page
  - (2) Echo:
    - This Processing Method Will Create an Echo Effect from Your File
    - This Processing Method Will Ask You to Enter a Percentage to Scale the Echo’s Volume, then it Will Ask You to Enter a Delay Value by Number of Samples, and Return You to the “Choose a Processing Method” Page
  - (3) Gain
    - This Processing Method Will Raise or Lower the Overall Amplitude of Your File
    - This Processing Method Will Ask You to Enter a Percentage to Scale the Overall Amplitude, and Return You to the “Choose a Processing Method” Page
  - (4) Low-Pass Filter
    - This Processing Method Does Not Work Properly
    - Avoid Using This Processing Method
  - (5) Compressor
    - This Processing Method Will Scale the Volume of Your .wav File by a Ratio Based on a Maximum Threshold
    - This Processing Method Will Ask You to Enter a Ratio that Will Scale Aspects of Your File that Exceed the Maximum Threshold, then it Will Ask You to Set a Maximum Threshold


