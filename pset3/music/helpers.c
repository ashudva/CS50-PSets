// Helper functions for music
#include <string.h>
#include <math.h>
#include <cs50.h>
#include "helpers.h"

int compare(char a);
// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    //converts first char into int
    int x = atoi(strtok(fraction, "/"));
    //converts second char of string into int
    int y = atoi(strtok(NULL, "/"));
    //Equation to find the duration
    int a = (x * 8) / y;
    return a;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //check for note format i.e. XY or XYZ
    if (strlen(note) == 2)
    {
        //use double as it will affect the equation
        double n = ((atoi(note + 1) - 4) * 12) + compare(note[0]);
        double f = (pow(2, n / 12)) * 440;
        //use round function
        return round(f);
    }
    //calculating frequency in case of # and b
    else if (strlen(note) == 3)
    {
        if (note[1] == '#')
        {
            double m = ((atoi(note + 2) - 4) * 12) + 1 + compare(note[0]);
            double f = (pow(2, m / 12)) * 440;
            return round(f);
        }
        else if (note[1] == 'b')
        {
            double o = ((atoi(note + 2) - 4) * 12) - 1 + compare(note[0]);
            double f = (pow(2, o / 12)) * 440;
            return round(f);
        }
    }
    return 1;
}
//Compare passed note letter and return int value for calcutation
int compare(char a)
{
    switch (a)
    {
        case ('A'):
            return 0;
        case ('B'):
            return 2;
        //return -9 as when you start counting from a to c in the same octave
        //it's -9 semitone apart and so for others
        case ('C'):
            return -9;
        case ('D'):
            return -7;
        case ('E'):
            return -5;
        case ('F'):
            return -4;
        case ('G'):
            return -2;
    }
    return 0;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    //get string returns "" when you hit enter or \n
    if (!strcmp(s, ""))
    {
        return true;
    }
    else
    {
        return false;
    }
}
