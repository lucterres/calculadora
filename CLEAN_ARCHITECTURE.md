# 🏗️ PLANO DE REFATORAÇÃO - CLEAN ARCHITECTURE

## 🎯 Objetivo
Refatorar a calculadora aplicando princípios de **Clean Architecture**, separando responsabilidades em camadas bem definidas.

## 📐 Nova Estrutura de Camadas

```
calculadora2/
├── src/
│   ├── domain/              # Camada de Domínio (Entities)
│   │   ├── Operation.cpp
│   │   └── CalculationResult.cpp
│   ├── usecases/           # Camada de Casos de Uso
│   │   ├── ExecuteOperationUseCase.cpp
│   │   └── GetLastResultUseCase.cpp
│   ├── interfaces/         # Portas (Interfaces)
│   │   └── (apenas headers)
│   ├── infrastructure/     # Adaptadores de Infraestrutura
│   │   └── InMemoryCalculatorRepository.cpp
│   ├── presentation/       # Adaptadores de Apresentação
│   │   ├── ConsolePresenter.cpp
│   │   └── ConsoleInputHandler.cpp
│   └── main.cpp           # Composition Root
├── include/
│   ├── domain/
│   │   ├── Operation.h
│   │   └── CalculationResult.h
│   ├── usecases/
│   │   ├── ExecuteOperationUseCase.h
│   │   └── GetLastResultUseCase.h
│   ├── interfaces/
│   │   ├── ICalculatorRepository.h
│   │   └── IPresenter.h
│   ├── infrastructure/
│   │   └── InMemoryCalculatorRepository.h
│   └── presentation/
│       ├── ConsolePresenter.h
│       └── ConsoleInputHandler.h
```

## 🔄 Camadas da Clean Architecture

### 1️⃣ **Domain (Núcleo)**
**Responsabilidade:** Regras de negócio puras, sem dependências externas

#### Entities:
- **`Operation`**: Representa uma operação matemática
  - Atributos: tipo de operação, operandos
  - Validações: divisão por zero, raiz de negativo
  - Métodos: `getType()`, `getOperand1()`, `getOperand2()`, `isValid()`

- **`CalculationResult`**: Encapsula o resultado de uma operação
  - Atributos: sucesso/falha, valor, mensagem de erro
  - Factory methods: `Success()`, `Failure()`
  - Métodos: `isSuccess()`, `getValue()`, `getErrorMessage()`

**Princípios aplicados:**
- ✅ Sem dependências externas
- ✅ Lógica de negócio pura
- ✅ Imutabilidade quando possível
- ✅ Validações centralizadas

---

### 2️⃣ **Use Cases (Casos de Uso)**
**Responsabilidade:** Orquestrar a lógica de aplicação

#### `ExecuteOperationUseCase`
- **Entrada:** `Operation`
- **Saída:** `CalculationResult`
- **Fluxo:**
  1. Valida a operação
  2. Executa o cálculo usando regras do domínio
  3. Salva o resultado no repositório
  4. Retorna `CalculationResult`

#### `GetLastResultUseCase`
- **Entrada:** Nenhuma
- **Saída:** `std::optional<double>`
- **Fluxo:**
  1. Busca último resultado no repositório
  2. Retorna valor ou vazio

**Princípios aplicados:**
- ✅ Single Responsibility
- ✅ Depende apenas de interfaces
- ✅ Testável isoladamente
- ✅ Sem conhecimento de UI ou DB

---

### 3️⃣ **Interfaces (Ports)**
**Responsabilidade:** Definir contratos entre camadas

#### `ICalculatorRepository`
Interface para persistência de dados:
```cpp
class ICalculatorRepository {
public:
    virtual void saveLastResult(double value) = 0;
    virtual std::optional<double> getLastResult() const = 0;
    virtual void clearLastResult() = 0;
    virtual ~ICalculatorRepository() = default;
};
```

#### `IPresenter`
Interface para apresentação:
```cpp
class IPresenter {
public:
    virtual void presentResult(const CalculationResult& result) = 0;
    virtual void presentMessage(const std::string& message) = 0;
    virtual void presentMenu() = 0;
    virtual void clearScreen() = 0;
    virtual void pause() = 0;
    virtual ~IPresenter() = default;
};
```

