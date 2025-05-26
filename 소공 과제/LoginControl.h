#pragma once
#include "UserList.h"  
#include "User.h" 
#include <string>

// 로그인 기능을 제어하는 control 클래스
class LoginControl {
private:
    UserList* userList;         // 사용자 목록을 관리하는 객체
    User** currentLoginUserPtr; // main의 currentLoginUser를 가리키는 포인터

public:
    // 로그인 control 객체를 생성한다
    LoginControl(UserList* uList, User** currentUserPtr);
    
    // 사용자 로그인을 시도한다
    bool attemptLogin(const std::string& id, const std::string& pw);
}; 