#include <stdlib.h>
#include "../include/lib.h"
#include "./lib.cpp"


int main(int argc, char* argv[])
{
	//clog << "Contador de dados:: " << argc << endl;
	manipulation_filters filter;

	if(argc > 1)
	{	
		if(*argv[1] == '1'){
			if(argc == 4)
				filter.filter_lowpass_pre(argv[2], argv[3]);
			else if (argc == 3)
				clog << "Nao foi especificado o arquivo de saida." << endl;
			else if (argc == 2)
				clog << "Nao foi especificado o arquivo de entrada." << endl;
		}
		if(*argv[1] == '2'){
			
			if(argc == 8){
				
				string file, freq, gain, supl, supr, pathSave;
				
				file = argv[2];
				
				freq = argv[3];

				gain = argv[4];

				supl = argv[5];

				supr = argv[6];

				pathSave = argv[7];
				filter.filter_lowpass(file, freq, gain, supl, supr, pathSave);
				
			}
			else if(argc == 2)
					clog << "Nao foi especificado o arquivo." << endl;
				else if(argc == 3)
					clog << "Nao foi especificado a frequencia." << endl;
				else if (argc == 4)
					clog << "Nao foi especificado o ganho." << endl;
				else if(argc == 5)
					clog << "Nao foi especificado a supressao dos agudos em L." << endl;
				else if (argc == 6)
					clog << "Nao foi especificado a supressao dos agudos em R." << endl;
				else if(argc == 7)
					clog << "Nao foi especificado o caminho do arquivo de saida." << endl;
		}
		if(*argv[1] == '3'){
			if(argc == 4)
				filter.filter_highpass_pre(argv[2], argv[3]);
			else if(argc == 2)
				clog << "Nao foi especificado o caminho do arquivo de entrada." << endl;
			else if(argc == 3)
				clog << "Nao foi especificado o caminho do arquivo de saida." << endl;

		}
		if(*argv[1] == '4'){
			if(argc == 8){
				string file, freq, gain, supl, supr, pathSave;
				file = argv[2];
				freq = argv[3];
				gain = argv[4];
				supl = argv[5];
				supr = argv[6];
				pathSave = argv[7];
				filter.filter_highpass(file, freq, gain, supl, supr, pathSave);
			}
			else if(argc == 2)
					clog << "Nao foi especificado o arquivo." << endl;
				else if(argc == 3)
					clog << "Nao foi especificado a frequencia." << endl;
				else if (argc == 4)
					clog << "Nao foi especificado o ganho." << endl;
				else if(argc == 5)
					clog << "Nao foi especificado a supressao dos graves em  L." << endl;
				else if(argc == 6)
					clog << "Nao foi especificado a supressao dos graves em R." << endl;
				else if (argc == 7)
					clog << "Nao foi especificado o caminho de saida do audio processado." << endl;
		}
		if(*argv[1] == '5'){
			if(argc == 10)
			{
				string file, freql, freqr, gainl, gainr, qr, ql, pathSave;
				file = argv[2];
				freql = argv[3];
				freqr = argv[4];
				gainl = argv[5];
				gainr = argv[6];
				ql = argv[7];
				qr = argv[8];
				pathSave = argv[9];
				filter.filter_bandpass(file, freql, freqr, gainl, gainr, ql, qr, pathSave);
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
			else if(argc == 9)
				clog << "Nao foi especificado o caminho de saida do audio processado." << endl;
		}
	}
  return 0;
}