**Princípios aplicados:**
- ✅ Interface Segregation
- ✅ Dependency Inversion
- ✅ Permite múltiplas implementações
- ✅ Facilita testes com mocks

---

### 4️⃣ **Infrastructure (Adaptadores)**
**Responsabilidade:** Implementar acesso a recursos externos

#### `InMemoryCalculatorRepository`
- Implementa `ICalculatorRepository`
- Armazena último resultado em memória
- Pode ser facilmente substituído por implementação com arquivo ou DB

**Código exemplo:**
```cpp
class InMemoryCalculatorRepository : public ICalculatorRepository {
private:
    std::optional<double> lastResult;
    
public:
    void saveLastResult(double value) override {
        lastResult = value;
    }
    
    std::optional<double> getLastResult() const override {
        return lastResult;
    }
    
    void clearLastResult() override {
        lastResult = std::nullopt;
    }
};
```

**Princípios aplicados:**
- ✅ Adapter Pattern
- ✅ Facilmente substituível
- ✅ Isolado da lógica de negócio

---

### 5️⃣ **Presentation (Adaptadores)**
**Responsabilidade:** Interface com o usuário

#### `ConsolePresenter`
- Implementa `IPresenter`
- Exibe informações no console
- Formata resultados para exibição

#### `ConsoleInputHandler`
- Lê entrada do usuário
- Valida dados de entrada
- Converte strings para números

**Princípios aplicados:**
- ✅ Separation of Concerns
- ✅ Pode ser substituído por GUI futuramente
- ✅ Não contamina lógica de negócio

---

### 6️⃣ **Main (Composition Root)**
**Responsabilidade:** Injeção de dependências e inicialização

```cpp
int main() {
    // Dependency Injection
    InMemoryCalculatorRepository repository;
    ConsolePresenter presenter;
    ConsoleInputHandler inputHandler;
    
    // Use Cases com dependências injetadas
    ExecuteOperationUseCase executeOperation(&repository);
    GetLastResultUseCase getLastResult(&repository);
    
    // Loop principal da aplicação
    // ...
}
```

**Princípios aplicados:**
- ✅ Composition over Inheritance
- ✅ Dependency Injection manual
- ✅ Todas as dependências em um só lugar
- ✅ Facilita configuração e testes

---

## ✨ Princípios SOLID Aplicados

### **S**ingle Responsibility Principle
- Cada classe tem uma única responsabilidade
- `Operation` apenas representa operações
- `ExecuteOperationUseCase` apenas executa operações
- `ConsolePresenter` apenas apresenta dados

### **O**pen/Closed Principle
- Aberto para extensão através de interfaces
- Fechado para modificação (Use Cases não mudam)
- Novas operações podem ser adicionadas sem alterar código existente

### **L**iskov Substitution Principle
- Implementações de interfaces são substituíveis
- Pode trocar `InMemoryRepository` por `FileRepository` sem quebrar

### **I**nterface Segregation Principle
- Interfaces específicas e coesas
- `ICalculatorRepository` só tem métodos de persistência
- `IPresenter` só tem métodos de apresentação

### **D**ependency Inversion Principle
- Use Cases dependem de abstrações (interfaces)
- Não dependem de implementações concretas
- Permite inversão de controle

---

## 🎨 Princípios Clean Code Aplicados

### Nomes Descritivos
- ✅ `ExecuteOperationUseCase` - autoexplicativo
- ✅ `InMemoryCalculatorRepository` - descreve exatamente o que faz
- ✅ `CalculationResult` - claro e conciso

### Funções Pequenas e Focadas
- ✅ Cada método faz uma coisa só
- ✅ Fácil de entender e testar
- ✅ Baixa complexidade ciclomática

### Sem Duplicação (DRY)
- ✅ Lógica de cálculo centralizada
- ✅ Validações no domínio
- ✅ Formatação no presenter

### Comentários Significativos
- ✅ Documentação clara com Doxygen
- ✅ Explicação de decisões arquiteturais
- ✅ Código autoexplicativo

---

## 📦 Benefícios da Refatoração

### 1. **Manutenibilidade** 📝
- Código organizado em camadas lógicas
- Fácil localizar e corrigir bugs
- Mudanças isoladas em camadas específicas

### 2. **Testabilidade** 🧪
- Cada camada pode ser testada isoladamente
- Mocks fáceis através de interfaces
- Use Cases independentes de UI/DB

