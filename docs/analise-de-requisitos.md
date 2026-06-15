# Sistema de Transporte Urbano

**Análise de Requisitos e Arquitetura do Sistema**
Projeto de Avaliação — Programação em C

---

## 1. Introdução

Este documento descreve a análise de requisitos e a arquitetura do Sistema de Transporte Urbano, desenvolvido em linguagem C como projeto de avaliação acadêmica.

O sistema tem como objetivo gerenciar linhas de ônibus urbano, incluindo cadastro de rotas com paradas intermediárias, horários, veículos e motoristas, além de calcular tarifas com base na distância percorrida entre paradas.

---

## 2. Modelagem das Entidades

O sistema é composto por cinco entidades principais, cujas relações e atributos foram definidos com base nas regras de negócio levantadas durante a análise.

| Entidade | Atributos |
| --- | --- |
| Motorista | id, nome, idade, sexo, empresa |
| Linha | id, nome, empresa, *paradas (lista enc.),*horarios (lista enc.) |
| Parada | id, nome, distancia_km, *proxima |
| Horario | id, hora, minuto, *proximo |
| Onibus | id, placa, modelo, ano, capacidade, id_linha, id_motorista |
| Empresa | id, nome |

As entidades `Parada` e `Horario` são armazenadas como listas encadeadas dentro de `Linha`, ordenadas automaticamente por distância e por horário, respectivamente. As demais entidades (`Linha`, `Motorista`, `Onibus` e `Empresa`) são armazenadas em arrays dinâmicos alocados com `malloc` e realocados com `realloc` conforme necessário.

---

## 3. Requisitos Funcionais

Os requisitos funcionais descrevem as operações que o sistema deve executar. Estão organizados por entidade e totalizam 29 requisitos.

### 3.1 Gestão de Linhas

| Código | Descrição |
| --- | --- |
| RF01 | O sistema deve permitir cadastrar uma linha informando número, nome e empresa operadora. |
| RF02 | O sistema deve permitir editar os dados de uma linha. |
| RF03 | O sistema deve permitir remover uma linha. |
| RF04 | O sistema deve listar todas as linhas cadastradas. |
| RF05 | O sistema deve permitir buscar uma linha por nome ou por empresa. |

### 3.2 Gestão de Paradas

| Código | Descrição |
| --- | --- |
| RF06 | O sistema deve permitir cadastrar uma parada em uma linha informando nome e distância em km desde a origem. |
| RF07 | O sistema deve inserir a parada automaticamente em ordem crescente de distância na lista da linha. |
| RF08 | O sistema deve permitir editar o nome de uma parada. |
| RF09 | O sistema deve permitir remover uma parada de uma linha. |
| RF10 | O sistema deve listar todas as paradas de uma linha em ordem de distância. |

### 3.3 Gestão de Horários

| Código | Descrição |
| --- | --- |
| RF11 | O sistema deve permitir cadastrar um horário associado a uma linha informando hora e minuto. |
| RF12 | O sistema deve inserir o horário automaticamente em ordem cronológica na lista da linha. |
| RF13 | O sistema deve permitir remover um horário de uma linha. |
| RF14 | O sistema deve listar todos os horários de uma linha em ordem cronológica. |

### 3.4 Gestão de Motoristas

| Código | Descrição |
| --- | --- |
| RF16 | O sistema deve permitir cadastrar um motorista informando nome, idade, sexo e empresa. |
| RF17 | O sistema deve permitir editar os dados de um motorista. |
| RF18 | O sistema deve permitir remover um motorista. |
| RF19 | O sistema deve listar todos os motoristas cadastrados. |
| RF20 | O sistema deve permitir buscar um motorista por nome ou por empresa. |

### 3.5 Gestão de Ônibus

| Código | Descrição |
| --- | --- |
| RF21 | O sistema deve permitir cadastrar um ônibus informando placa, modelo, ano, capacidade, linha e motorista. |
| RF22 | O sistema deve permitir editar os dados de um ônibus. |
| RF23 | O sistema deve permitir remover um ônibus. |
| RF24 | O sistema deve listar todos os ônibus cadastrados. |
| RF25 | O sistema deve permitir buscar um ônibus por placa ou por motorista. |

### 3.6 Cálculo de Tarifa

| Código | Descrição |
| --- | --- |
| RF26 | O sistema deve permitir calcular a tarifa de uma viagem informando a linha, a parada de embarque e a parada de desembarque. |
| RF27 | O sistema deve permitir calcular a tarifa para o percurso completo de uma linha. |
| RF28 | O sistema deve calcular a tarifa com base na diferença de distância em km entre a parada de embarque e a de desembarque. |
| RF29 | O sistema deve exibir o valor da tarifa calculada ao usuário. |

