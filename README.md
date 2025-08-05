# 🎯 So Long - Reborn's Training Mission

<div align="center">

![simplescreenrecorder-2024-04-09_17 26 50-ezgif com-video-to-gif-converter](https://github.com/CarolShingai/so_long/assets/72236332/f77c9167-b1ac-48f6-bb71-37a173c7b58a)

**Um jogo 2D inspirado no universo de Katekyo Hitman Reborn!**

*"Ciaossu! É hora do treinamento especial do Reborn!"*

[![Made with C](https://img.shields.io/badge/Made%20with-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![42 School](https://img.shields.io/badge/42-School-000000.svg)](https://42.fr)
[![MLX42](https://img.shields.io/badge/Graphics-MLX42-green.svg)](https://github.com/codam-coding-college/MLX42)

</div>

## 📖 Sobre o Projeto

So Long é um jogo 2D desenvolvido em C como parte do currículo da 42 School. Inspirado no personagem icônico **Reborn** do anime "Katekyo Hitman Reborn!", o jogador controla o pequeno hitman mais temido da máfia italiana em uma missão de coleta e escape.

### 🎭 História

Você é **Reborn**, o lendário Arcobaleno do Sol, e foi designado para uma missão especial. Navegue pelos labirintos coletando todos os **itens de treinamento** (representados por caixas) antes de encontrar a saída. Mas cuidado! Os **fantasmas da família Vongola** (inimigos) estão patrulhando a área. Um encontro com eles significa o fim da missão!

## ✨ Funcionalidades

### 🎮 Versão Base
- **Controles intuitivos**: WASD ou setas direcionais
- **Coleta de itens**: Colete todas as caixas de treinamento
- **Sistema de saída**: A saída só é liberada após coletar todos os itens
- **Contador de movimentos**: Acompanhe sua eficiência
- **Validação de mapas**: Sistema robusto de validação de níveis

### 🌟 Versão Bonus
- **Animações fluidas**: Reborn ganha vida com sprites animados
- **Inimigos animados**: Fantasmas da família Vongola com animação
- **Interface aprimorada**: Contador de movimentos na tela
- **Sprites direcionais**: Reborn vira conforme a direção do movimento
- **Mensagens de vitória/derrota**: Feedback visual imersivo

## 🎯 Como Jogar

### Controles
- **W/↑**: Mover para cima
- **A/←**: Mover para esquerda
- **S/↓**: Mover para baixo
- **D/→**: Mover para direita
- **ESC**: Sair do jogo

### Objetivo
1. **Colete** todas as caixas de treinamento (C) espalhadas pelo mapa
2. **Evite** os fantasmas da família Vongola (V) - versão bonus
3. **Alcance** a saída (E) após coletar todos os itens
4. **Complete** a missão com o menor número de movimentos possível!

## 🛠️ Instalação e Compilação

### Pré-requisitos
```bash
# Ubuntu/Debian
sudo apt-get update
sudo apt-get install build-essential libglfw3-dev cmake

# macOS
brew install glfw cmake
```

### Compilação
```bash
# Clone o repositório
git clone https://github.com/CarolShingai/so_long.git
cd so_long

# Compile a versão base
make

# Ou compile a versão bonus
make bonus

# Execute o jogo
./so_long maps/valid/valid_map_1.ber

# Versão bonus
./so_long_bonus maps/bonus/valid_map_bonus_1.ber
```

### Comandos Disponíveis
```bash
make           # Compila a versão base
make bonus     # Compila a versão bonus
make clean     # Remove arquivos objeto
make fclean    # Remove executáveis e objetos
make re        # Recompila tudo
```

## 🗺️ Formato dos Mapas

Os mapas são arquivos `.ber` com a seguinte estrutura:

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

### Elementos do Mapa
- **1**: Parede (impenetrável)
- **0**: Espaço vazio (chão)
- **P**: Posição inicial do Reborn
- **E**: Saída da missão
- **C**: Caixas de treinamento (coletáveis)
- **V**: Fantasmas da família Vongola (inimigos - apenas bonus)

### Regras de Validação
- ✅ Mapa deve ser retangular
- ✅ Bordas devem ser compostas apenas de paredes (1)
- ✅ Deve conter exatamente 1 jogador (P) e 1 saída (E)
- ✅ Deve conter pelo menos 1 coletável (C)
- ✅ Deve existir um caminho válido entre P, todos os C's e E
- ✅ Não pode conter linhas vazias

## 🎨 Assets e Sprites

O jogo conta com sprites customizados inspirados no universo de Katekyo Hitman Reborn:

### 🤵 Reborn (Personagem Principal)
- `reborn_R1.png`, `reborn_R2.png`, `reborn_R3.png` - Movimentação para direita
- `reborn_L1.png`, `reborn_L2.png`, `reborn_L3.png` - Movimentação para esquerda
- `reborn_1.png` - Sprite padrão

### 👻 Inimigos (Versão Bonus)
- `ghost1.png` - `ghost4.png` - Fantasmas animados da família Vongola

### 🌍 Ambiente
- `grass_tile.png` - Piso do jogo
- `BrickHouse.png` - Paredes do labirinto
- `collectable.png` - Caixas de treinamento

### 📱 Interface
- `win_msg.png` - Mensagem de vitória
- `death_msg.png` - Mensagem de derrota
- `icon.png` - Ícone da janela

## 🏗️ Estrutura do Projeto

```
so_long/
├── srcs/                   # Código fonte versão base
├── srcs_bonus/            # Código fonte versão bonus
├── includes/              # Headers do projeto
├── lib/                   # Bibliotecas externas
│   ├── libft/            # Biblioteca C personalizada
│   ├── ft_printf/        # Função printf personalizada
│   └── MLX42/            # Biblioteca gráfica
├── maps/                  # Mapas do jogo
│   ├── valid/            # Mapas válidos
│   ├── bonus/            # Mapas para versão bonus
│   └── unvalid/          # Mapas inválidos (testes)
├── sprites/              # Assets gráficos
│   └── reborn/          # Sprites do Reborn
└── Makefile              # Script de compilação
```

## 🧪 Testes

O projeto inclui mapas de teste para validação:

```bash
# Teste mapas válidos
./so_long maps/valid/valid_map_1.ber
./so_long maps/valid/valid_map_2.ber

# Teste versão bonus
./so_long_bonus maps/bonus/valid_map_bonus_1.ber

# Teste validação de erros
./so_long maps/unvalid/unvalid_map_border.ber
```

## 🎓 Conceitos Aprendidos

- **Programação em C**: Gerenciamento de memória, ponteiros, estruturas
- **Gráficos 2D**: Renderização, sprites, animações
- **Algoritmos**: Flood fill para validação de caminhos
- **Arquitetura de Software**: Organização modular do código
- **Manipulação de Arquivos**: Leitura e parsing de mapas
- **Tratamento de Eventos**: Input do usuário, loops de jogo

## 📋 Requisitos Técnicos

### Obrigatórios
- ⚡ Linguagem: C
- 🎮 Biblioteca gráfica: MLX42
- 🗂️ Compilação: Makefile
- 🚫 Sem vazamentos de memória
- 📝 Norma da 42 School
- ⌨️ Controles responsivos

### Bonus Implementados
- ✨ Animações de sprites
- 👹 Sistema de inimigos
- 📊 Interface de usuário
- 🎯 Contador de movimentos na tela

## 🤝 Contribuição

Este projeto foi desenvolvido como parte do currículo da 42 School. Sugestões e melhorias são bem-vindas!

## 📄 Licença

Este projeto está sob a licença da 42 School. Desenvolvido para fins educacionais.

---

<div align="center">

**"Reborn nunca falha em uma missão. E você?"**

*Desenvolvido com 💜 por [Carol Shingai](https://github.com/CarolShingai)*

**Ciaossu!** 🎯

</div>
