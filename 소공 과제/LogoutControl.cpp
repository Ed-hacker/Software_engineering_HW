#include "LogoutControl.h"

// 새로운 로그아웃 제어 객체를 생성한다
LogoutControl::LogoutControl(User** currentUserPtr)
    : currentLoginUserPtr(currentUserPtr) {}

// 현재 로그인한 사용자를 로그아웃 처리한다
void LogoutControl::logout() {
    if (currentLoginUserPtr != nullptr && *currentLoginUserPtr != nullptr) {
        *currentLoginUserPtr = nullptr; // main의 현재 로그인 사용자 포인터를 nullptr로 설정한다
    }
} 