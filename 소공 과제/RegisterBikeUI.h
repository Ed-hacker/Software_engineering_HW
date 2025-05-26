#pragma once
#include <iostream>
#include "RegisterBikeControl.h"
#include "User.h"

// 자전거 등록 인터페이스를 담당하는 boundary 클래스
class RegisterBikeUI {
private:
    RegisterBikeControl* control; // 자전거 등록 로직을 처리하는 control 객체

public:
    // 자전거 등록 UI 객체를 생성한다
    RegisterBikeUI(RegisterBikeControl* ctrl);
    
    // 자전거 등록 프로세스를 시작한다
    void handleBikeRegistration(std::istream& in, std::ostream& out, User* currentUser);
}; 