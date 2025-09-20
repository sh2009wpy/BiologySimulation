#include "Mitochondrion.h"
#include <algorithm>

Mitochondrion::Mitochondrion() {}

// 丙酮酸氧化
void Mitochondrion::pyruvateOxidation(double &pyruvate, double &nadh, double &acetylCoA) {
    double pyruvate_used = std::min(pyruvate, 2.0);
    pyruvate -= pyruvate_used;
    acetylCoA += pyruvate_used; // 生成Acetyl-CoA
    nadh += pyruvate_used;      // 每个丙酮酸产生1 NADH
}

// 三羧酸循环
double Mitochondrion::citricAcidCycle(double &acetylCoA, double &nadh, double &fadh2) {
    double acetyl_used = std::min(acetylCoA, 1.0);
    acetylCoA -= acetyl_used;
    nadh += 3 * acetyl_used;
    fadh2 += 1 * acetyl_used;
    double atp = 1 * acetyl_used; // 每个Acetyl-CoA直接生成1 ATP
    return atp;
}

// 电子传递链
double Mitochondrion::electronTransportChain(double &nadh, double &fadh2, double &oxygen) {
    double nadh_usable = std::min(nadh, 2 * oxygen);   // 0.5 O2/NADH
    double fadh2_usable = std::min(fadh2, 4 * oxygen); // 0.25 O2/FADH2
    double atp = 2.5 * nadh_usable + 1.5 * fadh2_usable;
    oxygen -= nadh_usable * 0.5 + fadh2_usable * 0.25;
    nadh -= nadh_usable;
    fadh2 -= fadh2_usable;
    return atp;
}
