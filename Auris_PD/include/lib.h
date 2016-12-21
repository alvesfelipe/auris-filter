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
#ifndef stringh
#define stringh
#include <string.h>
#endif
using namespace std;

string loc_patch;

class manipulation_filters{
public: 
  int filter_lowpass_pre(string path, string pathSave);
  int filter_lowpass(string path, string frequency_input, string gain_input, string suppress_high_freq_l, string suppress_high_freq_r, string pathSave);
  int filter_highpass_pre(string path, string pathSave);
  int filter_highpass(string path, string frequency_input, string gain_input, string suppress_low_freq_l, string suppress_low_freq_r, string pathSave);
  int filter_bandpass(string path, string frequency_l_input, string frequency_r_input, string gain_l_input, string gain_r_input, string q_in_left, string q_in_right, string pathSave);
  manipulation_filters()
  {
  	char * dir = getenv("AURIS_HOME_PATH");
  	char * pat = "auris-filter/pd_files/equalizador\ 1.pd";
  	char * final = (char *)malloc(100);
  	if(dir == NULL)
  	{
  		clog << "Variavel de ambiente AURIS_HOME_PATH nao setada. Abortando.\n";
  		exit(-1);
  	}
  	strcat(final, dir);
  	strcat(final, pat);
  	loc_patch = final;
  }
};

class command
{
public:
  int do_command(string task);
};

