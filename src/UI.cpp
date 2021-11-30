// Created by Alec Redera
#include "../headers/UI.h"
#include <iostream>

void UI::StartMenu() {
    output("This Program Can Load and Modify WAV Files.");
}
void UI::Input() {
    std::string name;
    std::cout << "Please Enter the Name of a WAV File, or Enter \"q\" to Exit the Program." << std::endl;
    std::cout << "Enter WAV Filename:" << std::endl;
    std::cin >> name;
    setInput(name);
}
bool UI::checkInput(){
  std::string i = lower(getInput());
  if ((i) == "q"){
    return false; // call exit(0); after in main
  }
  return true; // call setFile after
}
void UI::ExitMenu() {
    std::cout << "Goodbye!" << std::endl;
}


void UI::PrintMetaData(Wav wav) {
    std::cout << wav.GetFileName() << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << "Channels: " << wav.GetStereo() << std::endl;
    std::cout << "Sample Rate: " << wav.GetSampleRate() << std::endl;
    std::cout << "ByteRate: " << wav.GetByteRate() << std::endl;
    std::cout << "Bitdepth: " << wav.GetBitsPerSample() << std::endl;
    std::cout << "Block Align: " << wav.GetBlockAlign() << std::endl;
}


void UI::ProcessorMenu() {
    std::cout << "Pick a processor!" << std::endl;
    std::cout << "(1) Normalization" << std::endl;
    std::cout << "(2) Echo" << std::endl;
    std::cout << "(3) Gain" << std::endl;
    std::cout << "(4) Low Pass Filter" << std::endl;
    std::cout << "(5) Compression" << std::endl;
    std::cout << std::endl;
}
int UI::selectProcessor(){
    std::string selection;
    std::cout << "Enter the Number of the Processor Function You Would Like to Use." << std::endl;
    std::cout << "Or enter \"6\" to save your progress to a wav file." << std::endl;
    std::cin >> selection;
    checkProcessor(selection); 
    // since this is recursion it might not work due to making you input the number multiple times
    // if it doesn't work then try below?
    // if (!checkProcessor(selection)) selectProcessor();
    int select = std::stoi(selection);
    return select;
}
void UI::checkProcessor(std::string i){
    std::string arr[7] = {"0","1","2","3","4","5","6"};
    if (std::end(arr) == std::find(std::begin(arr), std::end(arr), i)){
        std::cout << "Invalid motherfucker." << std::endl;
        selectProcessor();
        //return false;
    }
    //return true;
}
void UI::callProcessor(){
    
}
void UI::askProcessorQuestions(int i){
    
}
std::string UI::OutputFileName() {
    std::cout << "Enter the Name of Your Output File:" << std::endl;
    std::string name;
    std::cin >> name;
    return name;
}


// Helper Functions
std::string UI::lower(std::string str){
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}
void UI::output(std::string str){
    std::cout << str << std::endl;
}

//Pseudo ~
/*
// So what i kinda want you to do is separate all of these functions into
// different functions. like how start menu and exit has it's own function
// i will be marking what you can put in a function below

//Complete
Start: Present start menu
If user selects quit, exit program
Else
  Request filename from user
  Open file specified by filename
  If file does not exist or file is not wav file
    display error message and goto start

//Incomplete
  else
    read file metadata // doable. write a function to call the getters in wav.cpp
(1) display metadata to user // ^^ conjunction with above

//Complete
    present user with processor menu // create a function with some UI for calling my code.
    If user selects processor option // this running should be it's own function ex: run(normalization()) etc.
      request output filename // the run command would do this and below
      run processor
      save file // can't do this yet. just comment where this would go
      goto Start // doable
*/