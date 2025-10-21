# Agente de Configuração - Projeto C++

    1. "Primeiro, faça um planejamento de como isso deve ser implementado e me apresente para aprovação.
    
    2. Após a aprovação, crie uma lista de tarefas e execute cada uma delas em ordem."
    
    3. Não crie documentação excessiva, como arquivos Markdown ou de instalação. Gere apenas o código necessário para criar o aplicativo. 

    4. Utilize as melhores práticas de Engenharia de Software na codificação 


## 📋 Informações do Projeto

**Nome:** Calculadora C++  
**Tipo:** Aplicação Console C++  
**Versão:** 1.0.0  
**Data de Criação:** 17 de Outubro de 2025  
**Linguagem:** C++17 ou superior  

---

## 🎯 Objetivo do Projeto

Desenvolver uma calculadora em C++ com operações matemáticas básicas e avançadas, seguindo boas práticas de programação e padrões modernos de C++.

---

## 🏗️ Estrutura de Diretórios

```
calculadora/
├── src/                    # Código fonte
│   ├── main.cpp           # Ponto de entrada da aplicação
│   ├── calculator.cpp     # Implementação da calculadora
│   └── utils.cpp          # Funções utilitárias
├── include/               # Arquivos de cabeçalho
│   ├── calculator.h       # Interface da calculadora
│   └── utils.h            # Declarações de utilitários
├── tests/                 # Testes unitários
│   └── test_calculator.cpp
├── build/                 # Arquivos de build (gerado)
├── bin/                   # Executáveis (gerado)
├── docs/                  # Documentação
├── CMakeLists.txt        # Configuração CMake
├── README.md             # Documentação principal
├── .gitignore            # Arquivos ignorados pelo Git
└── agente.md             # Este arquivo
```

---

## 🔧 Configuração do Ambiente

### Requisitos do Sistema

- **Compilador:** 
  - GCC 9.0+ / MinGW (Windows)
  - Clang 10.0+
  - MSVC 2019+ (Visual Studio)
  
- **Build System:** CMake 3.15+

- **Ferramentas Opcionais:**
  - Git para controle de versão
  - Doxygen para documentação
  - GTest para testes unitários

### Instalação no Windows

```powershell
# Instalar MinGW ou MSVC
# Instalar CMake: https://cmake.org/download/

# Verificar instalação
g++ --version
cmake --version
```

---

## 🚀 Comandos de Build

### Compilação Manual (g++)

```powershell
# Compilar arquivo único
g++ -std=c++17 src/main.cpp -o bin/calculadora.exe

# Compilar múltiplos arquivos
g++ -std=c++17 -I include src/*.cpp -o bin/calculadora.exe

# Com otimização
g++ -std=c++17 -O2 -I include src/*.cpp -o bin/calculadora.exe

# Com debug
g++ -std=c++17 -g -I include src/*.cpp -o bin/calculadora.exe
```

### Usando CMake

```powershell
# Criar diretório de build
mkdir build ; cd build

# Configurar projeto
cmake ..

# Compilar
cmake --build .

# Executar
.\bin\calculadora.exe
```

---

## 📝 Padrões de Código

### Convenções de Nomenclatura

- **Classes:** PascalCase (ex: `Calculator`, `MathUtils`)
- **Funções:** camelCase (ex: `calculateSum`, `getResult`)
- **Variáveis:** camelCase (ex: `userInput`, `resultValue`)
- **Constantes:** UPPER_SNAKE_CASE (ex: `MAX_VALUE`, `PI`)
- **Arquivos:** snake_case (ex: `calculator.cpp`, `math_utils.h`)

### Estilo de Código

```cpp
// Exemplo de estrutura recomendada
class Calculator {
private:
    double result;
    
public:
    Calculator();
    ~Calculator();
    
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    
    double getResult() const;
    void clearResult();
};
```

---

## 🎨 Funcionalidades Planejadas

### Fase 1: Operações Básicas
- [x] Adição (+)
- [x] Subtração (-)
- [x] Multiplicação (*)
- [x] Divisão (/)

### Fase 2: Operações Avançadas
- [ ] Potenciação (^)
- [ ] Raiz quadrada (√)
- [ ] Operações trigonométricas (sen, cos, tan)
- [ ] Logaritmos

### Fase 3: Interface
- [ ] Menu interativo
- [ ] Histórico de operações
- [ ] Modo científico
- [ ] Suporte a expressões complexas

### Fase 4: Recursos Extras
- [ ] Salvamento de histórico
- [ ] Suporte a variáveis
- [ ] Modo RPN (Reverse Polish Notation)

