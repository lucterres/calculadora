# 🧮 Calculadora C++

Uma calculadora em C++ com operações básicas e avançadas, desenvolvida seguindo as melhores práticas de Engenharia de Software e utilizando C++17.

## 📋 Funcionalidades

- ✅ **Operações Básicas**
  - Adição (+)
  - Subtração (-)
  - Multiplicação (*)
  - Divisão (/) com tratamento de divisão por zero

- ✅ **Operações Avançadas**
  - Potenciação (^)
  - Raiz Quadrada (√) com validação de números negativos

- ✅ **Recursos Adicionais**
  - Interface interativa em português
  - Armazenamento do último resultado
  - Tratamento robusto de erros
  - Validação de entradas

## 🏗️ Estrutura do Projeto

```
calculadora2/
├── src/                    # Código fonte
│   ├── main.cpp           # Ponto de entrada e interface do usuário
│   ├── calculator.cpp     # Implementação das operações
│   └── utils.cpp          # Funções utilitárias
├── include/               # Arquivos de cabeçalho
│   ├── calculator.h       # Interface da classe Calculator
│   └── utils.h            # Declarações de utilitários
├── bin/                   # Executáveis compilados
├── build/                 # Arquivos de build (CMake)
├── CMakeLists.txt        # Configuração do CMake
├── .gitignore            # Arquivos ignorados pelo Git
└── README.md             # Este arquivo
```

## 🔧 Requisitos

- **Compilador C++:** GCC 9.0+, Clang 10.0+, ou MSVC 2019+
- **CMake:** Versão 3.15 ou superior
- **Sistema Operacional:** Windows, Linux, ou macOS

## 🚀 Compilação e Execução

### Windows (PowerShell)

```powershell
# Clone o repositório
git clone https://github.com/lucterres/calculadora.git
cd calculadora

# Crie o diretório de build
mkdir build
cd build

# Configure o projeto com CMake
cmake ..

# Compile o projeto
cmake --build . --config Release

# Execute a calculadora
cd ..
.\bin\calculadora.exe
```

### Linux/macOS

```bash
# Clone o repositório
git clone https://github.com/lucterres/calculadora.git
cd calculadora

# Crie o diretório de build
mkdir build
cd build

# Configure e compile
cmake ..
make

# Execute a calculadora
cd ..
./bin/calculadora
```

## 💻 Uso

Ao executar o programa, você verá um menu interativo:

```
========================================
        CALCULADORA C++                 
========================================
 1. Adicao (+)
 2. Subtracao (-)
 3. Multiplicacao (*)
 4. Divisao (/)
 5. Potenciacao (^)
 6. Raiz Quadrada (sqrt)
 7. Limpar Resultado
 8. Mostrar Ultimo Resultado
 0. Sair
========================================
```

Escolha uma opção digitando o número correspondente e siga as instruções na tela.

## 🎨 Exemplos

### Adição
```
=== ADICAO ===
Digite o primeiro numero: 5
Digite o segundo numero: 3

Resultado: 5 + 3 = 8.0000
```

### Potenciação
```
=== POTENCIACAO ===
Digite a base: 2
Digite o expoente: 8

Resultado: 2 ^ 8 = 256.0000
```

### Raiz Quadrada
```
=== RAIZ QUADRADA ===
Digite o numero: 16

Resultado: sqrt(16) = 4.0000
```

## 🛡️ Tratamento de Erros

A calculadora possui tratamento robusto de erros:

- **Divisão por zero:** Exibe mensagem de erro apropriada
- **Raiz de número negativo:** Impede operação e notifica o usuário
- **Entrada inválida:** Solicita nova entrada até receber um valor válido

## 🏛️ Arquitetura

O projeto segue os princípios de **separação de responsabilidades**:

- **`Calculator`**: Classe responsável por todas as operações matemáticas
- **`Utils`**: Funções auxiliares para interface e validação
- **`main`**: Controle do fluxo principal e interação com o usuário

## 🧪 Compilação com Warnings

Para compilação com verificações adicionais:

```bash
# GCC/Clang
g++ -std=c++17 -Wall -Wextra -pedantic -I include src/*.cpp -o bin/calculadora

# MSVC
cl /std:c++17 /W4 /I include src\*.cpp /Fe:bin\calculadora.exe
```

## 📝 Padrões de Código

- **Padrão C++:** C++17
- **Nomenclatura:**
  - Classes: `PascalCase`
  - Funções/Variáveis: `camelCase`
  - Constantes: `UPPER_SNAKE_CASE`
- **Documentação:** Comentários em português
- **Tratamento de Erros:** Uso de exceções (`std::invalid_argument`)

## 🤝 Contribuindo

Contribuições são bem-vindas! Sinta-se à vontade para:

1. Fazer um fork do projeto
2. Criar uma branch para sua feature (`git checkout -b feature/NovaFuncionalidade`)
3. Commit suas mudanças (`git commit -m 'Adiciona nova funcionalidade'`)
4. Push para a branch (`git push origin feature/NovaFuncionalidade`)
5. Abrir um Pull Request

## 📄 Licença

Este projeto é de código aberto e está disponível para uso educacional.

## 👤 Autor

**Lucas Terres** - [@lucterres](https://github.com/lucterres)

## 🌟 Agradecimentos

Desenvolvido como parte de um projeto de estudo de C++ e boas práticas de programação.

---

⭐ Se este projeto foi útil para você, considere dar uma estrela no repositório!
