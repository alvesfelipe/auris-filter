#include "../include/lib.h"
#include "../include/lib.cpp"

int main(int argc, char* argv[])
{
	clog << "Contador de dados:: " << argc << endl;
	manipulation_filters filter;

	if(argc > 1)
	{	
		if(*argv[1] == '1'){
			if(argc == 3)
				filter.filter_lowpass_pre(argv[2]);
			else
				clog << "Nao foi especificado o arquivo." << endl;
		}
		if(*argv[1] == '2'){
			
			if(argc == 7){
				
				string file, freq, gain, supl, supr;
				
				file = argv[2];
				
				freq = argv[3];

				gain = argv[4];

				supl = argv[5];

				supr = argv[6];
				
				filter.filter_lowpass(file, freq, gain, supl, supr);
				
			}
			else if(argc == 2)
					clog << "Nao foi especificado o arquivo." << endl;
				else if(argc == 3)
					clog << "Nao foi especificado a frequencia." << endl;
				else if (argc == 4)
					clog << "Nao foi especificado o ganho." << endl;
				else if(argc == 5)
					clog << "Nao foi especificado a supressao dos agudos." << endl;
		}
		if(*argv[1] == '3'){
			if(argc == 3)
				filter.filter_highpass_pre(argv[2]);
			else
				clog << "Nao foi especificado o arquivo." << endl;
		}
		if(*argv[1] == '4'){
			if(argc == 7){
				string file, freq, gain, supl, supr;
				file = argv[2];
				freq = argv[3];
				gain = argv[4];
				supl = argv[5];
				supr = argv[6];
				filter.filter_highpass(file, freq, gain, supl, supr);
			}
			else if(argc == 2)
					clog << "Nao foi especificado o arquivo." << endl;
				else if(argc == 3)
					clog << "Nao foi especificado a frequencia." << endl;
				else if (argc == 4)
					clog << "Nao foi especificado o ganho." << endl;
				else if(argc == 5)
					clog << "Nao foi especificado a supressao dos graves." << endl;
		}
		if(*argv[1] == '5'){
			if(argc == 9)
			{
				string file, freql, freqr, gainl, gainr, qr, ql;
				file = argv[2];
				freql = argv[3];
				freqr = argv[4];
				gainl = argv[5];
				gainr = argv[6];
				ql = argv[7];
				qr = argv[8];
				filter.filter_bandpass(file, freql, freqr, gainl, gainr, ql, qr);
			}
			else if(argc == 2)
				clog << "Nao foi especificado o arquivo." << endl;
			else if(argc == 3)
				clog << "Nao foi especificado a freq em L." << endl;
			else if(argc == 4)
				clog << "Nao foi especificado a freq em R." << endl;
			else if(argc == 5)
				clog << "Nao foi especificado o ganho em L." << endl;
			else if(argc == 6)
				clog << "Nao foi especificado o ganho em R." << endl;
			else if(argc == 7)
				clog << "Nao foi especificado o Q em L." << endl;
			else if(argc == 8)
				clog << "Nao foi especificado o Q em R." << endl;
		}
	}
  return 0;
}