### 3.7 Gestão de Empresas

| Código | Descrição |
| --- | --- |
| RF30 | O sistema deve permitir cadastrar uma empresa informando nome. |
| RF31 | O sistema deve permitir editar os dados de uma empresa. |
| RF32 | O sistema deve permitir remover uma empresa. |
| RF33 | O sistema deve listar todas as empresas cadastradas. |
| RF34 | O sistema deve permitir buscar uma empresa por nome. |

---

## 4. Regras de Negócio

As regras de negócio definem as restrições que governam as operações do sistema e devem ser validadas pelos controllers antes de qualquer persistência em memória.

| Código | Descrição |
| --- | --- |
| RN01 | Uma parada pertence a apenas uma linha. |
| RN02 | Um ônibus opera em apenas uma linha. |

---

## 5. Requisitos Não-Funcionais

Os requisitos não-funcionais descrevem como o sistema deve se comportar, independentemente das funcionalidades.

| Código | Descrição |
| --- | --- |
| RNF01 | O sistema deve ser implementado em linguagem C. |
| RNF02 | O sistema deve utilizar listas encadeadas para armazenar paradas e horários de uma linha. |
| RNF03 | O sistema deve inserir paradas em ordem crescente de distância automaticamente, sem intervenção do usuário. |
| RNF04 | O sistema deve inserir horários em ordem cronológica automaticamente, sem intervenção do usuário. |
| RNF05 | O sistema deve ser operado via interface de menu no terminal. |
| RNF06 | O sistema deve liberar toda memória alocada dinamicamente ao encerrar. |
| RNF07 | O sistema deve alocar os arrays de entidades dinamicamente, iniciando com capacidade inicial pequena e realocando com `realloc` quando necessário. |
| RNF08 | O sistema deve liberar os arrays dinâmicos ao encerrar, além de toda memória das listas encadeadas. |

---

## 6. Arquitetura do Sistema

O sistema adota uma arquitetura inspirada no padrão MVC adaptado para C, separando claramente as responsabilidades em três camadas: models (structs), controllers (funções) e interface (menu no terminal).

### 6.1 Estrutura de Arquivos

```txt
transporte/
├── main.c
├── Makefile
├── database/
│   ├── database.h
│   └── database.c
├── includes/
│   ├── models/
│   │   ├── linha.h
│   │   ├── parada.h
│   │   ├── horario.h
│   │   ├── onibus.h
│   │   └── motorista.h
│   └── controllers/
│       ├── linha_controller.h
│       ├── parada_controller.h
│       ├── horario_controller.h
│       ├── onibus_controller.h
│       ├── motorista_controller.h
│       └── tarifa_controller.h
└── src/
    ├── linha_controller.c
    ├── parada_controller.c
    ├── horario_controller.c
    ├── onibus_controller.c
    ├── motorista_controller.c
    └── tarifa_controller.c
```

### 6.2 Camadas

#### Models (`includes/models/`)

Contêm apenas as declarações de structs. Cada header define uma entidade e inclui os headers das entidades das quais depende. Todos utilizam include guards (`#ifndef / #define / #endif`) para evitar inclusão dupla.

#### Controllers (`includes/controllers/` + `src/`)

Os headers declaram as assinaturas das funções de cada entidade. Os arquivos `.c` em `src/` contêm a implementação. Cada controller inclui `database.h` para acessar o estado global e o próprio model correspondente.

#### Database (`database/`)

Centraliza o estado global do sistema. O arquivo `database.h` declara ponteiros para os arrays dinâmicos e os contadores de registros com `extern`. O `database.c` inicializa esses ponteiros com `malloc` numa função `db_init()` e os libera numa função `db_free()`. Isso garante que todos os controllers acessem os mesmos dados sem duplicação.

#### `main.c`

Responsável apenas pelo loop principal do menu. Inicializa o sistema, exibe as opções ao usuário e despacha para o controller correspondente a cada operação selecionada.

### 6.3 Fluxo de Dependências

```txt
main.c           →  database.h, todos os controller headers
controller .c    →  database.h, model header correspondente
database.h       →  models de Linha, Onibus e Motorista
linha.h          →  parada.h, horario.h
parada.h         →  (auto-referência via ponteiro)
horario.h        →  (auto-referência via ponteiro)
```

---

*Documento gerado durante sessão de análise e planejamento.*
