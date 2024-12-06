
# Sun Wukong: Rebelião Contra os Céus

## Descrição

O projeto Sun Wukong é um jogo desenvolvido na plataforma Unity, inspirado na jornada lendária do Rei Macaco, Sun Wukong, através de terras místicas na Ásia. O jogo adota o estilo roguelike, no qual o jogador enfrenta uma série de salas geradas proceduralmente, cada uma oferecendo desafios únicos e crescentes. 

Para a criação do mapa e das mecânicas de desafio do jogo, o projeto utiliza grafos para criar combinações aleatórias de salas e o algoritmo de pathfinding A* para que haja uma etapa adicional com o 8Puzzle antes do desafio final de confronto com o boss, tornando o jogo mais dinâmico e desafiador.

## Alunos integrantes da equipe

* Alexandre Augusto Niess Ferreira
* Andre Mendes Rodrigues
* Arthur Martinho Medeiros Oliveira
* Caio Gomes Alcântara Glória
* Daniel Salgado Magalhães
* Rafael Maluf Araujo
* Samuel Correia Pedrosa

## Professores responsáveis

* Artur Martins Mol
* Cristiane Neri Nobre
* Cristiano Neves Rodrigues
* Pedro
* Rosilane Ribeiro da Mota


## Estrutura do Projeto

Abaixo está uma descrição da estrutura de pastas para facilitar a navegação e entendimento do projeto:

- **Assets/**: Contém todos os arquivos de recursos do jogo, incluindo scripts, modelos 3D, texturas, sons e animações.
- **Logs/**: Armazena arquivos de log para rastreamento e solução de problemas durante o desenvolvimento.
- **Packages/**: Inclui pacotes adicionais e dependências que o projeto utiliza.
- **ProjectSettings/**: Contém as configurações globais do projeto Unity.
- **UserSettings/**: Armazena as preferências de usuário para o projeto.
- **obj/Debug/**: Pasta de build de depuração que contém arquivos temporários gerados durante o processo de compilação.

### Arquivos Principais

- **Assembly-CSharp.csproj**: Arquivo de configuração de projeto C#, responsável por compilar os scripts do jogo.
- **AstarPathfindingProject.csproj**: Contém a implementação do algoritmo de pathfinding A* para o comportamento de perseguição dos inimigos.
- **PackageToolsEditor.csproj**: Scripts e ferramentas editoriais adicionais que facilitam o desenvolvimento no Unity.
- **SunWukong.sln** e **SunWukong - Copia.sln**: Arquivos de solução para organizar os scripts e componentes do projeto no Visual Studio.

## Funcionalidades

- **Exploração de Salas**: O jogador navega por salas geradas proceduralmente, cada uma com diferentes inimigos e desafios.
- **8Puzzle através de IA***: Ao limpar toda dungeon, o player encontra uma estátua sagrada, que ao ser tocada, libera o 8Puzzle para ser resolvido. Ao concluir o 8Puzzle, o player consegue enfrentar o boss final e terminar o jogo.
- **Combinações de Salas com Grafos**: Através do uso de grafos, as combinações de salas são geradas de forma a criar diferentes percursos e desafios a cada nova partida.

## Instalação

1. **Clonar o repositório**:
   ```bash
   git clone https://github.com/seuusuario/sun-wukong.git
   ```
2. **Abrir o projeto no Unity**:
   Abra o Unity Hub, selecione "Add" e escolha a pasta raiz do projeto clonado.

## Como Jogar

1. **Executar o projeto**: Após abrir o projeto no Unity, selecione o botão de play na barra superior para iniciar o jogo no modo editor.
2. **Controles Básicos**:
   - **Movimento**: Utilize as teclas WASD ou as setas para mover o personagem.
   - **Ataque**: Pressione a barra de espaço para atacar os inimigos.
   - **Habilidade**: Pressiona a tecla 'F' para ativar a habilidade "Rigidez de Pedra", permitindo que o player tome menos dano, em troca de uma velocidade reduzida.
3. **Objetivo**: Navegue pelas salas e enfrente inimigos enquanto explora o místico mundo de Sun Wukong.

## Contribuições

Sinta-se à vontade para contribuir com o projeto através de pull requests. Por favor, verifique primeiro as issues para alinhar os esforços de desenvolvimento.

## Licença

Este projeto está licenciado sob os termos da [MIT License](./LICENSE).