---

## 🧪 Testes

### Estrutura de Testes

```cpp
// Exemplo usando assertions simples
void testAddition() {
    Calculator calc;
    assert(calc.add(2, 3) == 5);
    assert(calc.add(-1, 1) == 0);
}

void testDivision() {
    Calculator calc;
    assert(calc.divide(10, 2) == 5);
    // Teste de divisão por zero
}
```

### Executar Testes

```powershell
# Compilar testes
g++ -std=c++17 -I include tests/test_calculator.cpp src/calculator.cpp -o bin/tests.exe

# Executar
.\bin\tests.exe
```

---

## 📚 Dependências

### Bibliotecas Padrão C++
- `<iostream>` - Entrada/saída
- `<cmath>` - Funções matemáticas
- `<string>` - Manipulação de strings
- `<vector>` - Containers dinâmicos
- `<stdexcept>` - Exceções

### Bibliotecas Externas (Opcionais)
- **Google Test** - Framework de testes
- **Boost** - Bibliotecas auxiliares
- **fmt** - Formatação moderna

---

## 🐛 Tratamento de Erros

### Diretrizes

1. Usar exceções para erros críticos
2. Validar entradas do usuário
3. Tratar divisão por zero
4. Verificar overflow/underflow
5. Mensagens de erro claras e em português

```cpp
// Exemplo
double divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Erro: Divisão por zero não permitida!");
    }
    return a / b;
}
```

---

## 📖 Documentação

### Comentários no Código

```cpp
/**
 * @brief Realiza a adição de dois números
 * @param a Primeiro operando
 * @param b Segundo operando
 * @return Soma de a e b
 */
double add(double a, double b);
```

### Gerar Documentação

```powershell
# Usando Doxygen (se instalado)
doxygen Doxyfile
```

---

## 🔄 Controle de Versão

### Git Workflow

```powershell
# Inicializar repositório
git init

# Adicionar arquivos
git add .

# Commit inicial
git commit -m "feat: Initial project setup"

# Criar branch para nova feature
git checkout -b feature/advanced-operations
```

### Mensagens de Commit

- `feat:` Nova funcionalidade
- `fix:` Correção de bug
- `docs:` Documentação
- `style:` Formatação
- `refactor:` Refatoração
- `test:` Testes
- `chore:` Tarefas gerais

---

## 🔒 Segurança e Qualidade

### Checklist de Qualidade

- [ ] Código compila sem warnings
- [ ] Testes passam
- [ ] Sem memory leaks (usar valgrind ou sanitizers)
- [ ] Documentação atualizada
- [ ] Código revisado
- [ ] Performance aceitável

### Compilar com Warnings

```powershell
g++ -std=c++17 -Wall -Wextra -Werror -I include src/*.cpp -o bin/calculadora.exe
```

---

## 🎯 Metas de Desenvolvimento

### Curto Prazo (1-2 semanas)
- Implementar operações básicas
- Criar interface de console
- Adicionar testes básicos

### Médio Prazo (1 mês)
- Operações avançadas
- Sistema de histórico
- Melhorar interface

### Longo Prazo (3 meses)
- GUI (interface gráfica) opcional
- Plugin system
- Modo programador (hex, bin, oct)

---

## 📞 Suporte e Referências

### Documentação C++
- [cppreference.com](https://en.cppreference.com/)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/)
- [CMake Documentation](https://cmake.org/documentation/)

### Comunidade
- Stack Overflow
- Reddit: r/cpp
- Discord: C++ Brasil

---

## 📝 Notas do Agente

### Decisões de Design

1. **Linguagem:** C++17 escolhido por balancear modernidade e compatibilidade
2. **Arquitetura:** Separação clara entre lógica e interface
3. **Build System:** CMake para portabilidade multiplataforma

### Próximos Passos

1. Criar estrutura básica de diretórios
2. Implementar classe Calculator com operações básicas
3. Criar main.cpp com menu interativo
4. Adicionar CMakeLists.txt
5. Escrever README.md
6. Implementar testes

### Observações Importantes

- Sempre compilar com `-std=c++17` no mínimo
- Manter compatibilidade com Windows (PowerShell)
- Priorizar clareza sobre otimização prematura
- Documentar decisões importantes
- Manter código modular e testável

---

## 🔄 Histórico de Mudanças

| Data | Versão | Descrição |
|------|--------|-----------|
| 2025-10-17 | 1.0.0 | Criação inicial do documento de configuração |

---

**Última atualização:** 17 de Outubro de 2025  
**Mantido por:** Agente de Desenvolvimento C++
