
#ifndef NOTES_H
#define NOTES_H

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "notes.h"

class Notes {
	public:
		Notes();
        ~Notes();
		void notePWM(int note);
		void offNote();
		void playNote(int note, double temps);
};


const uint8_t // note latine = fréquence // note midi
    La1 = 110, //45
    LaD1 = 116.541, //46
    Si1 = 123.471, //47
    Do2 = 130.813,//48
    DoD2 = 138.591,//49
    Re2 = 146.832,//50
    ReD2 = 155.563,//51
    Mi2 = 164.814,//52
    Fa2 = 174.614,//53
    FaD2 = 184.997,//54
    Sol2 = 195.998,//55
    SolD2 = 207.652,//56
    La2 = 220,//57
    LaD2 = 233.082,//58
    Si2 = 246.942,  //59
    Do3 = 261.626, //60
    DoD3 = 277.183, //61
    Re3 = 293.665, //62
    ReD3 = 311.127, //63
    Mi3 = 329.628, //64
    Fa3 = 349.228, //65
    FaD3 = 369.994, //66
    Sol3 = 391.995, //67
    SolD3 = 415.305, //68
    La3 = 440, //69
    LaD3 = 466.164, //70
    Si3 = 493.883, //71
    Do4 = 523.251, //72
    DoD4 = 554.365, //73
    Re4 = 587.33, //74
    ReD4 = 622.254, //75
    Mi4 = 659.255, //76
    Fa4 = 698.456, //77
    FaD4 = 739.989, //78
    Sol4 = 783.991, //79
    SolD4 = 830.609, //80
    La4 = 880; //81

const double active[] = // en ms
{
	4.545, 
    4.290, 
    4.050, 
    3.822,
	3.608, 
    3.405, 
    3.214, 
    3.034,
	2.863, 
    2.703, 
    2.551, 
    2.408,
	2.273, 
    2.145, 
    2.025, 
    1.911,
	1.804, 
    1.703, 
    1.607, 
    1.517,
	1.432, 
    1.351, 
    1.276, 
    1.204,
	1.136, 
    1.073, 
    1.012, 
    0.956,
	0.902, 
    0.851, 
    0.804, 
    0.758,
	0.716, 
    0.676, 
    0.638, 
    0.602, 
    0.568
};
const double period[] = // en ms
{
	9.09, 
    8.58, 
    8.10, 
    7.64, 
    7.22, 
    6.81, 
    6.43, 
    6.07,
	5.73, 
    5.41, 
    5.10, 
    4.82, 
    4.55, 
    4.29,
	4.06, 
    3.82, 
    3.61, 
    3.41, 
    3.21, 
    3.03,
	2.86, 
    2.70, 
    2.55, 
    2.41, 
    2.27, 
    2.15,
	2.02, 
    1.91,
    1.80, 
    1.70, 
    1.61, 
    1.52,
	1.43, 
    1.35, 
    1.28, 
    1.20, 
    1.14
};

#endif