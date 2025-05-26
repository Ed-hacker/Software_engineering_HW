#pragma once
#include <iostream>
#include "LoginControl.h"

// 로그인 인터페이스를 담당하는 boundary 클래스
class LoginUI {
private:
    LoginControl* control; // 로그인 로직을 처리하는 control 객체

public:
    // 로그인 UI 객체를 생성한다
    LoginUI(LoginControl* ctrl);
    
    // 로그인 프로세스를 시작한다
    void loginUser(std::istream& in, std::ostream& out);
}; 