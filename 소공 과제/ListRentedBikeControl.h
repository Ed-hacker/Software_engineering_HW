#pragma once
#include "User.h"
#include <vector>
#include <string>

// 현재 사용자가 대여한 자전거 목록 조회 관련 제어 로직을 담당하는 control 클래스
class ListRentedBikeControl {
private:
    User** currentLoginUserPtr; // main의 currentLoginUser를 가리키는 포인터

public:
    // 새로운 자전거 대여 목록 조회 control 객체를 생성한다
    ListRentedBikeControl(User** currentUserPtr);
    // 현재 로그인한 사용자가 대여 중인 자전거 목록을 반환한다
    const std::vector<Bike*>& getUserRentedBikes();
}; 