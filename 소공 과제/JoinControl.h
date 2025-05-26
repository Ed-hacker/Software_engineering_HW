#pragma once
#include "UserList.h" 
#include "User.h"
#include <string>

// 회원가입 관련 제어 로직을 담당하는 control 클래스
class JoinControl {
private:
    UserList* userList; // 사용자 목록을 관리하는 객체

public:
    // 새로운 회원가입 control 객체를 생성한다
    JoinControl(UserList* uList);
    // 새로운 사용자를 사용자 목록에 추가한다
    void addUser(const std::string& id, const std::string& pw, const std::string& phone);
}; 