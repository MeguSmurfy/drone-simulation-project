#include "PercentageDecorator.h"

PercentageDecorator::PercentageDecorator(IObserver* observer): 
    IPercentageDecorator(observer), quarter(false), half(false), threeQuarters(false) {}

std::string PercentageDecorator::DisplayPercentageThreshold(double dt) {
    if (observer->GetType() != "Drone" && observer->GetType() != "Package") {
        return "";
    }
    if (observer->GetProgress() < 0.05) {
        quarter = false;
        half = false;
        threeQuarters = false;
    }
    if (observer->GetProgress() > 0.25 && !quarter) {
        quarter = true;
        return observer->GetType() + "'s delivery progress: 25%.\n";
    }
    if (observer->GetProgress() > 0.5 && !half) {
        half = true;
        return observer->GetType() + "'s delivery progress: 50%.\n";
    }
    if (observer->GetProgress() > 0.75 && !threeQuarters) {
        threeQuarters = true;
        return observer->GetType() + "'s delivery progress: 75%.\n";
    }
    return "";
}