#include "score_tennis.hpp"
std::expected<std::string, std::string> calcul_score(uint8_t player1Score, uint8_t player2Score)
{
    const static std::string scores[] =
    {
        "LOVE",
        "FIFTEEN",
        "THIRTY",
        "FORTY"
    };

    if (player1Score == player2Score)
        return (player1Score > 3) ? "DEUCE" : scores[player1Score] + "-ALL";

    if (player1Score >= 4 && player2Score >= 4
        && std::abs(player1Score - player2Score) > 2) {
        return std::unexpected("Impossible score!");
    }

    if (player1Score >= 4 && player2Score >= 4
        && std::abs(player1Score - player2Score) == 1) {
        std::string playerAhead = (player1Score > player2Score) ? "PLAYER1" : "PLAYER2";
        return "ADVANTAGE " + playerAhead;
    }

    return scores[player1Score] + '-' + scores[player2Score];
}
