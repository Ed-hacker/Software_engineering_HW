#include "RentBikeUI.h"
#include "Bike.h" 
#include <iostream> 

// 새로운 자전거 대여 UI 객체를 생성한다
RentBikeUI::RentBikeUI(RentBikeControl* ctrl) : control(ctrl) {}

// 사용자로부터 대여할 자전거 정보를 입력받아 대여를 처리하고 결과를 출력 한다
void RentBikeUI::startRentBike(std::istream& in, std::ostream& out) {
    std::string bikeId;
    in >> bikeId;
    Bike* bikeAttempted = control->processBikeRental(bikeId);
    out << "4.1. 자전거 대여\n> ";
    if (bikeAttempted != nullptr && bikeAttempted->getRentedByUserId() != "") { // 성공적으로 대여되었는지 확인 (rentedByUserId가 설정되었는지)
        out << bikeAttempted->getId() << " " << bikeAttempted->getModel();
    } else if (bikeAttempted != nullptr && bikeAttempted->isRented()) { // 이미 다른 사람이 대여 중인 경우
        out << bikeId << " (이미 대여중)";
    } else { // 자전거가 없거나 대여에 실패한 경우
        out << bikeId << " (대여 실패)";
    }
    out << "\n";
} 