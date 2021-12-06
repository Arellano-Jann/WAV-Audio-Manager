// Created by Alec Redera
#include "../headers/UI.h"
#include <iostream>
#include <array>

/**
 * @brief Outputs the start menu text message to the console
 * 
 */
void UI::StartMenu() {
    output("This Program Can Load and Modify WAV Files.");
}
/**
 * @brief Retrieves a filename from the user andd appends ".wav" if it's not already there.
 * 
 * @return std::string the filename entered by the user
 */
std::string UI::Input() {
    std::string name;
    std::cout << "Please Enter the Name of a WAV File, or Enter \"q\" to Exit the Program." << std::endl;
    std::cout << "Enter WAV Filename:" << std::endl;
    std::cin >> name;
    if (name.find(".wav") != std::string::npos) return name;
    return name + ".wav";
    
}
/**
 * @brief Checks the input from the user to see if they are quitting
 * 
 * @param input user input
 * @return true user inputs a filename
 * @return false user inputs "q" or "Q"
 */
bool UI::checkInput(std::string input){
  //std::string i = lower(input);
  if (input == "q" || input == "Q"){
    return false; // call exit(0); after in main
  }
  return true; // call setFile after
}

/**
 * @brief Outputs the error message in case of an invalid filename
 * 
 */
void UI::InvalidFileName()
{
    std::cout << "File does not exist or is not a wav file." << std::endl;
}

/**
 * @brief Outputs the exit message to the console
 * 
 */
void UI::ExitMenu() {
    std::cout << "Goodbye!" << std::endl;
}

/**
 * @brief Prints relevant metadata to the console
 * The metadata is retrieved from the wav object.
 * @param wav a reference to the wav file to fetch the metadata
 */
void UI::PrintMetaData(const Wav& wav) {
    std::cout << "Metadata Goodness:" << std::endl;
    std::cout << wav.GetFileName() << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << "Channels: " << wav.GetStereo() << std::endl;
    std::cout << "Sample Rate: " << wav.GetSampleRate() << "hz" << std::endl;
    std::cout << "Byte Rate: " << wav.GetByteRate() << "bytes" << std::endl;
    std::cout << "Bitdepth: " << wav.GetBitsPerSample() << "bits" << std::endl;
    std::cout << "Block Align: " << wav.GetBlockAlign() << std::endl;
}

/**
 * @brief Outputs the Processor Menu to the console
 * 
 */
void UI::ProcessorMenu() {
    std::cout << "Pick a processor!" << std::endl;
    std::cout << "(1) Normalization" << std::endl;
    std::cout << "(2) Echo" << std::endl;
    std::cout << "(3) Gain" << std::endl;
    std::cout << "(4) Low Pass Filter" << std::endl;
    std::cout << "(5) Compressor" << std::endl;
    std::cout << std::endl;
}

/**
 * @brief Requests an integer selection from the user to select a processor.
 * 
 * @return int a number associated with a processor
 */
int UI::selectProcessor(){
    std::string selection;
    std::cout << "Enter the Number of the Processor Function You Would Like to Use." << std::endl;
    std::cout << "Or enter \"6\" to save your progress to a wav file." << std::endl;
    std::cin >> selection;
    if (checkProcessor(selection)){
        int select = std::stoi(selection);
        return select;
    }
    return 6;
}

/**
 * @brief Checks the previously selected input from the user to confirm it is a valid processor selection
 * 
 * @param i previous processor selection input (1-6)
 * @return true if the selected input is valid (between 1-6)
 * @return false if the selected input was invalid (not between 1-6)
 */
bool UI::checkProcessor(std::string i){
    std::string arr[6] = {"1","2","3","4","5","6"};
    // std::array<std::string, 6> arr = {"1","2","3","4","5","6"};
    if (std::end(arr) == std::find(std::begin(arr), std::end(arr), i)){
        std::cout << "You entered this wrong! Unfortunately. I'm going to tell you to save and leave for not following directions." << std::endl;
        return false;
    }
    return true;
}

/**
 * @brief Outputs questions to the user
 * 
 * @param i a picker for the questions
 */
void UI::askProcessorQuestions(int i){
    switch (i){
        case 1: output("How much is the scale in percent?");
            break;
        case 2: output("What is the delay as a whole number?");
            break;
        case 3: output("What is the ratio in terms of percentage?");
            break;
        case 4: output("What is the max value in terms of percentage?");
            break;
        case 5: output("How much do you want to destroy this frequency??!");
            break;
        case 6: output("How much do you want to hear the echo repeat?");
            break;
    }
}

/**
 * @brief Requests the name of the file the new wav data should be written to
 * 
 * @return std::string the complete output filename (includes .wav extension)
 */
std::string UI::OutputFileName() {
    std::cout << "Enter the Name of Your Output File:" << std::endl;
    std::string name;
    std::cin >> name;
    name += ".wav";
    return name;
}


// Helper Functions
/**
 * @brief Easier std::cout but in a function
 * 
 * @param str String outputted in the terminal
 */
void UI::output(std::string str){
    std::cout << str << std::endl;
}