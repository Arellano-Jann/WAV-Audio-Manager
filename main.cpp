// Created by Alec Redera

#include <iostream>
#include "Wav.h"
#include "UI.h"

int main()
{
    Wave w;
    if(w.SetFile("one_small_step.wav"))
    {
        w.AnalyzeFile();
    }
        /*
    while() {
        UI::UIStartMenu()
        UI::InputQuitMenu()
    }*/
return 0;
}