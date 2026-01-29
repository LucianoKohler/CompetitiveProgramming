# Compilando como um Pro

Quando falamos de C++, precisamos, após a criação do código, rodá-lo para ver se ele realmente funciona e soluciona nosso problema, e para isso, **Compilamo-os**, como? Utilizando o compilador da linguagem, que na maioria das vezes, será o **g++**

Uma compilação simples (e na maioria das vezes já suficiente), pode ser a clássica linha:

### <center> `g++ arq.cpp`

Gerando com essa linha, o executável `a.exe` que executa o código normalmente.

---

Mas quando falamos de programação competitiva, muitas das vezes, precisamos de algumas ferramentas a mais que podem auxiliar no desenvolvimento, otimização e depuração do código, para isso, é possível usar algumas outras keywords como:

### <center> `g++ -std=c++11 -O2 -Wall arq.cpp -o arq`

Onde:
- `-std=c++11`: Indica a versão da linguagem a se seguir (bem dispensável)
- `O2`: Indica o _nível de otimização_ do código, e segue este padrão:
    - `O0`: Nenhuma otimização feita (padrão)
    - `O1`: Algumas otimizações são feitas
    - `O2`: Otimizações fortes porém que não quebram o código são feitas
    - `O3`: Otimizações muito agressivas são feitas e **pode ou não** mudar como o código se comporta
    - `Os`: Otimização focada em memória (pesa menos em termos de tamanho)
- `Wall`: Significa Warn All, e manda o compilador ser bem chorão na hora de procurar por warnings e erros, mostrando muito mais warnings que uma compilação comum deixaria passar
- `-o arq`: Indica o nome do arquivo de saída, por padrão ele será nomeado como "a" ou "out", mas com -o, é possível alterar o nome do executável

Assim, temos muito mais funcionalidades para auxiliar a resolver aquela questão difícil que você não passa de jeito nenhum!

****Lembre-se** de que não é necessário usar todas essas keywords, analise a situação e infira quais keywords serão uteis para você, boa programação!*