### 3. **Flexibilidade** 🔄
- Fácil adicionar novos tipos de operações
- Trocar console por GUI sem alterar Use Cases
- Substituir persistência em memória por arquivo/DB

### 4. **Escalabilidade** 📈
- Arquitetura suporta crescimento
- Novas funcionalidades seguem mesmo padrão
- Múltiplos desenvolvedores podem trabalhar em paralelo

### 5. **Reusabilidade** ♻️
- Use Cases podem ser reutilizados
- Interfaces facilitam adaptação
- Componentes desacoplados

---

## 🔧 Comparação: Antes vs Depois

| Aspecto | Antes | Depois |
|---------|-------|--------|
| **Arquitetura** | Monolítica | Clean Architecture |
| **Camadas** | 2 (UI + Lógica) | 5 (Domain, Use Cases, Interfaces, Infrastructure, Presentation) |
| **Acoplamento** | Alto | Baixo |
| **Testabilidade** | Difícil | Fácil |
| **Dependências** | Concretas | Abstratas (Interfaces) |
| **Extensibilidade** | Limitada | Alta |
| **Manutenibilidade** | Baixa | Alta |
| **Linhas de código** | ~250 | ~600 (mais organizado) |

---

## 📚 Padrões de Design Utilizados

### **Dependency Injection**
- Dependências injetadas via construtor
- Facilita testes e flexibilidade

### **Repository Pattern**
- Abstração para acesso a dados
- Isola persistência da lógica

### **Adapter Pattern**
- `ConsolePresenter` adapta lógica para console
- Pode ter `GUIPresenter` no futuro

### **Strategy Pattern**
- Diferentes tipos de operações
- Extensível para novas operações

### **Factory Method**
- `CalculationResult::Success()` e `Failure()`
- Criação controlada de objetos

---

## 🎯 Próximos Passos Possíveis

### Testes Unitários
```cpp
TEST(ExecuteOperationUseCase, AddTwoNumbers) {
    MockRepository repo;
    ExecuteOperationUseCase useCase(&repo);
    Operation op(OperationType::ADD, 2, 3);
    
    auto result = useCase.execute(op);
    
    ASSERT_TRUE(result.isSuccess());
    ASSERT_EQ(5, result.getValue());
}
```

### Novas Funcionalidades
- ✅ Histórico completo de operações
- ✅ Operações trigonométricas
- ✅ Constantes matemáticas (π, e)
- ✅ Modo RPN
- ✅ Interface gráfica (GUI)
- ✅ API REST

### Melhorias Técnicas
- ✅ Logging estruturado
- ✅ Configuração externa
- ✅ Internacionalização (i18n)
- ✅ Persistência em arquivo/banco
- ✅ Undo/Redo

---

## 📖 Referências

### Livros
- **Clean Architecture** - Robert C. Martin (Uncle Bob)
- **Clean Code** - Robert C. Martin
- **Domain-Driven Design** - Eric Evans
- **Design Patterns** - Gang of Four

### Artigos
- [The Clean Architecture](https://blog.cleancoder.com/uncle-bob/2012/08/13/the-clean-architecture.html)
- [SOLID Principles](https://en.wikipedia.org/wiki/SOLID)

### Princípios
- **SOLID** - 5 princípios de design OO
- **DRY** - Don't Repeat Yourself
- **KISS** - Keep It Simple, Stupid
- **YAGNI** - You Aren't Gonna Need It
- **Separation of Concerns** - Separação de responsabilidades

---

## ✅ Status da Implementação

- [x] ✅ Camada de Domain (Entities)
- [x] ✅ Camada de Use Cases
- [x] ✅ Interfaces (Ports)
- [x] ✅ Camada de Infrastructure
- [x] ✅ Camada de Presentation
- [x] ✅ Composition Root (main.cpp)
- [x] ✅ CMakeLists.txt atualizado
- [x] ✅ Compilação bem-sucedida
- [x] ✅ Documentação completa

---

**Versão:** 2.0.0  
**Data:** 22 de Outubro de 2025  
**Arquitetura:** Clean Architecture  
**Autor:** Lucas Terres (@lucterres)

---

⭐ **A refatoração está completa e o projeto segue as melhores práticas de Clean Architecture e SOLID!**
