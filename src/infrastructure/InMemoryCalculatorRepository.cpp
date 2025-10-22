#include "infrastructure/InMemoryCalculatorRepository.h"

InMemoryCalculatorRepository::InMemoryCalculatorRepository()
    : lastResult(std::nullopt) {}

void InMemoryCalculatorRepository::saveLastResult(double result) {
    lastResult = result;
}

std::optional<double> InMemoryCalculatorRepository::getLastResult() const {
    return lastResult;
}

void InMemoryCalculatorRepository::clearLastResult() {
    lastResult = std::nullopt;
}
