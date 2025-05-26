#include "RegisterBikeUI.h"
#include <string>

// 새로운 자전거 등록 UI 객체를 생성한다
RegisterBikeUI::RegisterBikeUI(RegisterBikeControl* ctrl) 
    : control(ctrl) {}

// 사용자로부터 자전거 정보를 입력받아 등록을 처리하고 결과를 출력 한다
void RegisterBikeUI::handleBikeRegistration(std::istream& in, std::ostream& out, User* currentUser) {
    if (currentUser == nullptr || currentUser->getType() != UserType::ADMIN) {
        out << "3.1. 자전거 등록\n";
        out << "> 권한이 없습니다.\n";
        std::string tempId, tempModel; // 다음 입력을 위해 소비
        in >> tempId >> tempModel;
        return;
    }

    std::string id, model;
    in >> id >> model;
    bool success = control->registerBike(id, model);
    out << "3.1. 자전거 등록\n";
    if (success) {
        out << "> " << id << " " << model << "\n";
    } else {
        out << ">등록 실패(이미 존재하는 ID)\n";
    }
} 