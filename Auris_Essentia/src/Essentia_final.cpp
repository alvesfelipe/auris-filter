/* Por Allison Cândido Lima Santos */
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <essentia/algorithmfactory.h>
#include <essentia/essentiamath.h>
#include <essentia/pool.h>
#include <string>

using namespace std;
using namespace essentia;
using namespace essentia::standard;

string format(string str);

class lowPass
{
	public:
		lowPass(string filenameIn, string filenameOut);
		lowPass(string filenameIn, string filenameOut, unsigned int f, int g1);
		~lowPass();
		void doFilter();

	private:
		unsigned int cutFrequency;
		int gain;
		string fileNameIn, fileNameOut;
};

lowPass::lowPass(string filenameIn, string filenameOut)
{
	/* construtor default, usado quando não são passados parametros*/
	cutFrequency = 250;
	gain = 2;
	fileNameIn = filenameIn;
	fileNameOut = filenameOut;
}

lowPass::lowPass(string filenameIn, string filenameOut, unsigned int f, int g1)
{
	/* construtor usado quando se quer um filtro com parâmetros personalizado*/
	cutFrequency = f;
	gain = g1;
	fileNameIn = filenameIn;
	fileNameOut = filenameOut;
}

void lowPass::doFilter()
{
	essentia::init();
	AlgorithmFactory& factory = standard::AlgorithmFactory::instance();

	int sampleRate = 44100;
	Algorithm* audio 	 = factory.create("EasyLoader",
                        "filename", fileNameIn,
			"replayGain", gain, 
                        "sampleRate", sampleRate);

	Algorithm* lowPassFilter = factory.create("LowPass",
						"cutoffFrequency", cutFrequency,
						"sampleRate", sampleRate);

	Algorithm* MonoWriter    = factory.create("MonoWriter",
				"bitrate", 192,
				"filename", fileNameOut,
				"format", format(fileNameOut),
				"sampleRate", sampleRate);
	vector<Real> audioBuffer, audioBufferFiltered;

	audio->output("audio").set(audioBuffer);
	lowPassFilter->input("signal").set(audioBuffer);
	lowPassFilter->output("signal").set(audioBufferFiltered);
	MonoWriter->input("audio").set(audioBufferFiltered);

	audio->compute();
	lowPassFilter->compute();
	MonoWriter->compute();
	essentia::shutdown();
}

class highPass
{
	public:
		highPass(string filenameIn, string filenameOut);
		highPass(string filenameIn, string filenameOut, unsigned int f, int g1);
		~highPass(){}
		void doFilter();

		private:
		unsigned int cutFrequency;
		int gain;
		string fileNameIn, fileNameOut;
};

highPass::highPass(string filenameIn, string filenameOut)
{
	/* construtor default, usado quando não são passados parametros*/
	cutFrequency = 3000;
	gain = 2;
	fileNameIn = filenameIn;
	fileNameOut = filenameOut;
}

highPass::highPass(string filenameIn, string filenameOut, unsigned int f, int g1)
{
	/* construtor usado quando se quer um filtro com parâmetros personalizado*/
	cutFrequency = f;
	gain = g1;
	fileNameIn = filenameIn;
	fileNameOut = filenameOut;
}

void highPass::doFilter()
{
	essentia::init();
	AlgorithmFactory& factory = standard::AlgorithmFactory::instance();

	int sampleRate = 44100;
	Algorithm* audio 	 = factory.create("EasyLoader",
                        "filename", fileNameIn,
			"replayGain", gain,
                        "sampleRate", sampleRate);

	Algorithm* highPassFilter = factory.create("HighPass",
						"cutoffFrequency", cutFrequency,
						"sampleRate", sampleRate);

	Algorithm* MonoWriter    = factory.create("MonoWriter",
				"bitrate", 192,
				"filename", fileNameOut,
				"format", format(fileNameOut),
				"sampleRate", sampleRate); 
	vector<Real> audioBuffer, audioBufferFiltered;

	audio->output("audio").set(audioBuffer);
	highPassFilter->input("signal").set(audioBuffer);
	highPassFilter->output("signal").set(audioBufferFiltered);
	MonoWriter->input("audio").set(audioBufferFiltered);

	audio->compute();
	highPassFilter->compute();
	MonoWriter->compute();
	essentia::shutdown();
}

class bandPass
{
	public:
		bandPass(string file1, string file2, unsigned int f1, unsigned int bd, int g);
		~bandPass(){}
		void doFilter();
		
		private:
		unsigned int cutFrequency, bandWidth;
		int gain;
		string fileNameIn, fileNameOut;
};

bandPass::bandPass(string file1, string file2, unsigned int f1, unsigned int bd, int g)
{
	/* construtor default*/
	cutFrequency = f1;
	bandWidth = bd;
	gain = g;
	fileNameIn = file1;
	fileNameOut = file2;
}

