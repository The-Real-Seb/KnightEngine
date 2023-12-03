#include "BDDManager.h"
#include <cpr/cpr.h>
#include <iostream>
#include <json/json.h>
#include <iostream>

void KE::BDDManager::SendDataToBDD(float score)
{
    Json::Value newScore;
    newScore["name"] = "playerName";
    newScore["score"] = score;

    std::string url = "https://testknightengine-18cce-default-rtdb.europe-west1.firebasedatabase.app/scores.json";
    auto response = cpr::Post(cpr::Url{ url }, cpr::Body{ newScore.toStyledString() },
        cpr::Header{ {"Content-Type", "application/json"} });

    if (response.status_code == cpr::status::HTTP_OK) {
        std::cout << "Score submitted successfully!" << std::endl;
    }
    else {
        std::cout << "Failed to submit score." << std::endl;
    }
}

void KE::BDDManager::GetDataFromBDD()
{
    std::string url = "https://testknightengine-18cce-default-rtdb.europe-west1.firebasedatabase.app/scores.json?orderBy=\"score\"&limitToLast=10";
    auto response = cpr::Get(cpr::Url{ url });

    if (response.status_code == cpr::status::HTTP_OK) {
        Json::Value scores;
        std::istringstream(response.text) >> scores;

        // Création d'un vecteur pour stocker et inverser les scores
        std::vector<Json::Value> scoreList;

        for (Json::Value::const_iterator it = scores.begin(); it != scores.end(); ++it) {
            scoreList.push_back(*it);
        }

        // Inverser l'ordre des scores pour obtenir un ordre décroissant
        std::reverse(scoreList.begin(), scoreList.end());
                
        //return scoreList[0].asString();
    }
    else {
        std::cout << "Failed to retrieve scores. HTTP Status Code: " << response.status_code << std::endl; 
        //return "";
    }
}
