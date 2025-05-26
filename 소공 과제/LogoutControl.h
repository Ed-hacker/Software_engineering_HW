#pragma once
#include "User.h"

// 로그아웃 관련 제어 로직을 담당하는 control 클래스
class LogoutControl {
private:
    User** currentLoginUserPtr; // main의 currentLoginUser를 가리키는 포인터

public:
    // 새로운 로그아웃 control 객체를 생성한다
    LogoutControl(User** currentUserPtr);
    // 현재 로그인한 사용자를 로그아웃 처리한다
    void logout();
}; 