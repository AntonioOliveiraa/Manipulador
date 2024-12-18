# Manipulador

![Status do Projeto](https://img.shields.io/badge/status-concluído-brightgreen)

## Índice

- [Descrição do Projeto](#descrição-do-projeto)
- [Objetivo](#objetivo)
- [Funcionalidades](#funcionalidades)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Instalação](#instalação)
- [Como Usar](#como-usar)
- [Branches](#branches)
- [Tecnologias Utilizadas](#tecnologias-utilizadas)
- [Pinagem e Ligação dos Componentes](#pinagem-e-ligação-dos-componentes)
- [Contribuidores](#contribuidores)
- [Licença](#licença)

## Descrição do Projeto

Este projeto consiste no desenvolvimento de um braço robótico manipulador capaz de pegar três objetos e colocá-los dentro de uma caixa. Foi realizado como parte da avaliação da disciplina de Robótica do curso de Engenharia da Computação da Universidade Estadual do Maranhão (UEMA).

## Objetivo

O objetivo principal é aplicar conceitos de robótica para montar e programar um braço manipulador que execute tarefas de manipulação de objetos de forma autônoma.

## Funcionalidades

- Manipulação e transporte dos objetos até uma caixa de destino.
- Execução autônoma das tarefas programadas.

## Estrutura do Projeto

A estrutura de diretórios do projeto é organizada da seguinte forma:

```
Manipulador/
├── include/            # Arquivos de cabeçalho
├── lib/                # Bibliotecas externas
├── src/                # Código-fonte principal
├── test/               # Testes unitários
├── .gitignore          # Arquivos e diretórios ignorados pelo Git
└── platformio.ini      # Arquivo de configuração do PlatformIO
```

## Instalação

1. Clone este repositório para sua máquina local:

   ```bash
   git clone https://github.com/AntonioOliveiraa/Manipulador.git
   ```

2. Certifique-se de ter o [PlatformIO](https://platformio.org/) instalado.

3. Abra o projeto no seu ambiente de desenvolvimento integrado (IDE) preferido.

4. Conecte o dispositivo de hardware apropriado para o braço manipulador.

5. Compile e faça o upload do código para o dispositivo.

## Como Usar

1. Após a instalação, ligue o braço manipulador.
2. Faça o mapeamento dos movimentos necessários para o braço pegar cada objeto.
3. Insira o ângulo de cada movimento chamando a função `moveServo()` e passando como argumentos o servo e o ângulo.
4. O braço pegará cada objeto identificado e o colocará na caixa designada.

## Branches

O repositório possui as seguintes branches, cada uma com funcionalidades específicas:

- **master**: Contém a versão estável mais recente do projeto.
- **menu-control**: Implementa um menu interativo para controle do braço manipulador, permitindo selecionar diferentes modos de operação.
- **serial-monitor-control**: Adiciona funcionalidades para controle e monitoramento do braço via Serial Monitor, facilitando o diagnóstico, mapeamento de movimentos e execução de comandos.

## Tecnologias Utilizadas

- Linguagem de Programação: C++
- Plataforma de Desenvolvimento: [PlatformIO](https://platformio.org/)
- Hardware: Arduino Uno, Micro Servo SG90 e fonte de alimentação externa.

## Pinagem e Ligação dos Componentes

### Micro Servo SG90

O projeto utiliza **quatro micro servos SG90** para controlar diferentes partes do braço manipulador. A pinagem e a conexão dos servos estão configuradas da seguinte maneira no código:

```cpp
myservo1.attach(9);  // Conecta o servo no pino 9 (esquerdo) ao objeto servo
myservo2.attach(10); // Conecta o servo no pino 10 (direito) ao objeto servo
myservo3.attach(11); // Conecta o servo no pino 11 (garra) ao objeto servo
myservo4.attach(6);  // Conecta o servo no pino 6 (base) ao objeto servo
```

| **Componente**           | **Pino no Arduino** | **Descrição**               |
|--------------------------|---------------------|-----------------------------|
| Micro Servo SG90 (esquerdo) | 9                   | Movimento do braço esquerdo  |
| Micro Servo SG90 (direito) | 10                  | Movimento do braço direito  |
| Micro Servo SG90 (garra)   | 11                  | Abertura/fechamento da garra |
| Micro Servo SG90 (base)    | 6                   | Rotação da base              |

### Fonte de Alimentação

- **Fonte externa de 12V**: Utilizada para alimentar os **micro servos SG90**.
- **Regulador de tensão**: Um regulador foi utilizado para **reduzir a tensão de 12V para 5V**, que é a tensão de operação dos micro servos SG90.
- **GND comum**: O **GND** da fonte externa de 12V foi conectado ao **GND do Arduino** para garantir um circuito fechado e um referencial comum.

### Diagrama de Ligação (simplificado)

```
Fonte 12V
    |                
    |--> Regulador de Tensão --> 5V --> VCC dos Micro Servos SG90
    |                                  
    |--> GND --------------------------> GND (comum Arduino e Servos)
    
Arduino
    Pins 9, 10, 11, 6 -----------------> Sinal (Servos: esquerdo, direito, garra, base)
```

## Contribuidores

- [Antônio Oliveira](https://github.com/AntonioOliveiraa)
- [Gustavo Marques](https://github.com/GMFK00)
- [José Muniz](https://github.com/ribamarmuniz)
- [Victor Wendel](https://github.com/MonkeyTecno)

## Licença

Este projeto está licenciado sob a Licença MIT. Consulte o arquivo [LICENSE](LICENSE) para mais informações.
