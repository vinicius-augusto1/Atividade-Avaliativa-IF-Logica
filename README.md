# Sistema de Cadastro e Relatório de Peças

Este software em C permite cadastrar peças de diferentes formas (esfera, cilindro, paralelepípedo), associando materiais e lojas, calcular propriedades físicas e gerar um relatório consolidado.

---

## Funcionalidades

- Cadastro de peças com seleção de forma, material e loja.
- Cálculo automático de área, volume, peso, custo e quantidade de tinta necessária.
- Relatório com:
  - Peso total das peças.
  - Peso médio das esferas por material.
  - Valor total gasto.
  - Loja que mais faturou.

---

## Estrutura do Projeto

```
Atividade Avaliativa 2/
├── bin/
│   └── programa
├── src/
│   ├── controller.c
│   ├── controller.h
│   ├── main.c
│   ├── peca.c
│   ├── peca.h
│   ├── relatorio.c
│   ├── relatorio.h
│   ├── util.c
│   └── util.h
└── README.md
```

---

## Como Compilar

Execute o comando abaixo na raiz do projeto:

```sh
gcc -Wall -Werror -o bin/programa src/*.c -lm
```

- `-Wall`: ativa todos os avisos do compilador.
- `-Werror`: trata avisos como erros.
- `-o bin/programa`: define o executável de saída.
- `-lm`: linka a biblioteca matemática.

---

## Como Executar

Após compilar, execute:

```sh
./bin/programa
```

---

## Fluxo do Programa

1. O usuário é guiado para cadastrar peças, informando:
   - Forma (esfera, cilindro, paralelepípedo)
   - Material (aço, alumínio, bronze)
   - Loja (Zé, João, Paulo, Chico, Mané, Alfa, Beta)
   - Dimensões (raio, altura, largura, profundidade conforme a forma)
2. O programa calcula automaticamente as propriedades físicas e comerciais.
3. Ao finalizar o cadastro, é gerado um relatório detalhado.

---

## Principais Arquivos e Funções

- `src/main.c`: Ponto de entrada, chama o controlador principal.
- `src/controller.c/h`: Gerencia o fluxo de cadastro e chamada do relatório.
- `src/peca.c/h`: Funções de cálculo de área, volume, peso, custo e tinta.
- `src/relatorio.c/h`: Geração do relatório consolidado.
- `src/util.c/h`: Utilitários para entrada de dados e nomes de enums.

---

## Protótipos das Funções Utilitárias

```c
// src/util.h

const char* nomeMaterial(Material material);
const char* nomeForma(TipoForma forma);
const char* nomeLoja(Loja loja);

Material lerMaterial();
TipoForma lerForma();
Loja lerLoja();

float lerFloat(const char* mensagem);
int lerInt(const char *msg);
```

---

## Observações

- O limite de peças é definido por `MAX_PECAS` em `src/peca.h`.
- O programa exige entradas válidas e orienta o usuário em caso de erro.
- O relatório mostra apenas médias de esferas cadastradas.

---

## Autoria

Vinícius Augusto
