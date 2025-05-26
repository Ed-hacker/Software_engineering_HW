#include "ListRentedBikeUI.h"
#include "Bike.h" 
#include <iostream> 
#include <vector>   
#include <algorithm> 
#include <string>    

// 새로운 자전거 대여 목록 조회 UI 객체를 생성한다
ListRentedBikeUI::ListRentedBikeUI(ListRentedBikeControl* ctrl) : control(ctrl) {}

// 현재 사용자가 대여한 자전거 목록을 조회하고 결과를 출력 한다
void ListRentedBikeUI::showRentedBikes(std::ostream& out) {
    out << "5.1. 자전거 대여 리스트\n";
    const std::vector<Bike*>& rentedBikes = control->getUserRentedBikes();

    std::vector<Bike*> sortedBikes = rentedBikes; // 정렬을 위해 복사본 생성
    std::sort(sortedBikes.begin(), sortedBikes.end(), [](const Bike* a, const Bike* b) {
        // nullptr 체크 추가 (안정성)
        if (!a && !b) return false;
        if (!a) return true; // nullptr이 뒤로 가도록 (혹은 false로 하여 앞으로)
        if (!b) return false;
        return a->getId() < b->getId();
    });

    if (sortedBikes.empty()) {
        out << "> 대여한 자전거가 없습니다.\n"; 
    } else {
        for (const Bike* bike : sortedBikes) {
            if (bike) { // 정렬 후에도 nullptr 체크는 유효
                out << "> " << bike->getId() << " " << bike->getModel() << "\n";
            }
        }
    }
} 