void bandPass::doFilter() 
{
	essentia::init();
	AlgorithmFactory& factory = standard::AlgorithmFactory::instance();

	int sampleRate = 44100;
	Algorithm* audio 	 = factory.create("EasyLoader",
                        "filename", fileNameIn,
			"replayGain", gain,
                        "sampleRate", sampleRate);

	Algorithm* highPassFilter = factory.create("BandPass",
						"cutoffFrequency", cutFrequency,
						"sampleRate", sampleRate,
						"bandwidth", bandWidth);

	Algorithm* MonoWriter    = factory.create("MonoWriter",
				"bitrate", 192,
				"filename", fileNameOut,
				"format", format(fileNameOut),
				"sampleRate", sampleRate); 
	vector<Real> audioBuffer, audioBufferFiltered;

	audio->output("audio").set(audioBuffer);
	highPassFilter->input("signal").set(audioBuffer);
	highPassFilter->output("signal").set(audioBufferFiltered);
	MonoWriter->input("audio").set(audioBufferFiltered);

	audio->compute();
	highPassFilter->compute();
	MonoWriter->compute();
	essentia::shutdown();
}

int main(int argc, char ** argv)
{
	if(argc < 2)
	{
		clog << "Numero de argumentos inválido, não foi escolhido opção de filtro.\n";
		exit(1);
	}
	if(!strcmp(argv[1], "1"))
	{
		if(argc < 3)
		{
			clog << "Numero de argumentos inválido, não foi informado o caminho do arquivo de audio de entrada.\n";
			exit(1);
		}
		if(argc < 4)
		{
			clog << "Numero de argumentos inválido, não foi informado o caminho do arquivo de audio de saida.\n";
			exit(1);
		}
		lowPass *filtro = new lowPass(argv[2], argv[3]);
		filtro->doFilter();
	}
	if(!strcmp(argv[1], "2"))
	{
		if(argc < 3)
		{
			clog << "Numero de argumentos inválido, não foi informado o caminho do arquivo de audio de entrada.\n";
			exit(1);
		}
		if(argc < 4)
		{
			clog << "Numero de argumentos inválido, não foi informado o caminho do arquivo de audio de saida.\n";
			exit(1);
		}
		if(argc < 5)
		{
			clog << "Numero de argumentos inválido, não foi informado a frequencia de corte.\n";
			exit(1);
		}
		if(argc < 6)
		{
			clog << "Numero de argumentos inválido, não foi informado o ganho.\n";
			exit(1);
		}
		
		lowPass *filtro = new lowPass(argv[2], argv[3], atoi(argv[4]), atoi(argv[5]));
		filtro->doFilter();
	}
	if(!strcmp(argv[1], "3"))
	{
		if(argc < 3)
		{
			clog << "Numero de argumentos inválido, não foi informado o caminho do arquivo de audio de entrada.\n";
			exit(1);
		}
		if(argc < 4)
		{
			clog << "Numero de argumentos inválido, não foi informado o caminho do arquivo de audio de saida.\n";
			exit(1);
		}
		highPass *filtro = new highPass(argv[2], argv[3]);
		filtro->doFilter();
	}
	if(!strcmp(argv[1], "4"))
	{
		if(argc < 3)
		{
			clog << "Numero de argumentos inválido, não foi informado o caminho do arquivo de audio de entrada.\n";
			exit(1);
		}
		if(argc < 4)
		{
			clog << "Numero de argumentos inválido, não foi informado o caminho do arquivo de audio de saida.\n";
			exit(1);
		}
		if(argc < 5)
		{
			clog << "Numero de argumentos inválido, não foi informado a frequencia de corte.\n";
			exit(1);
		}
		if(argc < 6)
		{
			clog << "Numero de argumentos inválido, não foi informado o ganho.\n";
			exit(1);
		}
		
		highPass *filtro = new highPass(argv[2], argv[3], atoi(argv[4]), atoi(argv[5]));
		filtro->doFilter();
	}
	if(!strcmp(argv[1], "5"))
	{
		if(argc < 3)
		{
			clog << "Numero de argumentos inválido, não foi informado o caminho do arquivo de audio de entrada.\n";
			exit(1);
		}
		if(argc < 4)
		{
			clog << "Numero de argumentos inválido, não foi informado o caminho do arquivo de audio de saida.\n";
			exit(1);
		}
		if(argc < 5)
		{
			clog << "Numero de argumentos inválido, não foi informado a frequencia de corte.\n";
			exit(1);
		}
		if(argc < 6)
		{
			clog << "Numero de argumentos inválido, não foi informado a largura de banda.\n";
			exit(1);
		}
		if(argc < 7)
		{
			clog << "Numero de argumentos inválido, não foi informado o ganho.\n";
			exit(1);
		}
		
		bandPass *filtro = new bandPass(argv[2], argv[3], atoi(argv[4]), atoi(argv[5]), atoi(argv[6]));
		filtro->doFilter();
	}
	
	return 0;
}

string format(string str)
{
	char fmt[4];
	char compare = '.';
	for(unsigned int u = 0; u < str.length(); u++)
	{
		char ch = str[u];
		
		if(ch == compare)
		{
			int i = 0;
			for(u += 1; u < str.length(); u++)
			{
				fmt[i++] = str[u];
			}
			fmt[i]='\0';
			return (string) fmt;		
		}
	}
	return NULL;
}
