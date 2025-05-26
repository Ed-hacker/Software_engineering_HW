#include "RentBikeControl.h"

// 새로운 자전거 대여 제어 객체를 생성한다
RentBikeControl::RentBikeControl(BikeList* bList, User** currentUserPtr) 
    : bikeList(bList), currentLoginUserPtr(currentUserPtr) {}

// 특정 ID의 자전거 대여 요청을 처리하고, 성공 시 해당 자전거 포인터를 반환한다
Bike* RentBikeControl::processBikeRental(const std::string& bikeId) {
    User* actualCurrentUser = (currentLoginUserPtr != nullptr) ? *currentLoginUserPtr : nullptr;
    Bike* bike = bikeList->findBikeById(bikeId);

    if (actualCurrentUser && bike && !bike->isRented()) {
        if (actualCurrentUser->rentBike(bike)) {
            return bike; // 대여 성공
        }
    }
    // 대여에 실패했거나, 자전거가 없거나, 이미 대여 중인 경우 해당 자전거 객체(상태 포함) 또는 nullptr 반환
    return bike; 
} 