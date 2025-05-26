#pragma once
#include <iostream>
#include "RentBikeControl.h"
// using namespace std; // 헤더 파일에서는 사용 자제

// 자전거 대여 인터페이스를 담당하는 boundary 클래스
class RentBikeUI {
private:
    RentBikeControl* control; // 자전거 대여 로직을 처리하는 control 객체

public:
    // 자전거 대여 UI 객체를 생성한다
    RentBikeUI(RentBikeControl* control);
    
    // 자전거 대여 프로세스를 시작한다
    void startRentBike(std::istream& in, std::ostream& out);
}; 