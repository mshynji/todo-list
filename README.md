# To-do List para Terminal

Programa desenvolvido para sistemas Linux em C++ para aprender estrutura de programas em C/C++ e Makefile. O programa contém uma interface minimalista e permite com que o usuário manter uma lista de tarefas a serem realizadas, sendo possível adicionar e remover novas atividades conforme necessidade.

## Instalação
### Pré-requisitos
- make
- g++

### Instalação
```bash
    ~$ git clone https://github.com/mshynji/todo-list.git
    ~$ cd todo-list/
    ~$ make || make all
```

## Uso
Para utilizar o programa, basta rodar o comando `./bin/to-do` dentro do diretório do repositório. Também é possível adicionar o caminho do executável para o PATH do seu sistema operacional:

```bash
    # Bash
    echo 'export PATH="$PATH:'$(realpath ./bin)'"' >> ~/.bashrc && source ~/.bashrc

    # Fish shell
    set -U fish_user_paths caminho/para/todo-list/bin $fish_user_paths
```

Fazendo isso, basta rodar o comando `to-do` de qualquer lugar do terminal.
