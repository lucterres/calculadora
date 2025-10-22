#include "domain/CalculationResult.h"
#include <stdexcept>

CalculationResult::CalculationResult(bool success, std::optional<double> value, const std::string& error)
    : value(value), errorMessage(error), success(success) {}

CalculationResult CalculationResult::Success(double value) {
    return CalculationResult(true, value, "");
}

CalculationResult CalculationResult::Failure(const std::string& errorMessage) {
    return CalculationResult(false, std::nullopt, errorMessage);
}

bool CalculationResult::isSuccess() const {
    return success;
}

double CalculationResult::getValue() const {
    if (!success || !value.has_value()) {
        throw std::runtime_error("Tentativa de acessar valor de resultado com falha");
    }
    return value.value();
}

std::string CalculationResult::getErrorMessage() const {
    return errorMessage;
}
