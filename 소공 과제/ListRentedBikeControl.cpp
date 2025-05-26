#include "ListRentedBikeControl.h"

// 새로운 자전거 대여 목록 조회 제어 객체를 생성한다
ListRentedBikeControl::ListRentedBikeControl(User** currentUserPtr) 
    : currentLoginUserPtr(currentUserPtr) {}

// 현재 로그인한 사용자가 대여 중인 자전거 목록을 반환한다
const std::vector<Bike*>& ListRentedBikeControl::getUserRentedBikes() {
    User* actualCurrentUser = (currentLoginUserPtr != nullptr) ? *currentLoginUserPtr : nullptr;
    if (actualCurrentUser) {
        return actualCurrentUser->getRentedBikes();
    }
    // 사용자가 없거나 대여한 자전거가 없는 경우 빈 벡터 반환
    static const std::vector<Bike*> emptyRentedBikes;
    return emptyRentedBikes;
}

