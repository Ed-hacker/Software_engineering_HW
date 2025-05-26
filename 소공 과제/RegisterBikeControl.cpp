#include "RegisterBikeControl.h"

// 새로운 자전거 등록 제어 객체를 생성한다
RegisterBikeControl::RegisterBikeControl(BikeList* bList) 
    : bikeList(bList) {}

// 새로운 자전거를 시스템에 등록한다
bool RegisterBikeControl::registerBike(const std::string& id, const std::string& model) {
    if (bikeList->findBikeById(id) != nullptr) {
        return false; // ID가 중복되면 등록 실패
    }
    Bike newBike(id, model);
    bikeList->addBike(newBike);
    return true;
} 