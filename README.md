Para instalar o Puredata extended, basta, no ubuntu:

sudo add-apt-repository ppa:eighthave/pd-extended
sudo apt-get update
sudo apt-get install pd-extended

Para compilar os testes, basta, em src:

g++ main.cpp -o main

Executando:

Para usar o filtro passa baixo pre-definido:

./main 1 "nome do arquivo de entrada.wav" "nome do arquivo de saida.wav"

Ex:
./main 1 "/home/user/Music/musica.wav" "/home/user/Music/MscProc.wav"

Para usar o filtro passa baixo não pre-definido:

./main 2 "nome do arquivo de entrada.wav" "frequencia de corte" "ganho" "Supressão em L de ganho para as frequencias mais altas que a que esta passando, use 0 se não quiser alterar" "Supressão em R de ganho para as frequencias mais altas que a que esta passando, use 0 se não quiser alterar" "Caminho + nome do arquivo de saida.wav" 

Ex:
./main 2 "/home/user/Music/musica.wav" "500" "2"  "0.3" "0.4" "/home/user/Music/MscProc.wav"

Para usar o filtro passa alta pre-definido:

./main 3 "/home/user/Music/nome do arquivo de entrada.wav" "/home/user/Music/nome do arquivo de saida.wav"

Ex:
./main 3 "/home/user/Music/musica.wav" "/home/user/Music/MscProc.wav"

Para usar o filtro passa alta não pre-definido:

./main 4 "nome do arquivo de entrada.wav" "frequencia de corte" "ganho" "Supressão em L de ganho para as frequencias mais baixas que a que esta passando, use 0 se não quiser alterar" "Supressão em R de ganho para as frequencias mais baixas que a que esta passando, use 0 se não quiser alterar" "Caminho+nome do arquivo de saida.wav" 

Ex:
./main 4 "/home/user/Music/musica.wav" "500" "2"  "0.3" "0.4" "/home/user/Music/MscProc.wav"

Para usar o filtro passa baixo banda:

./main 5 "/home/user/Music/nome do arquivo de entrada.wav" "frequencia de L" "frequencia de R" "ganho da frequencia de L" "ganho da frequencia de R" "Q da frequencia de L" "Q da frequencia de R" "Caminho+nome do arquivo de saida"

Ex:
./main 5 "/home/user/Music/musica.wav" "500" "600" "2"  "3" "0.4" "0.4" "/home/user/Music/MscProc.wav"



