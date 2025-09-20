#include "Cell.h"
#include <iostream>
#include <algorithm>

Cell::Cell(double init_sugar, double init_oxygen, double init_atp)
    : sugar(init_sugar), oxygen(init_oxygen), atp(init_atp),
      pyruvate(0.0), acetylCoA(0.0), nadh(0.0), fadh2(0.0) {}

// 糖酵解（细胞质）
void Cell::glycolysis() {
    double glucose_used = std::min(sugar, 1.0);
    sugar -= glucose_used;
    pyruvate += 2 * glucose_used;
    nadh += 2 * glucose_used;
    double atp_gly = 2 * glucose_used;
    atp += atp_gly;
    std::cout << "Glycolysis: ATP +" << atp_gly 
              << ", pyruvate=" << pyruvate << ", NADH=" << nadh << std::endl;
}

// 线粒体代谢
void Cell::mitochondrialRespiration() {
    mito.pyruvateOxidation(pyruvate, nadh, acetylCoA);
    std::cout << "Pyruvate Oxidation: acetylCoA=" << acetylCoA << ", NADH=" << nadh << std::endl;

    double atp_tca = mito.citricAcidCycle(acetylCoA, nadh, fadh2);
    atp += atp_tca;
    std::cout << "TCA Cycle: ATP +" << atp_tca 
              << ", NADH=" << nadh << ", FADH2=" << fadh2 << std::endl;

    double atp_et = mito.electronTransportChain(nadh, fadh2, oxygen);
    atp += atp_et;
    std::cout << "Electron Transport Chain: ATP +" << atp_et 
              << ", remaining NADH=" << nadh << ", FADH2=" << fadh2 
              << ", O2=" << oxygen << std::endl;
}

// 完整代谢流程
void Cell::metabolize() {
    glycolysis();
    mitochondrialRespiration();
    std::cout << "Total ATP after step: " << atp << std::endl << std::endl;
}
