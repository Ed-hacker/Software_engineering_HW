#pragma once
#include <iostream>
#include "ListRentedBikeControl.h"
// using namespace std; // 헤더 파일에서는 사용 자제

// 자전거 대여 목록 조회 인터페이스를 담당하는 boundary 클래스
class ListRentedBikeUI {
private:
    ListRentedBikeControl* control; // 자전거 대여 목록 조회 로직을 처리하는 control 객체

public:
    // 자전거 대여 목록 조회 UI 객체를 생성한다
    ListRentedBikeUI(ListRentedBikeControl* control);
    
    // 자전거 대여 목록 조회 프로세스를 시작한다
    void showRentedBikes(std::ostream& out);
}; 