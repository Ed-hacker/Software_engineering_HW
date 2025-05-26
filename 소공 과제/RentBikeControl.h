#pragma once
#include "BikeList.h"
#include "User.h"
#include "Bike.h"

// 자전거 대여 기능을 제어하는 control 클래스
class RentBikeControl {
private:
    BikeList* bikeList;         // 자전거 목록을 관리하는 객체
    User** currentLoginUserPtr; // main의 currentLoginUser를 가리키는 포인터

public:
    // 자전거 대여 control 객체를 생성한다
    RentBikeControl(BikeList* bList, User** currentUserPtr);
    
    // 자전거 대여 요청을 처리한다
    Bike* processBikeRental(const std::string& bikeId);
}; 