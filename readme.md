# Dependências
## Windows
    - cmake >= 3.10
    - Instalar MSYS2
## Linux
```
    apt update
    apt install build-essential cmake
```
## Mac
```
    brew install cmake
```

# Compilação
*O projeto está configurado para utilizar as tasks do vscode.*
- Clean
- Build
- Run
- Clean and Build
- Clean, Build and Run

## Mac
Utilize o atalho `cmd + shift + p` e selecione uma das tasks listadas acima.

## Windows ou linux
Utilize o atalho `ctrl + shift + p` e selecione uma das tasks listadas acima.

## Build
Para o build manual utilize esses comandos
```
cmake .
make
```

# Execução
No terminal execute o programa `MergeSort` que foi gerado na pasta `build` que está na raiz do projeto.
```
./build/MergeSort
```
