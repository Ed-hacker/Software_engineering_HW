#include "LoginControl.h"

// 새로운 로그인 제어 객체를 생성한다
LoginControl::LoginControl(UserList* uList, User** currentUserPtr)
    : userList(uList), currentLoginUserPtr(currentUserPtr) {}

// 사용자 로그인을 시도하고 성공 시 현재 로그인 사용자 정보를 업데 이트한다
bool LoginControl::attemptLogin(const std::string& id, const std::string& pw) {
    User* user = userList->findUserById(id);
    if (user != nullptr && user->getPassword() == pw) {
        if (currentLoginUserPtr != nullptr) {
            *currentLoginUserPtr = user; // 로그인 성공 시 main의 포인터 업데이트
            return true;
        }
    }
    if (currentLoginUserPtr != nullptr) {
        *currentLoginUserPtr = nullptr; // 로그인 실패 시 main의 포인터 초기화
    }
    return false;
} 