#pragma once

#include <string>
#include <expected>

std::expected<std::string, std::string> calcul_score(uint8_t player1Score, uint8_t player2Score);
