#pragma once
#include <iostream>
#include "LogoutControl.h"
#include "User.h"

// 로그아웃 인터페이스를 담당하는 boundary 클래스
class LogoutUI {
private:
    LogoutControl* logoutControl; // 로그아웃 로직을 처리하는 control 객체

public:
    // 로그아웃 UI 객체를 생성한다
    LogoutUI(LogoutControl* ctrl);
    
    // 로그아웃 프로세스를 시작한다
    void requestLogout(std::ostream& out, User* currentUser);
}; 