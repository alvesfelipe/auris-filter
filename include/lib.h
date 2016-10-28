#ifndef stdlibl
#define stdlibl
#include <stdlib.h>
#endif
#ifndef iostreaml
#define iostreaml
#include <iostream>
#endif
#ifndef exceptionl
#define exceptionl
#include <exception>
#endif
#ifndef stringl
#define stringl
#include <string>
#endif
using namespace std;

string loc_patch = "../pd_files/equalizador\ 1.pd"; // localização do arquivo .pd
//string loc_patch = getenv("patch_pd");

class manipulation_filters{
public: 
  int filter_lowpass_pre(string path);
  int filter_lowpass(string path, string frequency_input, string gain_input, string suppress_high_freq_l, string suppress_high_freq_r);
  int filter_highpass_pre(string path);
  int filter_highpass(string path, string frequency_input, string gain_input, string suppress_low_freq_l, string suppress_low_freq_r);
  int filter_bandpass(string path, string frequency_l_input, string frequency_r_input, string gain_l_input, string gain_r_input, string q_in_left, string q_in_right);
};

class command
{
public:
  int do_command(string task);
};

