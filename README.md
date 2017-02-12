# Auris-Filter Setup

These Scripts were made to install the libraries and apply the filters on audio successfully.

These Modules includes:

- Auris Filters

### Installation:

There are two main scripts:
- One for the PureData
- Other for the Essentia library

Which add the following Repositories:
- ppa:eighthave/pd-extended
- ppa:mc3man/trusty-media

And which Install the following packages:
- gcc
- g++
- make
- mplayer
- build-essential
- libyaml-dev
- libfftw3-dev
- libavcodec-dev **
- libavformat-dev **
- libavutil-dev **
- libavresample-dev **
- python-dev
- libsamplerate0-dev
- libtag1-dev
- python-numpy-dev
- python-numpy
- python-yaml
- yasm
- cmake
- [fftw]
- ffmpeg
- gstreamer0.10-ffmpeg
- lame
- [libav] >= 10, in this case will be installed the version 12.
- libsamplerate-0.1.9
- libsndfile-1.0.27
- [taglib]
- [yaml]
- swig
- swig2.0
- swig3.0
- build-essential
- libqt4-dev
- libyaml-dev
- swig
- python-dev
- pkg-config
- [gaia]
- [Essentia]
- [PureData extended] pd-extended

** Included in libav package

### Make Run:

Now that everything is ready to run, go to Auris filter folder.
```sh
$ cd ~/MUSIC_DEAF/music_for_deaf/auris-filter/
```

Make and run:

Or, step by step.
First, using Essentia:
```
$ make ESSENTIA or just make
```
Second, using PureData:
```
$ make PD or just make
```
To run the program, it is enough call the compilated object like the examples bellow:

###  In Essentia:

To use the low pass filter pre-defined:
```sh
./Auris_essentia 1 "path_to_input/name_of_music.wav" "path_to_output/name_of_music.wav"

Ex: ./Auris_essentia 1 "$HOME/Music/music.wav" "$HOME/Music/MscProc.wav"
```

To use the low pass filter not pre-defined:
```sh
./Auris_essentia 2 "path_to_input/name_of_music.wav" "path_to_output/name_of_music.wav" "cut frequency" "gain" 

Ex: ./Auris_essentia 2 "$HOME/Music/music.wav" "$HOME/Music/MscProc.wav" "500" "2" 
```

To use the high pass filter pre-defined:
```sh
./Auris_essentia 3 "path_to_input/name_of_music.wav" "path_to_output/name_of_music.wav"
Ex: ./Auris_essentia 3 "$HOME/Music/music.wav" "$HOME/Music/MscProc.wav"    
```

To use the high pass filter not pre-defined:
```sh
./Auris_essentia 4 "path_to_input/name_of_music.wav" "path_to_output/name_of_music.wav" "cut frequency" "gain" 

Ex: ./Auris_essentia 4 "$HOME/Music/music.wav" "$HOME/Music/MscProc.wav" "500" "2" 
```

To use the band pass filter:
```sh
./Auris_essentia 5 "path_to_input/name_of_music.wav" "path_to_output/name_of_music.wav" "Cut frequency" "Band width" "gain"

Ex: ./Auris_essentia 5 "$HOME/Music/musica.wav" "$HOME/Music/MscProc.wav" "500" "125" "2"
```

### Attention: Using Essentia you can input files of the following formats:
    - WAV
    - MP3
    - OGG
    - FLAC
    - etc. In Essentia library all the formats supported by ffmpeg can be used.

### In Puredata:

To use the low pass filter pre-defined:
```sh
./Auris_pd 1 "path_to_input/name_of_music.wav" "path_to_output/name_of_music.wav"

Ex: ./Auris_pd 1 "$HOME/Music/music.wav" "$HOME/Music/MscProc.wav"
```

To use the low pass filter not pre-defined:
```sh
./Auris_pd 2 "path_to_input/name_of_music.wav" "cut frequency" "gain" "Supress value in L of gain to the frequencies higher than the are passing, use 0 if you don't want to change" "Supress value in R of gain to the frequencies higher than the are passing, use 0 if you don't want to change" "path_to_output/name_of_music.wav"

Ex: ./Auris_pd 2 "$HOME/Music/music.wav" "500" "2" "0.3" "0.4" "$HOME/Music/MscProc.wav"
```    

To use the high pass filter pre-defined:
```sh
./Auris_pd 3 "path_to_input/name_of_music.wav" "path_to_output/name_of_music.wav"

Ex: ./Auris_pd 3 "$HOME/Music/music.wav" "$HOME/Music/MscProc.wav"
```

To use the high pass filter not pre-defined:
```sh
./Auris_pd 4 "path_to_input/name_of_music.wav" "cut frequency" "gain"  "Supress value in L of gain to the frequencies lower than the are passing, use 0 if you don't want to change" "Supress value in R of gain to the frequencies lower than the are passing, use 0 if you don't want to change" "path_to_input/name_of_music.wav"

Ex: ./Auris_pd 4 "$HOME/Music/musica.wav" "500" "2" "0.3" "0.4" "$HOME/Music/MscProc.wav"
```

To use the band pass filter:
```sh
./Auris_pd 5 "path_to_input/name_of_music.wav" "frequency of L" "frequency of R" "gain of L" "gain of R" "Q of L" "Q of R" "path_to_output/name_of_music.wav"

Ex: ./Auris_pd 5 "$HOME/Music/musica.wav" "500" "600" "2" "3" "0.4" "0.4" "$HOME/Music/MscProc.wav"
```

### Attention: Using Pure Data only wav format file is supported.

[libav]: <https://libav.org/>
[fftw]: <http://www.fftw.org/>
[taglib]: <http://developer.kde.org/~wheeler/taglib.html>
[yaml]: <http://pyyaml.org/wiki/LibYAML>
[gaia]: <https://github.com/MTG/gaia>
[Essentia]: <http://essentia.upf.edu/>
[PureData extended]: <https://puredata.info/downloads/pd-extended>