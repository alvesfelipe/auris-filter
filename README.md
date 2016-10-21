Para instalar o Puredata extended, basta, no ubuntu:

sudo add-apt-repository ppa:eighthave/pd-extended
sudo apt-get update
sudo apt-get install pd-extended

Para compilar os testes, basta, em src:

g++ main.cpp -o main

Executando:

Para usar o filtro passa baixo pre-definido:

./main 1 "nome do arquivo.wav"

Ex:
./main 1 "musica.wav"

Para usar o filtro passa baixo não pre-definido:

./main 2 "nome do arquivo.wav" "frequencia de corte" "ganho" "Supressão em L de ganho para as frequencias mais altas que a que esta passando, use 0 se não quiser alterar" "Supressão em R de ganho para as frequencias mais altas que a que esta passando, use 0 se não quiser alterar" 

Ex:
./main 2 "musica.wav" "500" "2"  "0.3" "0.4" 

Para usar o filtro passa alta pre-definido:

./main 3 "nome do arquivo.wav"

Ex:
./main 3 "musica.wav"

Para usar o filtro passa alta não pre-definido:

./main 4 "nome do arquivo.wav" "frequencia de corte" "ganho" "Supressão em L de ganho para as frequencias mais baixas que a que esta passando, use 0 se não quiser alterar" "Supressão em R de ganho para as frequencias mais baixas que a que esta passando, use 0 se não quiser alterar" 

Ex:
./main 4 "musica.wav" "500" "2"  "0.3" "0.4" 

Para usar o filtro passa baixo banda:

./main 5 "nome do arquivo.wav" "frequencia de L" "frequencia de R" "ganho da frequencia de L" "ganho da frequencia de R" "Q da frequencia de L" "Q da frequencia de R"

Ex:
./main 5 "musica.wav" "500" "600" "2"  "3" "0.4" "0.4" 


