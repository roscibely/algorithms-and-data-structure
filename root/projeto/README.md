# Raylib — Instalação no Windows e Linux

Este guia apresenta como instalar a biblioteca **Raylib** para desenvolvimento de jogos em **C** nos sistemas operacionais **Windows** e **Linux**.

A Raylib é uma biblioteca simples e multiplataforma para desenvolvimento de jogos e aplicações gráficas em C/C++.

## 📋 Pré-requisitos

Você precisará de:

* Compilador C
* Git
* CMake
* Raylib

---

# 🪟 Windows

## Opção 1 — MSYS2

A maneira recomendada para trabalhar com C no Windows é utilizar o **MSYS2**.

### 1. Instalar o MSYS2

Baixe o MSYS2 em:

https://www.msys2.org/

Após a instalação, abra o terminal:

**MSYS2 UCRT64**

Atualize os pacotes:

```bash
pacman -Syu
```

Se o terminal solicitar o fechamento, feche-o, abra novamente o **MSYS2 UCRT64** e execute:

```bash
pacman -Su
```

---

## 2. Instalar o compilador

No terminal **MSYS2 UCRT64**:

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
```

Verifique a instalação:

```bash
gcc --version
```

---

## 3. Instalar a Raylib

Execute:

```bash
pacman -S mingw-w64-ucrt-x86_64-raylib
```

Verifique:

```bash
pkg-config --modversion raylib
```

Se aparecer uma versão, a Raylib está instalada.

---

## 4. Criar um programa

Crie uma pasta para o projeto:

```bash
mkdir meu-jogo
cd meu-jogo
```

Crie o arquivo:

```bash
touch main.c
```

Coloque no `main.c`:

```c
#include "raylib.h"

int main(void)
{
    InitWindow(800, 450, "Meu primeiro jogo");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText(
            "Raylib funcionando!",
            250,
            200,
            30,
            BLACK
        );

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
```

---

## 5. Compilar

No **MSYS2 UCRT64**:

```bash
gcc main.c -o jogo.exe $(pkg-config --cflags --libs raylib)
```

Execute:

```bash
./jogo.exe
```

Se uma janela aparecer com a mensagem **"Raylib funcionando!"**, a instalação está funcionando corretamente.

---

# 🐧 Linux

Os comandos abaixo são voltados principalmente para distribuições baseadas em Debian/Ubuntu.

## 1. Atualizar o sistema

```bash
sudo apt update
```

---

## 2. Instalar as ferramentas de desenvolvimento

```bash
sudo apt install build-essential git cmake pkg-config
```

Verifique o compilador:

```bash
gcc --version
```

---

## 3. Instalar dependências da Raylib

```bash
sudo apt install \
libasound2-dev \
libx11-dev \
libxrandr-dev \
libxi-dev \
libxcursor-dev \
libxinerama-dev \
libgl1-mesa-dev \
libglu1-mesa-dev
```

---

## 4. Baixar a Raylib

Clone o repositório oficial:

```bash
git clone https://github.com/raysan5/raylib.git
```

Entre na pasta:

```bash
cd raylib
```

---

## 5. Compilar

Crie uma pasta para a compilação:

```bash
mkdir build
cd build
```

Execute:

```bash
cmake ..
```

Depois:

```bash
make
```

Instale:

```bash
sudo make install
```

Atualize o cache das bibliotecas:

```bash
sudo ldconfig
```

---

# 🧪 Testando no Linux

Crie uma pasta para o projeto:

```bash
mkdir ~/meu-jogo
cd ~/meu-jogo
```

Crie:

```bash
nano main.c
```

Insira:

```c
#include "raylib.h"

int main(void)
{
    InitWindow(800, 450, "Meu primeiro jogo");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText(
            "Raylib funcionando!",
            250,
            200,
            30,
            BLACK
        );

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
```

Salve o arquivo.

---

## Compilar

```bash
gcc main.c -o jogo $(pkg-config --cflags --libs raylib)
```

Execute:

```bash
./jogo
```

Uma janela deverá aparecer.

---

# 📁 Estrutura recomendada do projeto

À medida que os projetos crescerem, recomendamos utilizar uma estrutura semelhante a:

```text
meu-jogo/
│
├── src/
│   └── main.c
│
├── assets/
│   ├── images/
│   ├── sounds/
│   └── fonts/
│
├── include/
│
├── build/
│
└── README.md
```

---

# 🔧 Verificando a instalação

## Windows

```bash
gcc --version
```

e:

```bash
pkg-config --modversion raylib
```

## Linux

```bash
gcc --version
```

e:

```bash
pkg-config --modversion raylib
```

Se o comando `pkg-config` retornar a versão da Raylib, a biblioteca está disponível para compilação.

---


## 📚 Documentação

Documentação oficial:

https://www.raylib.com/

Repositório oficial:

https://github.com/raysan5/raylib

Exemplos:

https://www.raylib.com/examples.html

---
