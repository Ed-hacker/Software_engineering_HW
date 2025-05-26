#pragma once
#include "BikeList.h"
#include "Bike.h"

// 자전거 등록 기능을 제어하는 control 클래스
class RegisterBikeControl {
private:
    BikeList* bikeList; // 자전거 목록을 관리하는 객체

public:
    // 자전거 등록 control 객체를 생성한다
    RegisterBikeControl(BikeList* bList);
    
    // 새로운 자전거를 시스템에 등록한다
    bool registerBike(const std::string& id, const std::string& model);
}; 